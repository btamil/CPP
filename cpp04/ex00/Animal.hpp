/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:32:42 by tponnusa          #+#    #+#             */
/*   Updated: 2024/03/30 18:29:42 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
    
    protected:
        std::string type;

    public:
        Animal();
        Animal(std::string arg_type);
        Animal(Animal const& obj);
        Animal& operator=(Animal const & obj);
        virtual ~Animal();
        
        std::string getType(void) const;

        virtual void makeSound(void) const;
};

#endif

/* 1. By making destructor as virtual, it ensures that the derived class destructor will be called upon delete
    if not virtual, only base class destructor will be called
    when assigning derived class obj into base class pointer
    2. By making Member function as virtual, it allows derived class to redefine the same function.
        This is called Function overriding or late binding. (Runtime polymorphism)
        Can be solved during runtime.
*/