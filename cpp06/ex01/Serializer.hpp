/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:09:37 by tponnusa          #+#    #+#             */
/*   Updated: 2024/05/14 13:46:46 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Serializer_HPP
#define Serializer_HPP

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
    private:
	    Serializer();
	    ~Serializer();
    public:
	    static uintptr_t serialize(Data *ptr);
	    static Data *deserialize(uintptr_t raw);
};

#endif