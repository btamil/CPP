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

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
	std::vector<int> v;

	for (int i = 0; i < 5; i++)
		v.push_back(i);
	try
	{
		std::vector<int>::iterator it = easyfind(v, 3);
		std::cout << "Element found in Vector: " << *it << std::endl;
		std::cout << *easyfind(v, 6) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::list<int> lst;

	for(int i =10; i <= 50;i = i+10)
		lst.push_back(i);
    try {
        std::list<int>::iterator it = easyfind(lst, 40);
        std::cout << "Element found in list: " << *it << std::endl;
    } catch (const NotFoundException& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::list<int>::iterator it = easyfind(lst, 60);
        std::cout << "Element found in list: " << *it << std::endl;
    } catch (const NotFoundException& e) {
        std::cerr << e.what() << std::endl;
    }
	return 0;
}
