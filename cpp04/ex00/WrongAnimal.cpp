/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:32:48 by tponnusa          #+#    #+#             */
/*   Updated: 2024/03/27 20:20:34 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "WrongAnimal is created" << std::endl;
}

 WrongAnimal::WrongAnimal(std::string arg_type) : type(arg_type)
 {
    std::cout << "WrongAnimal Type: " << this->type << " created." << std::endl;
 }

 WrongAnimal::WrongAnimal(WrongAnimal const& obj)
 {
    *this = obj;
    std::cout << "Copy of WrongAnimal type: " << obj.type << " is created." << std::endl;
 }

WrongAnimal& WrongAnimal::operator=(WrongAnimal const & obj)
{
	this->type = obj.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
     std::cout << "WrongAnimal is dead" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal Sounds not good....." << std::endl;
}

std::string WrongAnimal::getType( void ) const
{
	return (this->type);
}
