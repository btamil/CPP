/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:30:18 by tponnusa          #+#    #+#             */
/*   Updated: 2024/04/01 18:18:35 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main(void) 
{
const Animal* meta = new Animal(); 
std::cout << std::endl; 
const Animal* j = new Dog();
std::cout << std::endl; 
const Animal* i = new Cat();
std::cout << std::endl; 
std::cout << j->getType() << " ";
j->makeSound(); //Dog sound
std::cout << std::endl; 
std::cout << i->getType() << " "; 
i->makeSound(); //will output the cat sound! 
std::cout << std::endl; 

meta->makeSound(); 
std::cout << std::endl;

const WrongAnimal* wrong_animal = new WrongAnimal();
const WrongAnimal* wrong_cat = new WrongCat();

std::cout << std::endl;
wrong_cat->makeSound();
std::cout << std::endl;
wrong_animal->makeSound();
std::cout << std::endl;

const WrongCat* wr_cat = new WrongCat();
std::cout << std::endl;
wr_cat->makeSound();
std::cout << std::endl;

delete j;
delete i;
delete meta;
delete wrong_animal;
delete wrong_cat;
delete wr_cat;

return 0; 
}