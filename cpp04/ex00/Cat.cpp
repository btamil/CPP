/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:40:29 by tponnusa          #+#    #+#             */
/*   Updated: 2024/03/27 20:02:14 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
   this->type = "Cat";
    std::cout << "Cat is created" << std::endl;
}

 Cat::Cat(std::string arg_type)
 {
   this->type = arg_type;
    std::cout << "Cat Type: " << this->type << " created." << std::endl;
 }

 Cat::Cat(Cat const& obj)
 {
    *this = obj;
    std::cout << "Copy of Cat type: " << obj.type << " is created." << std::endl;
 }

Cat& Cat::operator=(Cat const & obj)
{
   this->type = obj.type;
	return (*this);
}

Cat::~Cat()
{
     std::cout << "Cat is dead" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meowwwwwwww........" << std::endl;
}