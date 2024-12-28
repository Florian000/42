#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int _value;
        static const int _bits = 8;

    public:
        Fixed(void);
        Fixed(const int n );
	    Fixed(const float f);
        Fixed (const Fixed &fixed);
        ~Fixed();

        Fixed	&operator=(const Fixed &fixed);

        bool operator>(const Fixed &other) const;
        bool operator<(const Fixed &other) const;
        bool operator>=(const Fixed &other) const;
        bool operator<=(const Fixed &other) const;
        bool operator==(const Fixed &other) const;
        bool operator!=(const Fixed &other) const;

        Fixed operator+(const Fixed &other) const;
        Fixed operator-(const Fixed &other) const;
        Fixed operator*(const Fixed &other) const;
        Fixed operator/(const Fixed &other) const;

        Fixed& operator++(void); 
        Fixed operator++(int);
        Fixed& operator--(void);
        Fixed operator--(int);

        static Fixed& min(Fixed &a, Fixed &b);
        static const Fixed& min(const Fixed &a, const Fixed &b);
        static Fixed& max(Fixed &a, Fixed &b);
        static const Fixed& max(const Fixed &a, const Fixed &b);

        int		toInt( void ) const;
        float	toFloat( void ) const;
        int		getRawBits(void) const;
        void	setRawBits(int raw);
};
std::ostream	&operator<<(std::ostream &out, const Fixed &fixed );