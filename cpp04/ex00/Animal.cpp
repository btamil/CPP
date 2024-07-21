/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:32:48 by tponnusa          #+#    #+#             */
/*   Updated: 2024/03/27 20:20:34 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal is created" << std::endl;
}

 Animal::Animal(std::string arg_type) : type(arg_type)
 {
    std::cout << "Animal Type: " << this->type << " created." << std::endl;
 }

 Animal::Animal(Animal const& obj)
 {
    *this = obj;
    std::cout << "Copy of Animal type: " << obj.type << " is created." << std::endl;
 }

Animal& Animal::operator=(Animal const &obj)
{
	this->type = obj.type;
	return (*this);
}

Animal::~Animal()
{
     std::cout << "Animal is dead" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Animal Sounds....." << std::endl;
}

std::string Animal::getType( void ) const
{
	return (this->type);
}
