/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:00:16 by tponnusa          #+#    #+#             */
/*   Updated: 2024/05/13 15:00:16 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {

public:
    Intern();
    Intern( const Intern& srcObj);
	Intern& operator=(const Intern& srcObj);
    ~Intern();

    AForm*   makeForm(std::string name, std::string target);
};

#endif