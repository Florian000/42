#pragma once
#include "Fixed.hpp"

class Point
{
    private:
        Fixed const _x;
        Fixed const _y;
    public:
        Point(void);
        Point(const float x, const float y);
        Point(const Point &point);

        Point &operator=(const Point &point);
        ~Point(void);

        Fixed getX(void) const;
        Fixed getY(void) const;
};