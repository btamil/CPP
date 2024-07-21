/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:01:04 by tponnusa          #+#    #+#             */
/*   Updated: 2024/05/13 15:01:04 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {

private:
    const std::string   target;

    ShrubberyCreationForm();

public:
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& srcObj);
    ShrubberyCreationForm&  operator=(ShrubberyCreationForm& srcObj);
    ~ShrubberyCreationForm();

    const	std::string	getTarget(void) const;

    void        execute(const Bureaucrat& executor) const;

};

#endif