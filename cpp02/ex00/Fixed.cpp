/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:20:06 by tponnusa          #+#    #+#             */
/*   Updated: 2024/03/20 15:20:06 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed :: Fixed() : fix_point_num (0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed :: Fixed(const Fixed &copy_obj)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fix_point_num = copy_obj.fix_point_num;
}

Fixed& Fixed :: operator=(const Fixed &assign_obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fix_point_num = assign_obj.fix_point_num;
	return (*this);
}

Fixed :: ~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed :: getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (fix_point_num);
}

void Fixed :: setRawBits(int const raw)
{
	this->fix_point_num = raw;
}

