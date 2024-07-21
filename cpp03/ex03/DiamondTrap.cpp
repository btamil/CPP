/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:56:33 by tponnusa          #+#    #+#             */
/*   Updated: 2024/03/22 18:28:36 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	this->name = "Diamond Original";
	std::cout << "DiamondTrap " << this->name << " Default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string arg_name): ClapTrap(arg_name + "_clap_name")
{
	this->name = arg_name;
	this->hit_pts = FRAGTRAP_DEFAULT_HIT_POINTS;
	this->engy_pts = SCAVTRAP_DEFAULT_ENERGY_POINTS;
	this->damage = FRAGTRAP_DEFAULT_ATTACK_DAMAGE;
	std::cout << "DiamondTrap " << this->name << " parameter constructor called." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->name << " is destroyed" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const& obj)
{
	std::cout << "DiamondTrap copy constructor" << std::endl;
	operator=(obj);
}

DiamondTrap&	DiamondTrap::operator=(DiamondTrap const& obj)
{
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	ClapTrap::operator=(obj);
	this->name = obj.name;
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, DiamondTrap const& obj)
{
	obj.display(os);
	return (os);
}

void	DiamondTrap::display(std::ostream& stream) const
{
	stream << "Diamond-TP " << name << " / " << ClapTrap::name << " has " << hit_pts << " hit points, " 
	<< engy_pts << " energy points and " << damage << " attack dammage.";

}

void	DiamondTrap::whoAmI() const
{
	std::cout << "My name: " << name << " My ClapTrap-Name: " << ClapTrap::name << std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}
