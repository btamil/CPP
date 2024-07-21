/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:40:35 by tponnusa          #+#    #+#             */
/*   Updated: 2024/04/01 18:14:52 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
   this->type = "Dog";
   std::cout << "Dog is created" << std::endl;
}

 Dog::Dog(std::string arg_type)
 {
   this->type = arg_type;
    std::cout << "Dog Type: " << this->type << " created." << std::endl;
 }

 Dog::Dog(Dog const& obj)
 {
    *this = obj;
    std::cout << "Copy of Dog type: " << obj.type << " is created." << std::endl;
 }

Dog& Dog::operator=(Dog const & obj)
{
   //Animal::operator=(obj); - can use this line if many attributes hav to copied.
   this->type = obj.type;
	return (*this);
}

Dog::~Dog()
{
     std::cout << "Dog is dead" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Barking........" << std::endl;
}
