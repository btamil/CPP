/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:58:21 by tponnusa          #+#    #+#             */
/*   Updated: 2024/07/11 13:59:22 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitCoinExchange.hpp"

int main(int ac, char **av)
{
	BitCoinExchange exchangeObj;
	if (ac == 1)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	if (ac != 2)
	{
		std::cerr << "Program accepts only input file as an Argument" << std::endl;
		return (1);
	}
	struct stat path_stat;
	if (stat(av[1], &path_stat) != 0)
	{
		std::cerr << "File does not exist." << std::endl;
	}
	else if (S_ISDIR(path_stat.st_mode))
	{
		std::cerr << "Input  is a folder." << std::endl;
	}
	else if (!S_ISREG(path_stat.st_mode))
	{
		std::cerr << "It is not a regular file." << std::endl;
	}

	exchangeObj.displayExchangeRate(av[1]);

	return 0;
}
