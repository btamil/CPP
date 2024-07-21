/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:58:35 by tponnusa          #+#    #+#             */
/*   Updated: 2024/05/13 14:58:35 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& argTarget) : AForm("PresidentialPardonForm", 25, 5), target(argTarget)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& srcObj) : AForm(srcObj), target(srcObj.target)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& srcObj) {
    (void)srcObj;
    return *this;
}

const std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->target);
}


void    PresidentialPardonForm::execute(const Bureaucrat& executor) const 
{
    if (this->getIsSignedBool() == false )
        throw AForm::NotSignedException();
    if ( executor.getGrade() > this->getExecGrade() )
        throw AForm::GradeTooLowException();
    else {
        std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    }
}