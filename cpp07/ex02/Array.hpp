/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:06:14 by tponnusa          #+#    #+#             */
/*   Updated: 2024/05/21 20:06:15 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <limits>

template <typename T>
class Array
{
	private:
		T* 				array;
		unsigned int 	_size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& src);
		Array& operator=(const Array& src);
		~Array();

		T& operator[](unsigned int index);
		unsigned int size() const;


	class IndexOutOfRangeException : public std::exception
	{
		public:
			virtual const char* what() const throw() {
				return "Index Out of range!!";
		}
	};
};

template<typename T>
Array<T>::Array() {
	this->array = NULL;
	this->_size = 0;
}

template<typename T>
Array<T>::Array(unsigned int n) {
	this->array = new T[n];
	this->_size = n;
}

template<typename T>
Array<T>::Array(const Array& src) {
	this->array = new T[src._size];
	if (this->array == NULL)
		return ;
	this->_size = src._size;
	for (unsigned int i = 0; i < size(); i++)
		this->array[i] = src.array[i];
}

template<typename T>
Array<T>::~Array() {
	if (array)
		delete[] array;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& src) {
	if (array)
		delete[] array;
	this->array = new T[src._size];
	this->_size = src._size;
	for (unsigned int i = 0; i < size(); i++)
		array[i] = src.array[i];
	return (*this);
}

template<typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= size())
		throw IndexOutOfRangeException();
	return array[index];
}

template<typename T>
unsigned int Array<T>::size() const {
	return (this->_size);
}

#endif