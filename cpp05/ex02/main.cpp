/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:58:18 by tponnusa          #+#    #+#             */
/*   Updated: 2024/05/13 14:58:18 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{

    try 
    {
        Bureaucrat bureaucrat("Person", 2);
        ShrubberyCreationForm form1("Home");
         
        std::cout << std::endl;
        bureaucrat.signForm(form1);
        bureaucrat.signForm(form1);
        bureaucrat.executeForm(form1);

        std::cout << std::endl;
        RobotomyRequestForm form2("Robotomy");
        bureaucrat.signForm(form2);
        bureaucrat.executeForm(form2);
        std::cout << std::endl;

        PresidentialPardonForm form3("President");

        bureaucrat.signForm(form3);
        bureaucrat.executeForm(form3);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}