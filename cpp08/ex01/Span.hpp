/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:39:20 by tponnusa          #+#    #+#             */
/*   Updated: 2024/05/21 19:40:26 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Span_HPP
#define Span_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>

class Span
{
	private:
		unsigned int		N;
		std::vector<int>	v;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();


		void	addNumber(int n);
		int		shortestSpan();
		int		longestSpan();
		void 	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	
	class ContainerOverFlowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class InSufficientValuesException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	
	class ContainerEmptyException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

#endif
