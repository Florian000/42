#include "Point.hpp"

Point::Point(void): _x(0), _y(0)
{
    //std::cout << "Default constructor called" << std::endl;
    return ;
}

Point::Point(const float x, const float y):_x(x), _y(y)
{
    //std::cout << "Default constructor called" << std::endl;
    return ;
}

Point::Point(const Point &point): _x(point._x), _y(point._y)
{
    //std::cout << "Copy constructor called" << std::endl;
    return ;
}

Point::~Point(void)
{
    //std::cout << "Destructor called" << std::endl;
    return ;
}

Point& Point::operator=(const Point &point)
{
    (void)point;
    return (*this);
}

Fixed Point::getX(void) const
{
    return(this->_x);
}
Fixed Point::getY(void) const
{
    return (this->_y);
}