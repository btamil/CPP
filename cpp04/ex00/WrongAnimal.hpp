/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 18:32:42 by tponnusa          #+#    #+#             */
/*   Updated: 2024/03/27 20:26:08 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
    
    protected:
        std::string type;

    public:
        WrongAnimal();
        WrongAnimal(std::string arg_type);
        WrongAnimal(WrongAnimal const& obj);
        WrongAnimal& operator=(WrongAnimal const & obj);
        ~WrongAnimal();
        
        std::string getType(void) const;

        void makeSound(void) const;
};

#endif
