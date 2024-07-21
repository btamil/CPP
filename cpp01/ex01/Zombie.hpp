/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:48:19 by tponnusa          #+#    #+#             */
/*   Updated: 2024/03/13 15:48:19 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {

	private:
		std::string name;
	public:
		Zombie();
		Zombie(std::string name);
		void announce( void );
		~Zombie();
};

Zombie* zombieHorde( int N, std::string name );

#endif