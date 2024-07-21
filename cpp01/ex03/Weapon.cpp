/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:35:15 by tponnusa          #+#    #+#             */
/*   Updated: 2024/03/13 16:35:15 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string arg_type) : type(arg_type)
{
	this->type = arg_type;
}

Weapon::~Weapon()
{
}

std::string const &Weapon::getType(void)
{
	return (this->type);
}

void	Weapon::setType(std::string arg_type)
{
	this->type = arg_type;
}