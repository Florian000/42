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

        int		toInt( void ) const;
        float	toFloat( void ) const;
        int		getRawBits(void) const;
        void	setRawBits(int raw);
};

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed );