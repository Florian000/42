#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <stdexcept>
#include <utility>
#include <cstdlib>
#include <cerrno>
#include <climits>

// Pair of elements used in FJ algorithm
struct ElementPair 
{
    int major;
    int minor;
};

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(const PmergeMe& src);
    PmergeMe& operator=(const PmergeMe& rhs);
    ~PmergeMe();

    void processInputAndSort(int argc, char **argv);
    void displayResults() const;

private:
    std::vector<int> _initialSequence;

    std::vector<int> _sortedVector;
    double _timeVectorMicroseconds;

    std::deque<int> _sortedDeque;
    double _timeDequeMicroseconds;

    void parseValidateInput(int argc, char **argv);

    template <typename Container>
    void printSequence(const Container& c, const std::string& prefix) const;
    
    std::vector<size_t> generateJacobsthalInsertionIndices(size_t numPendElements);

    void applySortAndMeasureVector();
    void fordJohnsonSort(std::vector<int>& container);
    void binaryInsert(std::vector<int>& mainChain, int value, std::vector<int>::iterator searchEndIt);

    void applySortAndMeasureDeque();
    void fordJohnsonSort(std::deque<int>& container);
    void binaryInsert(std::deque<int>& mainChain, int value, std::deque<int>::iterator searchEndIt);
};