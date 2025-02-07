#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span {

    private:
        std::vector<int> numbers;
        unsigned int max_size;

    public:
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int number);
        void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int shortestSpan() const;
        int longestSpan() const;

        class SpanFullException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class NotEnoughNumbersException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};
