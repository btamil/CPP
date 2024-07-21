/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:09:34 by tponnusa          #+#    #+#             */
/*   Updated: 2024/05/15 14:47:18 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base()
{}

Base *generate(void)
{
	srand(static_cast<unsigned int>(time(0)));
    int random = rand() % 3;
    if (random == 0)
        return new A;
    else if (random == 1)
        return new B;
    else if (random == 2)
        return new C;
	else
		return (NULL);
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	try {
		A &a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		(void)a;
	} catch (const std::exception& err) {
	}

	try {
		B &b = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		(void)b;
	} catch(const std::exception& err) {
	}
	
	try {
		C &c = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		(void)c;
	} catch(const std::exception& err) {
	}
}