#include "Fixed.hpp"
/*
	bits shifting on int : 
	<< multiply by 2^bits so 256 if bits = 8
	>> divide by 2^bits so 256 if bits = 8
	so for int=10; 10 << _bits = 8 = 2560
	In binary 10 = 00000000 00001010 and 2560 = 00001010 00000000 So we shift the value to the first 8 bits
	It will enable storing the decimal in the second part of the int
	To return to the original value : shitf the same number of bits in the other way
*/
Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;
	 this->_value = intValue << this->_bits;
	return;
}

Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	 this->_value = roundf(floatValue * (1 << this->_bits));
	return;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed::Fixed(const Fixed &fixed): _value(fixed._value)
{
	std::cout << "Copy constructor called" << std::endl;
	return ;
}

Fixed	&Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Assignation operator called" << std::endl;
	if(this != &fixed)
		this->_value = fixed._value;
	return (*this);
}
bool Fixed::operator>(const Fixed &fixed) const
{
    return (_value > fixed._value);
}

bool Fixed::operator<(const Fixed &fixed) const
{
    return (_value < fixed._value);
}

bool Fixed::operator>=(const Fixed &fixed) const
{
    return (_value >= fixed._value);
}

bool Fixed::operator<=(const Fixed &fixed) const
{
    return (_value <= fixed._value);
}

bool Fixed::operator==(const Fixed &fixed) const
{
    return (_value == fixed._value);
}

bool Fixed::operator!=(const Fixed &fixed) const
{
    return (_value != fixed._value);
}

Fixed Fixed::operator+(const Fixed &fixed) const 
{
    return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
    return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
    return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
    if (fixed._value == 0) {
        throw std::runtime_error("Division by zero");
    }
    return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed& Fixed::operator++(void)
{
    _value++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    ++(*this);
    return (temp);
}

Fixed& Fixed::operator--(void)
{
    _value--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    --(*this);
    return (temp);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    return ((a < b) ? a : b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    return ((a < b) ? a : b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    return ((a > b) ? a : b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    return  ((a > b) ? a : b);
}
int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBIts member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int raw)
{
	std::cout << "setRawBIts member function called" << std::endl;
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return(static_cast<float>(this->_value) / (1 << this->_bits));
}

int Fixed::toInt(void) const
{
	return (this->_value >> this->_bits);
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}