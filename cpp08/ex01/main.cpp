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

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " <<sp.longestSpan() << std::endl;
		try
		{
			sp.addNumber(14);
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		Span sp = Span(0);
	 	try { 		
	 		sp.addNumber(1);
	 	}catch (std::exception &e)
	 	{
	 		std::cerr << e.what() << std::endl;
	 	}
	}
	{
		Span sp3 = Span(20000);
		std::vector<int> v2;
		std::srand(time(NULL));
		for (int i = 0; i < 20000; i++)
		{
			
			int random_val = rand();
			v2.push_back(random_val);
		}
		try
		{
			sp3.addNumber(v2.begin(), v2.end());
			std::cout << "shortest span: " << sp3.shortestSpan() << std::endl;
			std::cout << "longest span: " << sp3.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
