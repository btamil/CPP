/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:21:06 by tponnusa          #+#    #+#             */
/*   Updated: 2024/03/20 15:21:06 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed :: Fixed() : fix_point_num (0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed :: Fixed(const Fixed &copy_obj) : fix_point_num(copy_obj.fix_point_num)
{
	//std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed :: operator=(const Fixed &assign_obj)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	this->fix_point_num = assign_obj.fix_point_num;
	return (*this);
}

Fixed::Fixed(const int int_arg)
{
	//std::cout << "Int constructor called" << std::endl;
	setRawBits(int_arg << this->fract_bits);
}

//To convert from floating-point to fixed-point, followed this algorithm:

//Calculate x = floating_input * 2^(fractional_bits) -> 2^8 = 256(1<<8)
//Round x to the nearest whole number (e.g. round(x))
//Store the rounded x in an integer container

Fixed::Fixed(const float float_arg)
{
	//std::cout << "Float constructor called" << std::endl;
	this->setRawBits((int)roundf(float_arg * (1 << this->fract_bits)));
}

Fixed :: ~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

int Fixed :: getRawBits(void) const
{
	return (fix_point_num);
}

void Fixed :: setRawBits(int const raw)
{
	this->fix_point_num = raw;
}

float Fixed::toFloat(void) const
{
	float	valInFloat;

	valInFloat = (float)this->getRawBits() / (1 << this->fract_bits);
	return (valInFloat);
}

int Fixed::toInt(void) const
{
	return (this->getRawBits() >> this->fract_bits);
}

std::ostream& operator<<(std::ostream &os, const Fixed &obj)
{
	os << obj.toFloat();
	return (os);
}

int Fixed::operator>( Fixed const & operand) const
{
	if (this->getRawBits() > operand.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator<( Fixed const & operand) const
{
	if (this->getRawBits() < operand.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator>=( Fixed const & operand) const
{
	if (this->getRawBits() >= operand.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator<=( Fixed const & operand) const
{
	if (this->getRawBits() <= operand.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator==( Fixed const & operand) const
{
	if (this->getRawBits() == operand.getRawBits())
		return (1);
	return (0);
}

int Fixed::operator!=( Fixed const & operand) const
{
	if (this->getRawBits() != operand.getRawBits())
		return (1);
	return (0);
}

Fixed Fixed::operator+( Fixed const & operand) const
{
	Fixed ret(this->toFloat() + operand.toFloat());
	
	return (ret);
}

Fixed Fixed::operator-( Fixed const & operand) const
{
	Fixed ret(this->toFloat() - operand.toFloat());
	
	return (ret);
}

Fixed Fixed::operator*( Fixed const & operand) const
{
	Fixed ret(this->toFloat() * operand.toFloat());

	return (ret);
}

Fixed Fixed::operator/( Fixed const & operand) const
{
	Fixed ret(this->toFloat() / operand.toFloat());
	
	return (ret);
}

//operand++
Fixed & Fixed::operator++( void ) 
{
	this->fix_point_num += 1;
	return (*this);
}

//operand--
Fixed & Fixed::operator--( void ) // Prefix 
{
	this->fix_point_num -= 1;
	return (*this);
}

//++operand
Fixed Fixed::operator++( int ) // Postfix
{
	Fixed	tmp = *this;

	(this->fix_point_num) += 1 ;
	return (tmp);
}

//--operand
Fixed Fixed::operator--( int ) // Postfix
{
	Fixed	tmp = *this;

	(this->fix_point_num) -= 1 ;
	return (tmp);
}

const Fixed & Fixed::min(const Fixed & obj1, const Fixed & obj2)
{
	if (obj1 < obj2)
		return (obj1);
	return (obj2);
}
	
const Fixed & Fixed::max(const Fixed & obj1, const Fixed & obj2)
{
	if (obj1 > obj2)
		return (obj1);
	return (obj2);
}

Fixed & Fixed::min(Fixed & obj1, Fixed & obj2)
{
	if (obj1 < obj2)
		return (obj1);
	return (obj2);
}
	
Fixed & Fixed::max(Fixed & obj1, Fixed & obj2)
{
	if (obj1 > obj2)
		return (obj1);
	return (obj2);
}
