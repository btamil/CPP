/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:33:26 by tponnusa          #+#    #+#             */
/*   Updated: 2024/07/11 14:33:26 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {

    operations[0] = &RPN::add;
    operations[1] = &RPN::subtract;
    operations[2] = &RPN::multiply;
    operations[3] = &RPN::divide;
}

RPN::RPN(RPN const &other) {
    *this = other;
}

RPN &RPN::operator=(RPN const &other) {
    if (this != &other)
        this->stackObj = other.stackObj;
    return (*this);
}

RPN::~RPN() {}

int RPN::add(int a, int b)
{
    return (a + b);
}

int RPN::subtract(int a, int b)
{
    return (a - b);
}

int RPN::multiply(int a, int b)
{
    return (a * b);
}

int RPN::divide(int a, int b)
{
    if (b == 0)
        throw std::invalid_argument("Division by zero");

    return (a / b);
}

int RPN::getIndex(std::string str)
{
    std::string operators[] = {"+", "-", "*", "/"};

    for (int i = 0; i < 4; i++)
    {
        if (str == operators[i])
            return i;
    }
    return (-1);
}

int RPN::ft_stoi(const std::string& str)
{
    std::stringstream ss(str);
    int result;

    if (!(ss >> result))
        throw std::invalid_argument("Too large Number");

    return result;
}

std::string RPN::checkExpression(const std::string& str) {

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

void RPN::calculate(const std::string &expression)
{
    std::istringstream iss(expression);
	std::string token;

    try {
        
        if (expression.empty())
            throw std::invalid_argument("Empty!!");
        while (iss >> token)
        {
            int index = getIndex(token);
            if (index == -1)
                stackObj.push(ft_stoi(checkExpression(token)));
            else
            {
                // if there is less than two elements in the stack
                if (stackObj.size() < 2)
                    throw std::invalid_argument("Not enough operands!!");

                int b = this->stackObj.top();
                stackObj.pop();
                int a = this->stackObj.top();
                stackObj.pop();
                double result = (this->*operations[index])(a, b);
                if (result >= INT_MAX || result <= INT_MIN)
                {
				    throw std::invalid_argument("Result is greater than limits");
                    exit(EXIT_FAILURE);
                }
                stackObj.push(result);
            }
        }
        if (this->stackObj.size() != 1) 
            throw std::invalid_argument("Too many operands!!");

        std::cout << this->stackObj.top() << std::endl;

    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    iss.clear();
}
