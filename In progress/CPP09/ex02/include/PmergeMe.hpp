#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm> // Pour std::lower_bound, std::sort (sur paires si besoin), std::min
#include <ctime>     // Pour clock() en C++98
#include <iomanip>   // Pour std::fixed, std::setprecision
#include <stdexcept> // Pour les exceptions
#include <limits>    // Pour std::numeric_limits (non utilisé directement mais bon à avoir)
#include <list>      // Peut être utilisé pour gérer les paires ou les éléments en attente
#include <map>       // Pour std::multimap

// Structure pour contenir une paire d'éléments (major >= minor)
struct ElementPair {
    int major;
    int minor;
};

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& src);
    PmergeMe& operator=(const PmergeMe& rhs);
    ~PmergeMe();

    void processInput(int argc, char **argv);
    void displayResults() const;

private:
    std::vector<int> _initialSequence;
    bool _parseError; // Indique si une erreur d'analyse a eu lieu

    std::vector<int> _sortedVector;
    double _timeVectorMicroseconds;

    std::deque<int> _sortedDeque;
    double _timeDequeMicroseconds;

    // --- Analyse de l'entrée ---
    void parseValidateInput(int argc, char **argv);

    // --- Utilitaires communs ---
    // typename est correct ici car c'est un template
    template <typename Container>
    void printSequence(const Container& c, const std::string& prefix) const;
    
    std::vector<size_t> generateJacobsthalInsertionIndices(size_t numPendElements);

    // --- Ford-Johnson pour std::vector ---
    void applySortAndMeasureVector();
    void fordJohnsonSort(std::vector<int>& container);
    // typename n'est PAS nécessaire ici car ce n'est pas un template
    void binaryInsert(std::vector<int>& mainChain, int value, std::vector<int>::iterator searchEndIt);

    // --- Ford-Johnson pour std::deque ---
    void applySortAndMeasureDeque();
    void fordJohnsonSort(std::deque<int>& container);
    // typename n'est PAS nécessaire ici
    void binaryInsert(std::deque<int>& mainChain, int value, std::deque<int>::iterator searchEndIt);
};