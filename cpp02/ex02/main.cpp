/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:14:03 by tponnusa          #+#    #+#             */
/*   Updated: 2024/03/22 16:30:49 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
    Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
    
	std::cout << "a = " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "max = " << Fixed::max(a, b) << std::endl;

	Fixed c = a;
	std::cout << "min = " << Fixed::min(c, b) << std::endl;
	std::cout << b / Fixed(2) << std::endl;
	std::cout << b + Fixed(-3.14f) << std::endl;
	std::cout << b - Fixed(10) << std::endl;
	std::cout << "c != a ->" << (c != a) << std::endl; 
	std::cout << "a == c ->" << (a == c) << std::endl; 
    return (0);
}