/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:46:25 by tponnusa          #+#    #+#             */
/*   Updated: 2024/03/13 15:46:25 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Zombie.hpp"

int	main(void)
{
	std::cout << "============= stackZombies =============" << std::endl;
	Zombie	obj1("Zombie1");
	Zombie	obj2("Zombie2");
	Zombie	obj3;

	obj1.announce();
	obj2.announce();
	obj3.announce();
	std::cout << "============= RandomZombie =============" << std::endl;
	randomChump("ZombieHead");

	std::cout << std::endl;
	std::cout << "============= heapZombies ==============" << std::endl;
	Zombie	*heapZ;

	heapZ = newZombie("HeapZombie");
	heapZ->announce();
	delete(heapZ);

	return (0);
}