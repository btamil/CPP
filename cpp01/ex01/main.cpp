/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:47:44 by tponnusa          #+#    #+#             */
/*   Updated: 2024/03/13 15:47:44 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

int main(void)
{
	Zombie	*horde;
	int 	no_of_zombies;

	no_of_zombies = 5;
	horde = zombieHorde(no_of_zombies, "ZombieGroup");

	for (int i = 0; i < no_of_zombies; i++)
	{
		horde[i].announce();
	}

	delete[] horde;
	return (0);
}
