/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:09:37 by tponnusa          #+#    #+#             */
/*   Updated: 2024/05/21 15:27:56 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <iomanip>
#include <cmath>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &srcObj);
        ScalarConverter& operator=(ScalarConverter const &srcObj);
        
    public:
        ~ScalarConverter();
        static void convert(std::string argInput);

};

#endif