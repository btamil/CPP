/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:05:11 by tponnusa          #+#    #+#             */
/*   Updated: 2024/05/21 20:05:12 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int main(void) {
	{
		int a = 2;
		int b = 3;
		std::cout << "Swap Int variables" << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		::swap(a, b);
		std::cout << "After Swap" << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
		std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		std::cout << "c = " << c << ", d = " << d << std::endl;
		::swap(c, d);
		std::cout << "After Swap" << std::endl;
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
		std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
	}
	{
		float a = 2.1;
		float b = 3.1;
		std::cout << "\nSwap Float variables" << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		::swap(a, b);
		std::cout << "After Swap" << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	}
	{
		double a = 2.1;
		double b = 3.1;
		std::cout << "\nSwap Double variables" << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		::swap(a, b);
		std::cout << "After Swap" << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	}

	return 0;
}
