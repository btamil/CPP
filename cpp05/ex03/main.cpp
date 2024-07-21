/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:00:21 by tponnusa          #+#    #+#             */
/*   Updated: 2024/05/13 15:00:21 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
    {
        Intern  someRandomIntern;
        AForm*   rrf1; 
        AForm*   rrf2;
        AForm*   rrf3;
        AForm*   rrf4;

        rrf1 = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << rrf1;
        rrf2 = someRandomIntern.makeForm("shrubbery creation", "Bender");
        rrf3 = someRandomIntern.makeForm("presidential pardon", "Bender");
        rrf4 = someRandomIntern.makeForm("Feedback", "Bender");

        delete rrf1;
        delete rrf2;
        delete rrf3;
        delete rrf4;
    }

    return (0);
}