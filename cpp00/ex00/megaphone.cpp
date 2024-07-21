/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:16:00 by tponnusa          #+#    #+#             */
/*   Updated: 2024/03/07 15:49:40 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include<string>

int main(int ac, char **av)
{   
    int i;
    int j;
    
    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (EXIT_SUCCESS);
    }
    i = 1;
    while (av[i])
    {
        j = 0;
        while (av[i][j])
        {
            std::cout << (char) std::toupper(av[i][j]);
            j++;
        }
        i++;
        if (av[i])
            std::cout << ' ';
    }
    std::cout << std::endl;
    return (EXIT_SUCCESS);
}

