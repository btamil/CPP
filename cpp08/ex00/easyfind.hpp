/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:39:20 by tponnusa          #+#    #+#             */
/*   Updated: 2024/05/21 19:40:26 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef easyfind_HPP
#define easyfind_HPP

# include <algorithm>
# include <exception>

class NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Number is not found");
		}
	
};

template <typename T>
typename T::iterator easyfind(T &container, int val)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), val);
	if (it == container.end())
		throw NotFoundException();
	return (it);
}

#endif

/**
 * find function returns iterator points to search valu if it found first occurence
 * If not found, it wil return the last element. So checking it is end element.
 * If end, throw error
*/
