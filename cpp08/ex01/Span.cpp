/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:39:20 by tponnusa          #+#    #+#             */
/*   Updated: 2024/05/21 19:40:26 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

Span::Span() : N(0)
{}

Span::Span(unsigned int val) : N(val)
{}

Span::Span(const Span &src)
{
	*this = src;
}

Span &Span::operator=(const Span &src)
{
	if (this != &src)
	{
		N = src.N;
		v = src.v;
	}
	return (*this);
}

Span::~Span()
{}

void	Span::addNumber(int value)
{
	if (N <= 0)
		throw ContainerEmptyException();
	else if (v.size() >= N)
		throw ContainerOverFlowException();	
	v.push_back(value);
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (v.size() + std::distance(begin, end) > N)
		throw ContainerOverFlowException();
	v.insert(v.end(), begin, end);
}

int		Span::shortestSpan()
{
	if (v.size() <= 1)
		throw InSufficientValuesException();
	std::vector<int> tmp = v;
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i - 1] < min)
			min = tmp[i] - tmp[i - 1];
	}
	return (min);
}

int		Span::longestSpan()
{
	if (v.size() <= 1)
		throw InSufficientValuesException();
	std::vector<int> tmp = v;
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}

const char *Span::ContainerOverFlowException::what() const throw()
{
	return ("Container is full!!");
}

const char *Span::InSufficientValuesException::what() const throw()
{
	return ("Container does not have enough values!!");
}

const char *Span::ContainerEmptyException::what() const throw()
{
	return ("Container Cannot hold values!!");
}

