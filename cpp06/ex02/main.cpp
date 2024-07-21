/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:54:12 by tponnusa          #+#    #+#             */
/*   Updated: 2024/05/21 15:41:53 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
    Base *randPtr = generate();
	identify(randPtr);
	identify(NULL);
	
	delete randPtr;

	Base &randRef = *generate();
	identify(randRef);
    return (0);
}
