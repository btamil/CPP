/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:56:33 by tponnusa          #+#    #+#             */
/*   Updated: 2024/03/27 17:41:58 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	this->name = "ST-Original";
	this->hit_pts = SCAVTRAP_DEFAULT_HIT_POINTS;
	this->engy_pts = SCAVTRAP_DEFAULT_ENERGY_POINTS;
	this->damage = SCAVTRAP_DEFAULT_ATTACK_DAMAGE;
	std::cout << "ScavTrap " << this->name << " Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string arg_name) : ClapTrap(arg_name)
{
	this->name = arg_name;
	this->hit_pts = SCAVTRAP_DEFAULT_HIT_POINTS;
	this->engy_pts = SCAVTRAP_DEFAULT_ENERGY_POINTS;
	this->damage = SCAVTRAP_DEFAULT_ATTACK_DAMAGE;
	std::cout << "ScavTrap " << this->name << " Parameter constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& obj)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = obj;
}

ScavTrap&	ScavTrap::operator=(ScavTrap const& obj)
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->name = obj.getName();
		this->hit_pts = obj.getHitPoints();
		this->engy_pts = obj.getEnergyPoints();
		this->damage = obj.getAttackDamage();
	}
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->name << " is destroyed" << std::endl;
}

void ScavTrap::attack(const std::string & target)
{
	if (this->hit_pts == 0)
		std::cout << "ScavTrap: " << this->name << " is already dead and can not attack someone." << std::endl;
	else if (this->engy_pts > 0)
	{
		std::cout << "ScavTrap: " << this->name << " attacks " << target << ", causing " << this->damage << " points of damage!" << std::endl;
		this->engy_pts -= 1;
	}
	else
		std::cout << "ScavTrap: No energy points to attack" << std::endl;
}

void ScavTrap::guardGate(void)
{
	if (this->hit_pts > 0)
    	std::cout << "ScavTrap " << this->name << " is in Gate Keeper Mode now." << std::endl;
	else
		std::cout << "ScavTrap " << this->name << " can't Guard" << std::endl;
}
