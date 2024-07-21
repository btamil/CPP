/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:57:19 by tponnusa          #+#    #+#             */
/*   Updated: 2024/05/13 14:57:19 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	{	
		Bureaucrat *a = new Bureaucrat();
		std::cout << *a << std::endl;
		Form *b = new Form();
		std::cout << b << std::endl;

		try
		{
			b->beSigned(*a);
			b->beSigned(*a);
		}
		catch(std::exception &e)
		{
			std::cerr << a->getName() << e.what() << std::endl;
		}
		delete a;
		delete b;
	}
	{
		std::cout << std::endl;
		Bureaucrat *p1;
		try
		{
			p1 = new Bureaucrat("Person1", 1);
			std::cout << *p1 << std::endl;
			p1->setGrade(-22);
		}
		catch(std::exception &e)
		{
			std::cerr << p1->getName() << " -> " << e.what() << std::endl;
		}		
		if (p1)
			delete p1;
	}
	{
		std::cout << std::endl;
		Bureaucrat *p2;
		try
		{
			p2 = new Bureaucrat("Person2", 10);
			std::cout << *p2 << std::endl;
			Form *b = new Form("Form2", -1, 2);
			std::cout << b << std::endl;
		}
		catch(std::exception &e)
		{
			std::cerr << p2->getName() << " -> "  << e.what() << std::endl;
		}		
		if (p2)
			delete p2;
	}
	{
		std::cout << std::endl;
		Bureaucrat *p3;
		Form *form3;
		try
		{
			p3 = new Bureaucrat("Person3", 55);
			std::cout << *p3 << std::endl;
			form3 = new Form("Form3", 1, 2);
			std::cout << form3 << std::endl;
			p3->signForm(*form3);
		}
		catch(std::exception &e)
		{
			std::cerr << p3->getName() << " -> "  << e.what() << std::endl;
		}		
		if (p3)
			delete p3;
		if (form3)
			delete form3;
	}
	{
		std::cout << std::endl;
		Bureaucrat *p3;
		Form *form3;
		try
		{
			p3 = new Bureaucrat("Person3", 1);
			std::cout << *p3 << std::endl;
			form3 = new Form("Form3", 2, 2);
			std::cout << form3 << std::endl;
			p3->signForm(*form3);
			p3->signForm(*form3);
			if (p3)
				delete p3;
			if (form3)
				delete form3;
		}
		catch(std::exception &e)
		{
			std::cerr << p3->getName() << " -> "  << e.what() << std::endl;
		}
	}
	return (0);
}