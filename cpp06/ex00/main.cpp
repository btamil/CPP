/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:54:12 by tponnusa          #+#    #+#             */
/*   Updated: 2024/05/21 15:16:36 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{    
    if (ac != 2)
    {
        std::cout << "Program takes one argument to do Conversion!" << std::endl;
        return (0);
    }
    if (ac == 2 && av[1][0] == '\0')
    {
        std::cout << "Input is Empty!!!" << std::endl;
        return (0);
    }         
    ScalarConverter::convert(av[1]);
    return (0);
}