/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:49:14 by tponnusa          #+#    #+#             */
/*   Updated: 2024/03/13 15:49:14 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanA.hpp"

HumanA::HumanA(std::string arg_name, Weapon &arg_Weapon) : name(arg_name), weapon(arg_Weapon)
{
}

HumanA::~HumanA()
{

}

void HumanA::attack()
{
	std::cout << this->name << " attacks with his " << weapon.getType() << std::endl;
}