/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:00:52 by tponnusa          #+#    #+#             */
/*   Updated: 2024/05/13 15:00:52 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <ctime>
#include <cstdlib> 

class RobotomyRequestForm : public AForm
{
private:
    const std::string   target;

    RobotomyRequestForm();

public:
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& srcObj);
    RobotomyRequestForm &operator=(RobotomyRequestForm& srcObj);
    ~RobotomyRequestForm();

    const	std::string	getTarget(void) const;

    void	execute(const Bureaucrat& executor) const;
};

#endif