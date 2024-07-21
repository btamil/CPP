/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:31:56 by tponnusa          #+#    #+#             */
/*   Updated: 2024/05/13 10:31:56 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * If Exception is caught in try block anywhere, control goes to catch block.
 * Remaining code of try block will not be executed.
 * Can have multiple catch blocks for try block.
 * last catch block must be Exception class.
*/

#include "Bureaucrat.hpp"

int main(void)
{
	try {
		Bureaucrat person1("Bureaucrat-P1",10);
		std::cout << person1 << std::endl;

		person1.setGrade(100);
		std::cout << person1 << std::endl;

		Bureaucrat person4(person1);
		std::cout << person4 << std::endl;
		person4.incrementGrade();
		std::cout << person4 << std::endl;
		person1.decrementGrade();
		std::cout << person1 << std::endl;

		Bureaucrat &person5 = person4;
		std::cout << person5 << std::endl;

		person4.setGrade(150);
		person4.decrementGrade();
		std::cout << person4 << std::endl;

		person5.setGrade(1);
		person4.incrementGrade();
		std::cout << person4 << std::endl;
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try{
		Bureaucrat *person2 = new Bureaucrat("Bureaucrat-p2",200);
		std::cout << *person2 << std::endl;
		std::cout << *person2 << std::endl;
		delete person2;
	} catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return (0);
}