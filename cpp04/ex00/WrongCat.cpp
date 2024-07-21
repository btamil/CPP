/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:40:29 by tponnusa          #+#    #+#             */
/*   Updated: 2024/03/27 20:02:14 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
   this->type = "WrongCat";
   std::cout << "WrongCat is created" << std::endl;
}

 WrongCat::WrongCat(std::string arg_type)
 {
   this->type = arg_type;
   std::cout << "WrongCat Type: " << this->type << " created." << std::endl;
 }

 WrongCat::WrongCat(WrongCat const& obj)
 {
    *this = obj;
    std::cout << "Copy of WrongCat type: " << obj.type << " is created." << std::endl;
 }

WrongCat& WrongCat::operator=(WrongCat const & obj)
{
	//WrongAnimal::operator=(obj);
   this->type = obj.type;
	return (*this);
}

WrongCat::~WrongCat()
{
     std::cout << "WrongCat is dead" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "some Weird sounds by Wrongcat........" << std::endl;
}