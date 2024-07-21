
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int fix_point_num;
		static const int fract_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed& copy);
		Fixed(const int value);
		Fixed(const float value);
		Fixed& operator=(const Fixed& assign_obj);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream& operator<<(std::ostream &os, const Fixed& obj);
#endif