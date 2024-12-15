#include "Point.hpp"

// Calculate the area of the triangle and then each triangle for the point = a b or c 
// if A1 + A2 + A3 = A and all era are > 0 the point is inside the triangle

Fixed area(Point const a, Point const b, Point const c)
{
    return Fixed((a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()) +
                  b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()) +
                  c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) / 2.0f);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed A = area(a, b, c);
    Fixed A1 = area(point, b, c);
    Fixed A2 = area(a, point, c);
    Fixed A3 = area(a, b, point);

    return (A1 > 0 && A2 > 0 && A3 > 0 && (A1 + A2 + A3) == A);
}