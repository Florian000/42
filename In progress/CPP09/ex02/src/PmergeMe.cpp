#include "PmergeMe.hpp"

// --- Canonical Form ---
PmergeMe::PmergeMe() : _parseError(false), _timeVectorMicroseconds(0.0), _timeDequeMicroseconds(0.0) {}

PmergeMe::PmergeMe(const PmergeMe& src) {
    *this = src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) {
    if (this != &rhs) {
        _initialSequence = rhs._initialSequence;
        _parseError = rhs._parseError;
        _sortedVector = rhs._sortedVector;
        _timeVectorMicroseconds = rhs._timeVectorMicroseconds;
        _sortedDeque = rhs._sortedDeque;
        _timeDequeMicroseconds = rhs._timeDequeMicroseconds;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

// --- Public Methods ---
void PmergeMe::processInput(int argc, char **argv) {
    try {
        parseValidateInput(argc, argv);
        if (_parseError) { // parseValidateInput now throws, so this might be redundant
            throw std::runtime_error("Input parsing failed.");
        }
        if (_initialSequence.empty() && argc > 1) { // Check if parsing resulted in empty sequence but there were args
             throw std::runtime_error("No valid positive integers found in input.");
        }


        applySortAndMeasureVector();
        applySortAndMeasureDeque();

    } catch (const std::exception& e) {
        _parseError = true; // Mark error for displayResults or rethrow
        throw; // Rethrow for main to catch and print "Error"
    }
}

void PmergeMe::displayResults() const {
    if (_parseError) {
        // Error already printed by main or not applicable if no valid input
        return;
    }
    if (_initialSequence.empty() && _timeVectorMicroseconds == 0.0 && _timeDequeMicroseconds == 0.0) {
        // Handles case like "./PmergeMe" with no args if main let it pass, or if all args were invalid.
        // However, main should catch argc < 2. This is more for "no valid numbers found".
        // If parseValidateInput throws on no valid numbers, this path might not be hit for results.
        std::cout << "Before: " << std::endl;
        std::cout << "After:  " << std::endl;

    } else {
        printSequence(_initialSequence, "Before:");
        // Assuming vector sort is always done if input is valid
        printSequence(_sortedVector, "After: ");
    }

    std::cout << std::fixed << std::setprecision(5); // Ensure consistent float output
    std::cout << "Time to process a range of " << _initialSequence.size()
              << " elements with std::vector : " << _timeVectorMicroseconds << " us" << std::endl;
    std::cout << "Time to process a range of " << _initialSequence.size()
              << " elements with std::deque  : " << _timeDequeMicroseconds << " us" << std::endl;
}


// --- Input Parsing ---
void PmergeMe::parseValidateInput(int argc, char **argv) {
    _initialSequence.clear();
    _parseError = false;

    for (int i = 1; i < argc; ++i) {
        std::string argStr = argv[i];
        if (argStr.empty()) {
             throw std::runtime_error("Empty argument provided.");
        }
        
        char* endptr;
        long val = std::strtol(argStr.c_str(), &endptr, 10);

        // Check for conversion errors
        if (*endptr != '\0') { // Not entire string was consumed
            throw std::runtime_error("Invalid character in input: '" + std::string(argv[i]) + "'");
        }
        if (errno == ERANGE || val > INT_MAX || val < INT_MIN) { // Out of range for long or int
            throw std::out_of_range("Input value out of range: '" + std::string(argv[i]) + "'");
        }
        if (val <= 0) { // Not a positive integer
            throw std::runtime_error("Non-positive integer encountered: '" + std::string(argv[i]) + "'");
        }
        _initialSequence.push_back(static_cast<int>(val));
    }
    if (_initialSequence.empty() && argc > 1) { // If args were given but none were valid
         throw std::runtime_error("No valid positive integers to sort.");
    }
}

// --- Common Utilities ---
template <typename Container>
void PmergeMe::printSequence(const Container& c, const std::string& prefix) const {
    std::cout << prefix;
    for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it) {
        std::cout << " " << *it;
    }
    std::cout << std::endl;
}


// Generates the 0-based indices for inserting pend elements in Jacobsthal order.
std::vector<size_t> PmergeMe::generateJacobsthalInsertionIndices(size_t numPendElements) {
    if (numPendElements == 0) return std::vector<size_t>();

    std::vector<long long> jacobsthal_numbers; // Actual J_k values (0, 1, 1, 3, 5, ...)
    jacobsthal_numbers.push_back(0); // J_0
    jacobsthal_numbers.push_back(1); // J_1
    if (numPendElements > 0) { // Ensure J_2 = 1 is added if needed for indexing later
         jacobsthal_numbers.push_back(1); // J_2
    }


    for (size_t k = 3; ; ++k) {
        long long next_jac = jacobsthal_numbers[k-1] + 2 * jacobsthal_numbers[k-2];
        jacobsthal_numbers.push_back(next_jac);
        if (static_cast<size_t>(next_jac) >= numPendElements) { // Stop when J_k covers all pend elements
            break;
        }
        if (k > numPendElements + 3) break; // Safety break, should not be hit
    }

    std::vector<size_t> insertion_indices;
    std::vector<bool> inserted(numPendElements, false);
    
    size_t prev_jac_val = 1; // Corresponds to J_2 (index 1 in pend is B_J(2))

    for (size_t k = 2; k < jacobsthal_numbers.size(); ++k) { // Start from J_2
        long long current_jac_val = jacobsthal_numbers[k]; // This is J_k (e.g., J_2=1, J_3=3, J_4=5)
                                                        // It refers to the k-th element in the conceptual list B

        // Iterate downwards from current_jac_val-1 down to prev_jac_val (0-indexed into pend)
        for (long long idx = std::min((long long)numPendElements, current_jac_val) -1; idx >= (long long)prev_jac_val; --idx) {
            if (static_cast<size_t>(idx) < numPendElements && !inserted[idx]) {
                insertion_indices.push_back(idx);
                inserted[idx] = true;
            }
        }
        if (static_cast<size_t>(current_jac_val) >= numPendElements) break; // All covered
        prev_jac_val = current_jac_val;
    }
    // Ensure any remaining elements are added (should be covered by loop logic)
    for(size_t i = 0; i < numPendElements; ++i) {
        if(!inserted[i]) insertion_indices.push_back(i);
    }
    return insertion_indices;
}


// --- Ford-Johnson Generic Binary Insert Helper ---
// Used by specific vector/deque binaryInsert if logic is identical for RandomAccessIterators
template <typename Container, typename Iterator>
void PmergeMe::generalBinaryInsert(Container& mainChain, int value, Iterator searchEndIt) {
    Iterator insertPos = std::lower_bound(mainChain.begin(), searchEndIt, value);
    mainChain.insert(insertPos, value);
}

// --- Ford-Johnson for std::vector ---
void PmergeMe::applySortAndMeasureVector() {
    if (_parseError || _initialSequence.empty() && _timeVectorMicroseconds != 0.0) { // If already processed or error
         if(!_initialSequence.empty()) _sortedVector = _initialSequence; // reset if needed for re-display
         else _sortedVector.clear();
    }
    _sortedVector = _initialSequence; // Copy data to sort

    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    fordJohnsonSort(_sortedVector);
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double, std::micro> duration = end - start;
    _timeVectorMicroseconds = duration.count();
}

void PmergeMe::binaryInsert(std::vector<int>& mainChain, int value, typename std::vector<int>::iterator searchEndIt) {
    generalBinaryInsert(mainChain, value, searchEndIt);
}


void PmergeMe::fordJohnsonSort(std::vector<int>& container) {
    size_t n = container.size();
    if (n <= 1) return;

    int straggler_val = -1;
    bool has_straggler = (n % 2 != 0);
    if (has_straggler) {
        straggler_val = container.back();
        container.pop_back();
        n--; 
    }

    std::vector<ElementPair> pairs;
    for (size_t i = 0; i < n; i += 2) {
        if (container[i] >= container[i+1])
            pairs.push_back({container[i], container[i+1]});
        else
            pairs.push_back({container[i+1], container[i]});
    }

    if (pairs.empty()) {
        if (has_straggler) container.push_back(straggler_val); // Original size 1
        return;
    }

    std::vector<int> majors;
    for (size_t i = 0; i < pairs.size(); ++i) majors.push_back(pairs[i].major);
    
    fordJohnsonSort(majors); // Recursive call

    std::vector<ElementPair> sorted_pairs;
    std::multimap<int, int> major_to_minor_map;
    for (size_t i = 0; i < pairs.size(); ++i) {
        major_to_minor_map.insert(std::make_pair(pairs[i].major, pairs[i].minor));
    }
    for (size_t i = 0; i < majors.size(); ++i) {
        std::multimap<int, int>::iterator it = major_to_minor_map.find(majors[i]);
        sorted_pairs.push_back({majors[i], it->second});
        major_to_minor_map.erase(it);
    }
    
    std::vector<int> S; // Main chain
    std::vector<std::pair<int, int> > pend; // {value_to_insert, its_major_partner_value}

    if (!sorted_pairs.empty()) {
        S.push_back(sorted_pairs[0].minor); // Insert b1
        for (size_t i = 0; i < sorted_pairs.size(); ++i) {
            S.push_back(sorted_pairs[i].major); // Insert a_i
            if (i > 0) { // b2 onwards for pend
                pend.push_back(std::make_pair(sorted_pairs[i].minor, sorted_pairs[i].major));
            }
        }
    }

    if (has_straggler) {
        pend.push_back(std::make_pair(straggler_val, -1)); // -1 indicates straggler, search full S
    }

    std::vector<size_t> insertion_indices = generateJacobsthalInsertionIndices(pend.size());

    for (size_t i = 0; i < insertion_indices.size(); ++i) {
        size_t pend_idx = insertion_indices[i];
        int value_to_insert = pend[pend_idx].first;
        int major_partner_val = pend[pend_idx].second;

        typename std::vector<int>::iterator search_limit_it;
        if (major_partner_val != -1) { // Not the straggler
            // Find major_partner_val in S. S = [b1, a1, a2, ...]. Majors start at S.begin()+1
            search_limit_it = std::lower_bound(S.begin() + (S.empty() ? 0 : 1), S.end(), major_partner_val);
        } else { // Straggler
            search_limit_it = S.end();
        }
        binaryInsert(S, value_to_insert, search_limit_it);
    }
    container = S;
}


// --- Ford-Johnson for std::deque ---
void PmergeMe::applySortAndMeasureDeque() {
     if (_parseError || _initialSequence.empty() && _timeDequeMicroseconds != 0.0) {
         if(!_initialSequence.empty()) _sortedDeque.assign(_initialSequence.begin(), _initialSequence.end());
         else _sortedDeque.clear();
    }
    _sortedDeque.assign(_initialSequence.begin(), _initialSequence.end()); // Copy

    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    fordJohnsonSort(_sortedDeque);
    std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::micro> duration = end - start;
    _timeDequeMicroseconds = duration.count();
}

void PmergeMe::binaryInsert(std::deque<int>& mainChain, int value, typename std::deque<int>::iterator searchEndIt) {
    generalBinaryInsert(mainChain, value, searchEndIt);
}


void PmergeMe::fordJohnsonSort(std::deque<int>& container) {
    size_t n = container.size();
    if (n <= 1) return;

    int straggler_val = -1;
    bool has_straggler = (n % 2 != 0);
    if (has_straggler) {
        straggler_val = container.back();
        container.pop_back();
        n--;
    }

    std::vector<ElementPair> pairs; // Using std::vector for pairs is fine, easier to manage
    for (size_t i = 0; i < n; i += 2) {
        if (container[i] >= container[i+1])
            pairs.push_back({container[i], container[i+1]});
        else
            pairs.push_back({container[i+1], container[i]});
    }
    
    if (pairs.empty()) {
        if (has_straggler) container.push_back(straggler_val);
        return;
    }

    std::deque<int> majors; // Use deque for majors to match container type for recursion
    for (size_t i = 0; i < pairs.size(); ++i) majors.push_back(pairs[i].major);
    
    fordJohnsonSort(majors); // Recursive call

    std::vector<ElementPair> sorted_pairs;
    std::multimap<int, int> major_to_minor_map;
    for (size_t i = 0; i < pairs.size(); ++i) {
        major_to_minor_map.insert(std::make_pair(pairs[i].major, pairs[i].minor));
    }

    for (size_t i = 0; i < majors.size(); ++i) {
        std::multimap<int, int>::iterator it = major_to_minor_map.find(majors[i]);
        sorted_pairs.push_back({majors[i], it->second});
        major_to_minor_map.erase(it);
    }
    
    std::deque<int> S; // Main chain
    std::vector<std::pair<int, int> > pend; // {value_to_insert, its_major_partner_value}

    if (!sorted_pairs.empty()) {
        S.push_back(sorted_pairs[0].minor);
        for (size_t i = 0; i < sorted_pairs.size(); ++i) {
            S.push_back(sorted_pairs[i].major);
            if (i > 0) {
                pend.push_back(std::make_pair(sorted_pairs[i].minor, sorted_pairs[i].major));
            }
        }
    }

    if (has_straggler) {
        pend.push_back(std::make_pair(straggler_val, -1)); // -1 indicates straggler
    }

    std::vector<size_t> insertion_indices = generateJacobsthalInsertionIndices(pend.size());

    for (size_t i = 0; i < insertion_indices.size(); ++i) {
        size_t pend_idx = insertion_indices[i];
        int value_to_insert = pend[pend_idx].first;
        int major_partner_val = pend[pend_idx].second;

        typename std::deque<int>::iterator search_limit_it;
        if (major_partner_val != -1) { // Not straggler
             typename std::deque<int>::iterator majors_start = S.begin();
             if(!S.empty()) ++majors_start; // Majors start after b1
            search_limit_it = std::lower_bound(majors_start, S.end(), major_partner_val);
        } else { // Straggler
            search_limit_it = S.end();
        }
        binaryInsert(S, value_to_insert, search_limit_it);
    }
    container = S;
}