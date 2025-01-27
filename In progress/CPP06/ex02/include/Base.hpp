#pragma once

class Base {
public:
    Base();
    virtual ~Base();
    Base(const Base&);
    Base& operator=(const Base&);
};
