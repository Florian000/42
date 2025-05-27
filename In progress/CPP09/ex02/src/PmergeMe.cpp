#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe() : _timeVectorMicroseconds(0.0), _timeDequeMicroseconds(0.0) {}

PmergeMe::PmergeMe(const PmergeMe& src) 
{
    *this = src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) 
{
    if (this != &rhs)
    {
        _initialSequence = rhs._initialSequence;
        _sortedVector = rhs._sortedVector;
        _timeVectorMicroseconds = rhs._timeVectorMicroseconds;
        _sortedDeque = rhs._sortedDeque;
        _timeDequeMicroseconds = rhs._timeDequeMicroseconds;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::processInputAndSort(int argc, char **argv)
{
    try 
    {
        parseValidateInput(argc, argv);
        applySortAndMeasureVector();
        applySortAndMeasureDeque();

    }
    catch (const std::exception& e)
    {
        throw;
    }
}

void PmergeMe::displayResults() const
{
    printSequence(_initialSequence, "Before:");
    printSequence(_sortedVector, "After: ");

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << _initialSequence.size()
              << " elements with std::vector : " << _timeVectorMicroseconds << " us" << std::endl;
    std::cout << "Time to process a range of " << _initialSequence.size()
              << " elements with std::deque  : " << _timeDequeMicroseconds << " us" << std::endl;
}

void PmergeMe::parseValidateInput(int argc, char **argv)
{
    _initialSequence.clear();

    for (int i = 1; i < argc; ++i)
    {
        std::string argStr = argv[i];

        if (argStr.empty())
             throw std::runtime_error("Empty argument provided.");
        
        char* endptr = NULL;
        errno = 0;
        long val = std::strtol(argStr.c_str(), &endptr, 10);

        if (*endptr != '\0')
            throw std::runtime_error("Invalid character in input: '" + std::string(argv[i]) + "'");
        if (errno == ERANGE || val > INT_MAX || val < 0)
            throw std::runtime_error("Input value out of range or not positive: '" + std::string(argv[i]) + "'");
        if (val == 0)
            throw std::runtime_error("Non-positive integer encountered (zero): '" + std::string(argv[i]) + "'");
        _initialSequence.push_back(static_cast<int>(val));
    }
    if (_initialSequence.empty() && argc > 1)
         throw std::runtime_error("No valid positive integers found in input.");
}

template <typename Container>
void PmergeMe::printSequence(const Container& c, const std::string& prefix) const 
{
    std::cout << prefix;
    for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it)
        std::cout << " " << *it;
    std::cout << std::endl;
}

std::vector<size_t> PmergeMe::generateJacobsthalInsertionIndices(size_t numPendElements)
{
    if (numPendElements == 0) return std::vector<size_t>();

    std::vector<long> jacobsthal_numbers;
    jacobsthal_numbers.push_back(0);
    jacobsthal_numbers.push_back(1);
    jacobsthal_numbers.push_back(1);

    for (size_t k = 3; ; ++k)
    {
        long next_jac = jacobsthal_numbers[k-1] + 2 * jacobsthal_numbers[k-2];
        jacobsthal_numbers.push_back(next_jac);
        if (static_cast<size_t>(next_jac) >= numPendElements) break;
        if (k > numPendElements + 5) break; 
    }

    std::vector<size_t> insertion_indices;
    std::vector<bool> inserted(numPendElements, false);
    
    long prev_jac_val = 1; 

    for (size_t k_idx = 2; k_idx < jacobsthal_numbers.size(); ++k_idx)
    { 
        long current_jac_val = jacobsthal_numbers[k_idx]; 

        for (long idx_to_insert = std::min(static_cast<long>(numPendElements), current_jac_val) - 1; idx_to_insert >= prev_jac_val; --idx_to_insert)
        {
            if (static_cast<size_t>(idx_to_insert) < numPendElements && !inserted[idx_to_insert])
            {
                insertion_indices.push_back(static_cast<size_t>(idx_to_insert));
                inserted[static_cast<size_t>(idx_to_insert)] = true;
            }
        }
        if (insertion_indices.size() == numPendElements) break; 
        prev_jac_val = current_jac_val;
    }
    for(size_t i = 0; i < numPendElements; ++i)
        if(!inserted[i]) insertion_indices.push_back(i);
    return insertion_indices;
}

// --- Ford-Johnson for std::vector ---
void PmergeMe::applySortAndMeasureVector()
{
    _sortedVector = _initialSequence;

    clock_t start_time = clock();
    fordJohnsonSort(_sortedVector);
    clock_t end_time = clock();
    
    _timeVectorMicroseconds = static_cast<double>(end_time - start_time) * 1000000.0 / CLOCKS_PER_SEC;
}

void PmergeMe::binaryInsert(std::vector<int>& mainChain, int value, std::vector<int>::iterator searchEndIt)
{
    std::vector<int>::iterator insertPos = std::lower_bound(mainChain.begin(), searchEndIt, value);
    mainChain.insert(insertPos, value);
}

void PmergeMe::fordJohnsonSort(std::vector<int>& container)
{
    size_t n = container.size();
    if (n <= 1) return;

    int straggler_val = 0;
    bool has_straggler = (n % 2 != 0);
    if (has_straggler)
    {
        straggler_val = container.back();
        container.pop_back();
        n--; 
    }

    std::vector<ElementPair> pairs;
    for (size_t i = 0; i < n; i += 2)
    {
        ElementPair p;
        if (container[i] >= container[i+1])
        {
            p.major = container[i]; p.minor = container[i+1];
        }
        else
        {
            p.major = container[i+1]; p.minor = container[i];
        }
        pairs.push_back(p);
    }

    std::vector<int> majors;
    for (size_t i = 0; i < pairs.size(); ++i)
        majors.push_back(pairs[i].major);
    
    fordJohnsonSort(majors);

    std::vector<ElementPair> sorted_pairs;
    std::vector<bool> used_pairs(pairs.size(), false);

    for (size_t i = 0; i < majors.size(); ++i)
    {
        int current_major = majors[i];
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (!used_pairs[j] && pairs[j].major == current_major)
            {
                ElementPair sp;
                sp.major = pairs[j].major; sp.minor = pairs[j].minor;
                sorted_pairs.push_back(sp);
                used_pairs[j] = true;
                break;
            }
        }
    }
    
    std::vector<int> S;
    std::vector<std::pair<int, int> > pend; 

    if (!sorted_pairs.empty())
    {
        S.push_back(sorted_pairs[0].minor); 
        for (size_t i = 0; i < sorted_pairs.size(); ++i)
        {
            S.push_back(sorted_pairs[i].major); 
            if (i > 0) pend.push_back(std::make_pair(sorted_pairs[i].minor, sorted_pairs[i].major));
        }
    }

    if (has_straggler) pend.push_back(std::make_pair(straggler_val, -1));

    std::vector<size_t> insertion_indices = generateJacobsthalInsertionIndices(pend.size());

    for (size_t i = 0; i < insertion_indices.size(); ++i)
    {
        size_t pend_idx = insertion_indices[i];
        int value_to_insert = pend[pend_idx].first;
        int major_partner_val = pend[pend_idx].second;

        std::vector<int>::iterator search_limit_it;
        if (major_partner_val != -1) 
        {
            std::vector<int>::iterator majors_start_in_S = S.begin();
            if (!S.empty()) majors_start_in_S++;
            search_limit_it = std::lower_bound(majors_start_in_S, S.end(), major_partner_val);
        } 
        else
        {
            search_limit_it = S.end();
        }
        binaryInsert(S, value_to_insert, search_limit_it);
    }
    container = S;
}

