/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:52:35 by tponnusa          #+#    #+#             */
/*   Updated: 2024/03/22 16:52:35 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a;
	ClapTrap b("Robot B");
	ClapTrap c;

	c = b;

	std::cout << std::endl;
	a.attack("Robot A");
	a.attack("Robot A");
	a.attack("Robot A");
	std::cout << std::endl;
	a.beRepaired(4);
	std::cout << std::endl;
	a.takeDamage(-5);
	std::cout << std::endl;
	a.beRepaired(7);
	std::cout << std::endl;
	b.takeDamage(15);
	std::cout << std::endl;
	b.beRepaired(10);
	std::cout << std::endl;

	c.takeDamage(1);
	std::cout << std::endl;
	c.beRepaired(1);
	std::cout << std::endl;
/*	for (int i = 0; i < 11; i++)
	{
		c.attack("test");
	}
	std::cout << std::endl;
*/
	return (0);
}