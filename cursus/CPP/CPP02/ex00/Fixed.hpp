#include <iostream>

class Fixed
{
    private:
        int _value;
        static const int _bits = 8;

    public:
        Fixed();
        Fixed (Fixed &fixed);
        ~Fixed();
        Fixed	&operator=(Fixed &fixed);

        int		getRawBits(void) const;
        void	setRawBits(int raw);
};