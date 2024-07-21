/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:56:54 by tponnusa          #+#    #+#             */
/*   Updated: 2024/05/13 14:56:54 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): name("default"), is_signed(false), sign_grade(150), exec_grade(150)
{
	//std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form(const std::string arg_name, int arg_sign_grade, int arg_exec_grade): name(arg_name), is_signed(false)
			, sign_grade(arg_sign_grade), exec_grade(arg_exec_grade)
{
	if (arg_sign_grade < 1 || arg_exec_grade < 1)
		throw Form::GradeTooHighException();
	if (arg_sign_grade > 150 || arg_exec_grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &srcObj): name(srcObj.getName()), is_signed(false)
			, sign_grade(srcObj.getSignGrade()), exec_grade(srcObj.getExecGrade())
{
	if (srcObj.getSignGrade() < 1 || srcObj.getExecGrade() < 1)
		throw Form::GradeTooHighException();
	if (srcObj.getSignGrade() > 150 || srcObj.getExecGrade() > 150)
		throw Form::GradeTooLowException();
	*this = srcObj;
}

//All members are private and constant. So cannot assign.
Form &Form::operator=(const Form &srcObj)
{
	if (this == &srcObj)
		return (*this);
	return (*this);
}

void Form::beSigned(Bureaucrat &signer)
{
	if (signer.getGrade() > this->getSignGrade())
		throw Bureaucrat::GradeTooLowException();
	else if (!this->getIsSignedBool())
	{
		this->is_signed = true;
		std::cout << signer.getName() << " signed " << this->getName() << " Form." << std::endl;
	}
	else
		std::cout << signer.getName() << " form " << this->getName() << " is already signed!!" << std::endl;
}

const std::string	Form::getName(void) const
{
	return (this->name);
}

bool	Form::getIsSignedBool(void) const
{
	return (this->is_signed);
}

int	Form::getSignGrade(void) const
{
	return (this->sign_grade);
}

int	Form::getExecGrade(void) const
{
	return (this->exec_grade);
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low!!S");
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high!!");
}

std::ostream	&operator<<(std::ostream &os, const Form *a)
{
	os << "Form: " << a->getName() <<
	" sign-grade: " << a->getSignGrade() <<
	" exec-grade: " << a->getExecGrade();
	if (a->getIsSignedBool())
		os << " is signed." << std::endl;
	else
		os << " is not signed." << std::endl;
	return (os);
}

Form::~Form()
{
	//std::cout << "Form is Destructed" << std::endl;
}