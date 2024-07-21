/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:27:02 by tponnusa          #+#    #+#             */
/*   Updated: 2024/03/13 14:57:43 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	index = 0;
}

void PhoneBook::add_to_phonebook(std::string f_name, std::string l_name, std::string n_name, std::string ph_no, std::string secret)
{
	if (index >= 8)
	{
		std::cout << "\033[38;2;255;0;0m" << "Phonebook is Full.Replacing Oldest contact..." << "\033[0m" << std::endl;
		this->contacts[index % 8].set_contact(f_name, l_name, n_name, ph_no, secret);
	}
	else
		this->contacts[index].set_contact(f_name, l_name, n_name, ph_no, secret);
	index++;
}

void PhoneBook::show_phonebook()
{
	int current_index;
	std::string	s_index;

	int i = 0;
	if (index == 0)
		std::cout << "\033[38;2;255;0;0m" << "Phonebook is Empty.Please add a contact to search" << "\033[0m" << std::endl;
	else
	{
		std::cout << "|*******************************************|" << std::endl;
		std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
		std::cout << "|**********|**********|**********|**********|" << std::endl;
		current_index = index;
		if (index >= 8)
			current_index = 8;
    	while (i < current_index)
    	{
        	contacts[i].display_all(i);
        	i++;
    	}
		while (1)
            {
                std::cout <<  "Please select index to display: (Type EXIT to quit search) "<< std::endl;
				std::cin >> s_index;
				if (std::cin.eof())
            		std::exit(0);
                if(!s_index.empty())
                {
                    char ch = s_index.back();
                    if(s_index.length() == 1 && isdigit(ch) && std::stoi(s_index) < current_index)
                        search_contact(stoi(s_index));
					else if (s_index.compare("EXIT") == 0)
						break;
					else
						std::cout << "\033[38;2;255;0;0m" << "Wrong Index value. Select from displayed info" << "\033[0m" << std::endl;
                }
            }
	}
}

void PhoneBook::search_contact(int s_index)
{
    contacts[s_index].display_contact(s_index);
}