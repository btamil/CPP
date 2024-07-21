/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:09:37 by tponnusa          #+#    #+#             */
/*   Updated: 2024/05/14 13:46:46 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base {
	public:
		virtual ~Base();
};

class A : public Base {
};

class B : public Base {
};

class C : public Base {
};

Base	*generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif