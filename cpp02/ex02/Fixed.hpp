
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
		//Overloading relational operators
		int operator>(Fixed const & rhs) const;
		int operator<(Fixed const & rhs) const;
		int operator>=(Fixed const & rhs) const;
		int operator<=(Fixed const & rhs) const;
		int operator==(Fixed const & rhs) const;
		int operator!=(Fixed const & rhs) const;
		
		// Overloading Arithmetic operators
		Fixed operator+(Fixed const & rhs) const;
		Fixed operator-(Fixed const & rhs) const;
		Fixed operator*(Fixed const & rhs) const;
		Fixed operator/(Fixed const & rhs) const;

		//Overloading increment/decrement operator
		Fixed & operator++( void ); // Prefix (++F)
		Fixed & operator--( void ); // Prefix (--F)
		Fixed operator++( int value ); // Postfix (F++)
		Fixed operator--( int value ); // Postfix (F--)

		// min & max
		static Fixed & min(Fixed & a, Fixed & b );
		static Fixed & max(Fixed & a, Fixed & b );
		static const Fixed & min(const Fixed & a, const Fixed & b );
		static const Fixed & max(const Fixed & a, const Fixed & b );
};

std::ostream& operator<<(std::ostream &os, const Fixed& obj);
#endif