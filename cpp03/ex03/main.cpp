/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:52:35 by tponnusa          #+#    #+#             */
/*   Updated: 2024/03/22 16:52:35 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << "\n### TESTING DIAMONDTRAP ###\n" << std::endl;
	{
		DiamondTrap a;

		std::cout << std::endl;
		a.whoAmI();
		a.attack("Random Robot");
		std::cout << std::endl;

		DiamondTrap b("Giga Chadd");
		std::cout << std::endl;

		b.whoAmI();
		b.attack("Chadd-clone");
		std::cout << std::endl;
		std::cout << b << std::endl;

		//	DiamondTrap c(a);

		
	//	a.attack("some super random dude");
	//	c.whoAmI();
	}
	return (0);
}
