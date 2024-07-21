/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:00:39 by tponnusa          #+#    #+#             */
/*   Updated: 2024/05/13 15:00:39 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    std::string target;

    PresidentialPardonForm();

public:
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& srcObj);
    PresidentialPardonForm& operator=( const PresidentialPardonForm& srcObj);
    ~PresidentialPardonForm();

    const	std::string	getTarget(void) const;
    
    void execute(const Bureaucrat& executor) const;
};

#endif