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

int main(void)
{
	ScavTrap	st("Derived");
	ClapTrap 	ct;
	
	std::cout << std::endl;
	std::string target_name = "ST-Robot";

	std::cout << "CT-Energy Points: " << ct.getEnergyPoints() << std::endl;
	std::cout << "ST-Energy Points: " << st.getEnergyPoints() << std::endl;
	st.attack(target_name);
	std::cout << std::endl;
	st.takeDamage(42);
	std::cout << std::endl;
	st.guardGate();
	std::cout << std::endl;
	st.takeDamage(220);
	std::cout << std::endl;
	st.guardGate();
	std::cout << std::endl;

	ct.attack("CT-Robot");
	std::cout << std::endl;
	ct.takeDamage(5);
	std::cout << std::endl;
	ct.beRepaired(3);
	std::cout << std::endl;

	st.beRepaired(10);
	std::cout << std::endl;

}