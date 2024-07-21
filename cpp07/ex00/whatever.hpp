/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:39:20 by tponnusa          #+#    #+#             */
/*   Updated: 2024/05/21 19:40:26 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T min(T &a, T &b) {
	return (a < b ? a : b);
}

template <typename T>
T max(T &a, T &b) {
	return (a > b ? a : b);
}

#endif

/** when Using Templates,
 * Compiler internally develops code when swap/mim/max called with different datatypes.
 * Function Templates: Allow functions to operate with any data type.
 * Class Templates: Allow classes to handle any data type.
 * Template Specialization: Provide specific implementations for particular data types when needed.
*/