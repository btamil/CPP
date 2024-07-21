/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:57:40 by tponnusa          #+#    #+#             */
/*   Updated: 2024/05/13 14:57:40 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): name("default"), is_signed(false), sign_grade(150), exec_grade(150)
{
	//std::cout << "AForm Default Constructor called" << std::endl;
}

AForm::AForm(const std::string arg_name, int arg_sign_grade, int arg_exec_grade): name(arg_name), is_signed(false)
			, sign_grade(arg_sign_grade), exec_grade(arg_exec_grade)
{
	if (arg_sign_grade < 1 || arg_exec_grade < 1)
		throw AForm::GradeTooHighException();
	if (arg_sign_grade > 150 || arg_exec_grade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &srcObj): name(srcObj.getName()), is_signed(false)
			, sign_grade(srcObj.getSignGrade()), exec_grade(srcObj.getExecGrade())
{
	if (srcObj.getSignGrade() < 1 || srcObj.getExecGrade() < 1)
		throw AForm::GradeTooHighException();
	if (srcObj.getSignGrade() > 150 || srcObj.getExecGrade() > 150)
		throw AForm::GradeTooLowException();
	*this = srcObj;
}

//All members are private and constant. So cannot assign.
AForm &AForm::operator=(const AForm &srcObj)
{
	if (this == &srcObj)
		return (*this);
	return (*this);
}

void AForm::beSigned(Bureaucrat &signer)
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

const std::string	AForm::getName(void) const
{
	return (this->name);
}

bool	AForm::getIsSignedBool(void) const
{
	return (this->is_signed);
}

int	AForm::getSignGrade(void) const
{
	return (this->sign_grade);
}

int	AForm::getExecGrade(void) const
{
	return (this->exec_grade);
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low!!S");
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high!!");
}

const char *AForm::NotSignedException::what(void) const throw()
{
	return ("Form is not signed!!");
}

std::ostream	&operator<<(std::ostream &os, const AForm *a)
{
	os << "AForm: " << a->getName() <<
	" sign-grade: " << a->getSignGrade() <<
	" exec-grade: " << a->getExecGrade();
	if (a->getIsSignedBool())
		os << " is signed." << std::endl;
	else
		os << " is not signed." << std::endl;
	return (os);
}

AForm::~AForm()
{
	//std::cout << "AForm is Destructed" << std::endl;
}