void PmergeMe::applySortAndMeasureDeque()
{
    _sortedDeque.assign(_initialSequence.begin(), _initialSequence.end());

    clock_t start_time = clock();
    fordJohnsonSort(_sortedDeque);
    clock_t end_time = clock();

    _timeDequeMicroseconds = static_cast<double>(end_time - start_time) * 1000000.0 / CLOCKS_PER_SEC;
}

void PmergeMe::binaryInsert(std::deque<int>& mainChain, int value, std::deque<int>::iterator searchEndIt)
{
    std::deque<int>::iterator insertPos = std::lower_bound(mainChain.begin(), searchEndIt, value);
    mainChain.insert(insertPos, value);
}

void PmergeMe::fordJohnsonSort(std::deque<int>& container)
{
    size_t n = container.size();
    if (n <= 1) return;

    int straggler_val = 0;
    bool has_straggler = (n % 2 != 0);
    if (has_straggler) 
    {
        straggler_val = container.back();
        container.pop_back();
        n--;
    }

    std::vector<ElementPair> pairs;
    for (size_t i = 0; i < n; i += 2)
    {
        ElementPair p;
        if (container[i] >= container[i+1])
        {
            p.major = container[i]; p.minor = container[i+1];
        } 
        else 
        {
            p.major = container[i+1]; p.minor = container[i];
        }
        pairs.push_back(p);
    }

    std::deque<int> majors; 
    for (size_t i = 0; i < pairs.size(); ++i) 
        majors.push_back(pairs[i].major);
    
    fordJohnsonSort(majors);

    std::vector<ElementPair> sorted_pairs;
    std::vector<bool> used_pairs(pairs.size(), false);

    for (size_t i = 0; i < majors.size(); ++i)
    {
        int current_major = majors[i];
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (!used_pairs[j] && pairs[j].major == current_major)
            {
                 ElementPair sp;
                 sp.major = pairs[j].major; sp.minor = pairs[j].minor;
                 sorted_pairs.push_back(sp);
                 used_pairs[j] = true;
                 break;
            }
        }
    }
    
    std::deque<int> S; 
    std::vector<std::pair<int, int> > pend;

    if (!sorted_pairs.empty())
    {
        S.push_back(sorted_pairs[0].minor);
        for (size_t i = 0; i < sorted_pairs.size(); ++i)
        {
            S.push_back(sorted_pairs[i].major);
            if (i > 0) pend.push_back(std::make_pair(sorted_pairs[i].minor, sorted_pairs[i].major));
        }
    }

    if (has_straggler) pend.push_back(std::make_pair(straggler_val, -1)); 

    std::vector<size_t> insertion_indices = generateJacobsthalInsertionIndices(pend.size());

    for (size_t i = 0; i < insertion_indices.size(); ++i)
    {
        size_t pend_idx = insertion_indices[i];
        int value_to_insert = pend[pend_idx].first;
        int major_partner_val = pend[pend_idx].second;

        std::deque<int>::iterator search_limit_it;
        if (major_partner_val != -1)
        {
            std::deque<int>::iterator majors_start_in_S = S.begin();
            if(!S.empty()) majors_start_in_S++;
            search_limit_it = std::lower_bound(majors_start_in_S, S.end(), major_partner_val);
        }
        else
        {
            search_limit_it = S.end();
        }
        binaryInsert(S, value_to_insert, search_limit_it);
    }
    container = S;
}