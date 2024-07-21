/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:58:47 by tponnusa          #+#    #+#             */
/*   Updated: 2024/05/13 14:58:47 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& argTarget) : AForm("RobotomyRequestForm", 72, 45), target(argTarget) 
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& srcObj) : AForm(srcObj), target(srcObj.target)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm&    RobotomyRequestForm::operator=(RobotomyRequestForm& srcObj)
{
    (void)srcObj;
    return *this;
}

const std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->target);
}

void    RobotomyRequestForm::execute(const Bureaucrat& executor) const 
{
    if (this->getIsSignedBool() == false)
        throw AForm::NotSignedException();
    if (executor.getGrade() > this->getExecGrade() )
        throw AForm::GradeTooLowException();
    std::cout << "Rat-a-tat-ta!!!! Rat-a-tat-tat!!!!" << std::endl;
    
    srand(time(0));
    // Check if the robotomy was successful (50% chance)
    if (std::rand() % 2 == 0)
        std::cout << target << " has been robotomized successfully!" << std::endl;
    else 
        std::cout << "Robotomy on " << target << " failed." << std::endl; 
}

/**
 * Initialize the random number generator with a starting value. 
 * If you don't seed the random number generator, it will produce the same sequence of numbers every time the program is run.
 * like srand(time(NULL));
 * rand() - produces non-negative integers in the range from 0 to RAND_MAX, which is a constant defined in <cstdlib>
*/
