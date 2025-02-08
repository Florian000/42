#pragma once

#include "Base.hpp"

class B : public Base {
public:
    B();
    ~B();
    B(const B&);
    B& operator=(const B&);
};
