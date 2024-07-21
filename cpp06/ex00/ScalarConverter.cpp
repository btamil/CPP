/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:09:34 by tponnusa          #+#    #+#             */
/*   Updated: 2024/05/21 17:29:13 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(ScalarConverter const &) {}

ScalarConverter	& ScalarConverter::operator=(ScalarConverter const &) {
    return *this;
}

ScalarConverter::~ScalarConverter()
{}

void convertToChar(std::string input)
{
    char ch;
    int i;

    std::stringstream ss(input);
    i = 0;
    if (input.length() != 1)
    {
        if (input.compare("42") == 0 || input.compare("42.0") == 0 || input.compare("42.0f") == 0)
            std::cout << "char: " << "'*'\n";
        else
            std::cout << "char: Impossible\n";
        return ;
    }
    if (ss >> ch)
    {
        i = static_cast<int>(ch);
        if (!std::isdigit(i) && std::isprint(ch))
            std::cout << "char: " << ch << std::endl;
		else
			std::cout << "char: Non displayable\n";
    }
    else
        std::cout << "char: " << "Impossible" << std::endl;

}

void convertToInt(std::string input)
{
    int i;

    std::stringstream ss(input);

    if (ss >> i)
        std::cout << "int: " << i << std::endl;
    else
        std::cout << "int: " << "Impossible" << std::endl;
}

void convertToFloat(std::string input)
{
    float f;
    bool  isZero;
    std::stringstream ss(input);

    //If string has no ., it returns npos value.
    isZero = true;
    size_t decimalPos = input.find('.');
    if (decimalPos != std::string::npos) {
        for (size_t i = decimalPos + 1; i < input.size(); ++i) {
            if (input[i] != '0') {
                isZero = false;
            }
        }
    }
    if (decimalPos == std::string::npos || isZero)
            std::cout << std::fixed << std::setprecision(1);
    if (ss >> f)
    {
        std::cout << "float: " << f << "f" << std::endl;
    }
    else
        std::cout << "float: " << "Impossible" << std::endl;
}

void convertToDouble(std::string input)
{
    double d;
    std::stringstream ss(input);

    if (ss >> d)
        std::cout << "double: " << d << std::endl;
    else
        std::cout << "double: " << "Impossible" << std::endl;
}

int checkPseudoLiterals(std::string input)
{
    std::string pseudoForDouble[3] = {"-inf", "+inf", "nan"};
    std::string pseudoForFloat[3] = {"-inff", "+inff", "nanf"};
    bool isLiteral;
    
    isLiteral = false;
    for (int i = 0; i < 3; i++)
    {
        if (input == pseudoForFloat[i])
        {
            std::cout << "float: " << input << std::endl;
            std::cout << "double: " << input.substr(0, input.size() - 1) << std::endl;
            isLiteral = true;
            break;
        }
        else if (input == pseudoForDouble[i])
        {
            std::cout << "float: " << input << "f" << std::endl;
            std::cout << "double: " << input << std::endl;
            isLiteral = true;
            break;
        }   
    }
    return (isLiteral);
}

void ScalarConverter::convert(std::string argInput)
{
    convertToChar(argInput);
    convertToInt(argInput);
    if (!checkPseudoLiterals(argInput))
    {
        if (argInput.at(argInput.length() - 1) == 'f')
            argInput.erase(argInput.length() - 1, 1);
        convertToFloat(argInput);
        convertToDouble(argInput);
    }
}