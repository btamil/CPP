/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:34:43 by tponnusa          #+#    #+#             */
/*   Updated: 2024/03/13 16:34:43 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanB.hpp"

HumanB::HumanB(std::string arg_name) : name(arg_name), weapon(NULL)
{
}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon(Weapon &arg_weapon)
{
	this->weapon = &arg_weapon;
}

void	HumanB::attack(void)
{
	if (this->weapon == NULL)
		std::cout << this->name << " has no weapon" << std::endl;
	else
	{
		std::cout << this->name << " attacks with his ";
		std::cout << (this->weapon)->getType() << std::endl;
	}
}