#include "../include/Span.hpp"

Span::Span(unsigned int N) : max_size(N) {}

Span::Span(const Span& other) : numbers(other.numbers), max_size(other.max_size) {}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        numbers = other.numbers;
        max_size = other.max_size;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
    if (numbers.size() >= max_size)
        throw SpanFullException();
    numbers.push_back(number);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (std::distance(begin, end) + numbers.size() > max_size)
        throw SpanFullException();
    numbers.insert(numbers.end(), begin, end);
}

int Span::shortestSpan() const
{
    if (numbers.size() < 2)
        throw NotEnoughNumbersException();
    std::vector<int> sorted(numbers);
    std::sort(sorted.begin(), sorted.end());
    int min_span = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size() - 1; ++i)
    {
        int span = sorted[i + 1] - sorted[i];
        if (span < min_span)
            min_span = span;
    }
    return min_span;
}

int Span::longestSpan() const
{
    if (numbers.size() < 2)
        throw NotEnoughNumbersException();
    int min = *std::min_element(numbers.begin(), numbers.end());
    int max = *std::max_element(numbers.begin(), numbers.end());
    return max - min;
}

const char* Span::SpanFullException::what() const throw() { return "Span is full"; }

const char* Span::NotEnoughNumbersException::what() const throw() { return "Not enough numbers to find a span"; }
