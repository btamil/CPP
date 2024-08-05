/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:58:21 by tponnusa          #+#    #+#             */
/*   Updated: 2024/07/29 17:58:51 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	BitcoinExchange exchangeObj;
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
		std::cerr << "Error: File does not exist." << std::endl;
		return (1);
	}
	else if (S_ISDIR(path_stat.st_mode))
	{
		std::cerr << "Error: Input  is a folder." << std::endl;
		return (1);
	}
	else if (!S_ISREG(path_stat.st_mode))
	{
		std::cerr << "Error: It is not a regular file." << std::endl;
		return (1);
	}

	try {
		exchangeObj.initDatabase();
		exchangeObj.displayExchangeRate(av[1]);
	}catch(const std::invalid_argument& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
