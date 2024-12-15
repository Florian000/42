#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);
    Point point(1.5f, 2.6f);

    if (bsp(a, b, c, point))
        std::cout << "Point is inside the triangle" << std::endl;
    else
        std::cout << "Point is outside the triangle" << std::endl;

    return 0;
}