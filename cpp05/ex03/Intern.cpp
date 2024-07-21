/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:00:10 by tponnusa          #+#    #+#             */
/*   Updated: 2024/05/13 15:00:10 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern& srcObj)
{
    *this = srcObj;
}

Intern::~Intern()
{}

Intern& Intern::operator=(const Intern& srcObj)
{
    (void) srcObj;
    return (*this);
}

AForm*   Intern::makeForm(std::string name, std::string target)
{

    std::string formNames[] = {
		"shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    AForm*    forms[] = {
		new ShrubberyCreationForm(target),
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target)
    };
    for (int i = 0; i < 3; i++)
    {
        if (name == formNames[i]) 
        {
            std::cout << "Intern creates " << name << std::endl;
            for(int j = 0; j < 3; j++)
            {
                if (j != i)
                    delete forms[j];    
            }
            return forms[i];
        }
    }
    for(int j = 0; j < 3; j++)
        delete forms[j];
    std::cout << "Form " << name << " is not available to create." << std::endl;
    return (NULL);
}