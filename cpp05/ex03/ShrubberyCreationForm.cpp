/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:00:58 by tponnusa          #+#    #+#             */
/*   Updated: 2024/05/13 15:00:58 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& argTarget) : AForm("ShrubberyCreationForm", 145, 137), target(argTarget)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& srcObj) : AForm(srcObj), target(srcObj.target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& srcObj)
{
    (void)srcObj;
    return *this;
}

const std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->target);
}

void    ShrubberyCreationForm::execute(const Bureaucrat& executor) const 
{
    if (this->getIsSignedBool() == false )
        throw AForm::NotSignedException();
    else if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();

    std::string fileName = this->target + "_shrubbery";
    std::ofstream outfile(fileName.c_str());

    // Check if the file was opened successfully
    if (!outfile.is_open())
    {
        std::cerr << "Error opening file." << std::endl;
        return ;
    }
       
    outfile << "                             * " << std::endl;
    outfile << "                            ^^^ " << std::endl;
    outfile << "                          ^^^^^^^ " << std::endl;
    outfile << "                        ^^^^^^^^^^^ " << std::endl;
    outfile << "                      ^^^^^^^^^^^^^^^ " << std::endl;
    outfile << "                          ^^^^^^^ " << std::endl;
    outfile << "                        ^^^^^^^^^^^ " << std::endl;
    outfile << "                      ^^^^^^^^^^^^^^^ " << std::endl;
    outfile << "                   ^^^^^^^^^^^^^^^^^^^^^^ " << std::endl;
    outfile << "                          ^^^^^^^ " << std::endl;
    outfile << "                        ^^^^^^^^^^^ " << std::endl;
    outfile << "                    ^^^^^^^^^^^^^^^^^^^^ " << std::endl;
    outfile << "                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^ " << std::endl;
    outfile << "                          ^^^^^^^ " << std::endl;
    outfile << "                        ^^^^^^^^^^^ " << std::endl;
    outfile << "                    ^^^^^^^^^^^^^^^^^^^^ " << std::endl;
    outfile << "                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^ " << std::endl;
    outfile << "            ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ " << std::endl;
    outfile << "                        |||||||||||| " << std::endl;
    outfile << "                        |||||||||||| " << std::endl;
    outfile << "                        |||||||||||| " << std::endl;
    outfile.close();
}