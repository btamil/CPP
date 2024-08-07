/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 16:03:30 by tponnusa          #+#    #+#             */
/*   Updated: 2024/07/14 16:03:30 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <deque>
#include <vector>

template <typename Container>
class PmergeMe
{
	public:
		
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();


		void mergeInsertSort(Container &container, int start, int end);
		void mergeSort(Container &container, int start, int mid, int end);
		void insertSort(Container &container, int start, int end);
		void calculateTime(Container &container, double &usedTime);

		void printData(const Container &container) const;
		
};

#endif