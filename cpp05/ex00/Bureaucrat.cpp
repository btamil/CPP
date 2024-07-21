/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:32:13 by tponnusa          #+#    #+#             */
/*   Updated: 2024/05/13 10:50:12 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :name("Default"), grade(150)
{
   //std::cout << "Bureaucrat is constructed" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string argName, int argGrade): name(argName), grade(argGrade)
{
	if (argGrade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (argGrade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& srcObj): name(srcObj.getName()), grade(srcObj.getGrade())
{
	*this = srcObj;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& srcObj)
{
	this->grade = srcObj.getGrade();
	return (*this);
}

const std::string& Bureaucrat::getName(void) const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::setGrade(int argGrade)
{
   if (argGrade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (argGrade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = argGrade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high to set.Pls try range from 1-150");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low to set.Pls try range from 1-150");
}

void Bureaucrat::incrementGrade()
{
	this->setGrade(this->grade - 1);
}

void Bureaucrat::decrementGrade()
{
	this->setGrade(this->grade + 1);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (os);
}

Bureaucrat::~Bureaucrat() 
{
   //std::cout << "Bureaucrat is destructed" << std::endl;
}