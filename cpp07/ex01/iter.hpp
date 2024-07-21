/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:05:23 by tponnusa          #+#    #+#             */
/*   Updated: 2024/05/21 20:05:24 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void	increment(T &val) {
	val++;
}

template <typename T>
void	iter(T *array, int length, void (*f)(T &)) {
	if (array == NULL || length <= 0) {
        std::cout << "Invalid array or length!" << std::endl;
        return;
    }
	for (int i = 0; i < length; i++) {
			f(array[i]);
	}
}

#endif