/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:04:34 by tponnusa          #+#    #+#             */
/*   Updated: 2024/03/20 15:06:06 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl service;

	if (argc != 2)
	{
		std::cout << "Program accepts only 2 parameters: ./pgm_name complain_level" << std::endl;
		return (-1);
	}
	service.complain(argv[1]);
	return (0);
}