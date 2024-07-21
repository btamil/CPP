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

int main(void)
{
	std::string	fragTrapName = "FT-356";
	std::string scavTrapName = "SCVT-2000";
	std::string clapTrapName = "CT-42";

	FragTrap	fragTrap(fragTrapName);
	std::cout << std::endl;
	ScavTrap	scavTrap(scavTrapName);
	std::cout << std::endl;
	ClapTrap	clapTrap(clapTrapName);
	std::cout << std::endl;

	ClapTrap clapTrap1(fragTrap);
	
	std::cout << "Name: " << clapTrap1.getName() << " Energy points: " << clapTrap1.getEnergyPoints() << std::endl;
	fragTrap.highFivesGuys();
	std::cout << std::endl;
	clapTrap.attack(scavTrapName);
	std::cout << std::endl;
	scavTrap.takeDamage(CLAPTRAP_DEFAULT_ATTACK_DAMAGE);
	std::cout << std::endl;
	scavTrap.attack(fragTrapName);
	std::cout << std::endl;
	fragTrap.takeDamage(SCAVTRAP_DEFAULT_ATTACK_DAMAGE);
	std::cout << std::endl;
	fragTrap.beRepaired(5);
	std::cout << std::endl;
	scavTrap.guardGate();
	std::cout << std::endl;
/*	for (int i = 0; i < 100; i++) {
		fragTrap.attack(scavTrapName);
		scavTrap.takeDamage(FRAGTRAP_DEFAULT_ATTACK_DAMAGE);
	}  */
	scavTrap.beRepaired(20);
	std::cout << std::endl;
	fragTrap.highFivesGuys();
	std::cout << std::endl;
	fragTrap.takeDamage(5000);
	std::cout << std::endl;
	fragTrap.highFivesGuys();
	std::cout << std::endl;
	return (0);
}
