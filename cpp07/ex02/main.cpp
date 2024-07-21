/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:06:20 by tponnusa          #+#    #+#             */
/*   Updated: 2024/05/21 20:06:21 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main(int, char**)
{
	{
		Array<int> array;
		std::cout << "array.size = " << array.size() << std::endl;
		std::cout << std::endl;
	}
	{
		Array<unsigned int> array(10);
		unsigned int len = array.size();
		std::cout << "array.size = " << len << std::endl;
		for (unsigned int i = 0; i < len; i++)
			std::cout << "array[" << i << "] = " << array[i] << std::endl;
		std::cout << std::endl;
		try {
			std::cout << "array[" << "] = " << array[11] << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	{
		Array<std::string> array(3);
		array[0] = "42";
		array[1] = "Abudhabi";
		array[2] = "Awesome";
		Array<std::string> array2(array);
		unsigned int len = array2.size();
		
		for (unsigned int i = 0; i < len; i++)
			std::cout << "array2[" << i << "] = " << array2[i] << std::endl;
		std::cout << "After modify element at Index 0" << std::endl;
		array2[0] = "@42";
		std::cout << "array[0] = " << array[0] << std::endl;
		std::cout << "array2[0] = " << array2[0] << std::endl;
		std::cout << std::endl;
	}

	return (0);
}