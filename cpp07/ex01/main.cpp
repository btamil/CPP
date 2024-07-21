/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:05:28 by tponnusa          #+#    #+#             */
/*   Updated: 2024/05/21 20:05:29 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int main(void) 
{
	{
		int array[5] = {1, 2, 3, 4, 5};
		iter<int>(array, 5, increment<int>);
		for (int i = 0; i < 5; i++)
			std::cout << "[" << i << "] = " << array[i] << std::endl;
		std::cout << std::endl;
		iter<int>(array, -5, increment<int>);
	}
	{
		char array[3] = {'a', 'b', 'c'};
		iter<char>(array, 3, increment<char>);
		for (int i = 0; i < 3; i++)
			std::cout << "[" << i << "] = " << array[i] << std::endl;
		std::cout << std::endl;
		iter<char>(array, 3, increment<char>);
	}
	return 0;
}
