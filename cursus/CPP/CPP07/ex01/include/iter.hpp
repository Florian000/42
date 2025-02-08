#pragma once

template <typename T, typename F>
void iter(T* array, size_t length, F func) 
{
    for (size_t i = 0; i < length; ++i)
        func(array[i]);
}

template <typename T>
void iter(T* array, std::size_t length, void (*func)(T const&)) {
    for (std::size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}
template <typename T>
void printElement(const T & element) { std::cout << element << " "; }

template <typename T>
void incrementElement(T & element) { element++; }

template <typename T>
void decrementElement(T & element) { element--; }