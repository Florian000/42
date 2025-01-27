#pragma once

template <typename T>
void iter(T* array, size_t length, void(* func)(const T &target)) 
{
    for (size_t i = 0; i < length; ++i)
        func(array[i]);
}

template <typename T>
void iter(T* array, size_t length, void(* func)(T &target)) 
{
    for (size_t i = 0; i < length; ++i)
        func(array[i]);
}

template <typename T>
void printElement(T const & element) { std::cout << element << " "; }

template <typename T>
void incrementElement(T & element) { element++; }

template <typename T>
void decrementElement(T & element) { element--; }