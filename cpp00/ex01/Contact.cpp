/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:53:53 by tponnusa          #+#    #+#             */
/*   Updated: 2024/03/07 13:53:54 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::set_contact(std::string f_name, std::string l_name, std::string n_name, std::string ph_no, std::string secret)
{
	this->first_name = f_name;
	this->last_name = l_name;
	this->nick_name = n_name;
	this->phone_no = ph_no;
	this->dark_secret = secret;
}

void	Contact::display_all(int index)
{
    std::cout << "|" << std::setw(10) << index;
	if (first_name.length() > 10)
        std::cout << "|" << first_name.substr(0, 9) << ".";
	else
		std::cout << "|" << std::setw(10) << first_name;
	if (last_name.length() > 10)
        std::cout << "|" << last_name.substr(0, 9) << ".";
	else
		std::cout << "|" << std::setw(10) << last_name;
	if (nick_name.length() > 10)
        std::cout << "|" << nick_name.substr(0, 9) << ".";
	else
		std::cout << "|" << std::setw(10) << nick_name;	
    std::cout << "|" << std::endl;
    std::cout << "*********************************************" << std::endl;
}

void Contact::display_contact(int index)
{
    std::cout << "index : " << index << std::endl;
    std::cout << "first name : " << first_name << std::endl;
    std::cout << "last name : " << last_name << std::endl;
    std::cout << "nick name : " << nick_name << std::endl;
    std::cout << "secret : " << phone_no << std::endl;
    std::cout << "phone : " << dark_secret << std::endl;
}