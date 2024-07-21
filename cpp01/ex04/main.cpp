/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:35:31 by tponnusa          #+#    #+#             */
/*   Updated: 2024/03/20 14:47:25 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "\033[38;2;255;0;0m" 
        << "Program accepts only three parameters(./main filename str_to_find str_to_replace_by)" 
        << "\033[0m" << std::endl;
        return (0);
    }
    if (!av[1][0] || !av[2][0] || !av[3][0])
    {
        std::cout << "value cannot be empty" << std::endl;
        return (0);
    }
    std::ifstream   inFile(av[1]);
    std::string     fileName = av[1];
    if (!inFile.is_open())
    {
        std::cout << "Coulnd't open the input file" << std::endl;
        return (1);
    }
    std::ofstream   outFile(fileName + ".replace", std::ios::out);
    std::string     line;
    
    if (!outFile.is_open())
	{
		std::cout << "Coulnd't open output file" << std::endl;
		return (1);
	}
    std::string str_to_find = av[2];
    std::string str_to_replace = av[3];
    while(getline(inFile, line))
    {
        size_t occ_index = line.find(str_to_find, 0);
        while (occ_index != std::string::npos)
        {
            line.erase(occ_index, str_to_find.length());
            line.insert(occ_index, str_to_replace);
            occ_index = line.find(str_to_find, occ_index);
        }
        if (!std::cin.eof())
            outFile << line << std::endl;
    }
    inFile.close();
    outFile.close();     
    return (0);
}