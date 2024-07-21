/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:32:50 by tponnusa          #+#    #+#             */
/*   Updated: 2024/07/11 14:32:50 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReversePolishNotation.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Program requires Expression as Input" << std::endl;
        std::cout << "Ex: 7 7 + 8 *" << std::endl;
        return (EXIT_FAILURE);
    }
    ReversePolishNotation rpn;
    rpn.calculate(av[1]);

    return EXIT_SUCCESS;
}