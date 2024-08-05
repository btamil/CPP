/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                          :+:      :+:    :+:   */
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
#include <climits>

class RPN
{
private:
    std::stack<int> stackObj;

    typedef int (RPN::*doArithmetic)(int, int);

    doArithmetic operations[5];

    int         add(int a, int b);
    int         subtract(int a, int b);
    int         multiply(int a, int b);
    int         divide(int a, int b);

    int         getIndex(std::string str);
    int         ft_stoi(const std::string& str);
    std::string checkExpression(const std::string& str);

public:
    RPN();
    RPN(RPN const &other);
    RPN &operator=(RPN const &other);
    ~RPN();

    void calculate(const std::string &expression);
};