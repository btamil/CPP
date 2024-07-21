/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReversePolishNotation.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:33:36 by tponnusa          #+#    #+#             */
/*   Updated: 2024/07/11 14:33:36 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cmath>

class ReversePolishNotation
{
private:
    std::stack<int> stackObj;

    typedef int (ReversePolishNotation::*doArithmetic)(int, int);

    doArithmetic operations[5];

    int add(int a, int b);
    int subtract(int a, int b);
    int multiply(int a, int b);
    int divide(int a, int b);

    int         getIndex(std::string str);
    int         ft_stoi(const std::string& str);
    std::string checkExpression(const std::string& str);

public:
    ReversePolishNotation();
    ReversePolishNotation(ReversePolishNotation const &other);
    ReversePolishNotation &operator=(ReversePolishNotation const &other);
    ~ReversePolishNotation();

    void calculate(std::string input);
};