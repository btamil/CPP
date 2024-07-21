/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReversePolishNotation.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:33:26 by tponnusa          #+#    #+#             */
/*   Updated: 2024/07/11 14:33:26 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReversePolishNotation.hpp"

ReversePolishNotation::ReversePolishNotation() {

    operations[0] = &ReversePolishNotation::add;
    operations[1] = &ReversePolishNotation::subtract;
    operations[2] = &ReversePolishNotation::multiply;
    operations[3] = &ReversePolishNotation::divide;
}

ReversePolishNotation::ReversePolishNotation(ReversePolishNotation const &other) {
    *this = other;
}

ReversePolishNotation &ReversePolishNotation::operator=(ReversePolishNotation const &other) {
    if (this != &other)
        this->stackObj = other.stackObj;
    return (*this);
}

ReversePolishNotation::~ReversePolishNotation() {}

int ReversePolishNotation::add(int a, int b)
{
    return (a + b);
}

int ReversePolishNotation::subtract(int a, int b)
{
    return (a - b);
}

int ReversePolishNotation::multiply(int a, int b)
{
    return (a * b);
}

int ReversePolishNotation::divide(int a, int b)
{
    if (b == 0)
        throw std::invalid_argument("Division by zero");

    return (a / b);
}

int ReversePolishNotation::getIndex(std::string str)
{
    std::string operators[] = {"+", "-", "*", "/"};

    for (int i = 0; i < 4; i++)
    {
        if (str == operators[i])
            return i;
    }
    return (-1);
}

int ReversePolishNotation::ft_stoi(const std::string& str)
{
    std::stringstream ss(str);
    int result;

    if (!(ss >> result))
        throw std::invalid_argument("Too large Number");

    return result;
}

std::string ReversePolishNotation::checkExpression(const std::string& str) {

    bool valid = true;
    size_t i = 0;

    if (str.size() == 1 && !std::isdigit(str[i]))
        valid = false;

    if (str[0] == '+' || str[0] == '-')
        i = 1;

    for (; i < str.size(); i++) {
        if (!std::isdigit(str[i]))
            valid = false;
    }
    
    if (!valid) 
		throw std::invalid_argument("Not a number");
    return str;
}

void ReversePolishNotation::calculate(std::string input)
{
    std::stringstream ss(input);

    try {
        
        if (input.empty())
            throw std::invalid_argument("Empty!!");
        if (!(ss >> input))
             throw std::invalid_argument("No expression provided!!");
        while (ss >> input)
        {
            int index = getIndex(input);
            if (index == -1)
                this->stackObj.push(ft_stoi(checkExpression(input)));
            else
            {
                // if there is less than two elements in the stack
                if (this->stackObj.size() < 2)
                    throw std::invalid_argument("Not enough operands!!");

                int b = this->stackObj.top();
                this->stackObj.pop();
                int a = this->stackObj.top();
                this->stackObj.pop();
                int result = (this->*operations[index])(a, b);
                this->stackObj.push(result);
            }
        }
        if (this->stackObj.size() != 1) 
            throw std::invalid_argument("Too many operands!!");

        std::cout << this->stackObj.top() << std::endl;

    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    ss.clear();
}
