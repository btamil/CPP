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

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	this->name = "FT-Original";
	this->hit_pts = FRAGTRAP_DEFAULT_HIT_POINTS;
	this->engy_pts = FRAGTRAP_DEFAULT_ENERGY_POINTS;
	this->damage = FRAGTRAP_DEFAULT_ATTACK_DAMAGE;
	std::cout << "FragTrap " << this->name << " Default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string arg_name) : ClapTrap(arg_name)
{
	this->name = arg_name;
	this->hit_pts = FRAGTRAP_DEFAULT_HIT_POINTS;
	this->engy_pts = FRAGTRAP_DEFAULT_ENERGY_POINTS;
	this->damage = FRAGTRAP_DEFAULT_ATTACK_DAMAGE;
	std::cout << "FragTrap " << this->name << " Parameter constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const& obj)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = obj;
}

FragTrap&	FragTrap::operator=(FragTrap const& obj)
{
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		this->name = obj.getName();
		this->hit_pts = obj.getHitPoints();
		this->engy_pts = obj.getEnergyPoints();
		this->damage = obj.getAttackDamage();
	}
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->name << " is destroyed" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (this->hit_pts == 0)
		std::cout << this->name
			<< "Would like to High-Five you"
			<< std::endl;
	else
		std::cout << this->name << " Let's High-Five guys!!!"
			<< std::endl;
}
