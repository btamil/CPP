/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:34:09 by tponnusa          #+#    #+#             */
/*   Updated: 2024/03/07 14:15:12 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string get_prompt_value()
{
    std::string input;
    
    std::cin >> input;
    if (std::cin.eof())
        std::exit(0);
    while (input.empty() || (input.length() == 0))
    {
        std::cout << "A field can't have an empty value. Please provide value" << std::endl;
        std::cin >> input;
        if (std::cin.eof())
            std::exit(0);
    }
    return (input);
}

void get_input(PhoneBook& entry)
{
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string phone_no;
    std::string secret;

    std::cout << "Enter your Name:" << std::endl;
    first_name = get_prompt_value();
    std::cout << "Enter your Last name:" << std::endl;
    last_name = get_prompt_value();
    std::cout << "Enter your Nick name:" << std::endl;
    nick_name = get_prompt_value();
    std::cout << "Enter your phone no:" << std::endl;
    phone_no = get_prompt_value();
    std::cout << "Enter your Darkest secret:" << std::endl;
    secret = get_prompt_value();
    entry.add_to_phonebook(first_name, last_name, nick_name, phone_no, secret);
    std::cout << "\033[38;2;0;255;0m" << "Contact added Successfully" << "\033[0m" << std::endl;
}

int main(void)
{
    PhoneBook entry;
    std::string option;
    
    while (1)
    {
        std::cout << "\033[38;2;0;0;255m" << "Welcome to Crappy Awesome Phonebook!!!"  << "\033[0m" << std::endl;
        std::cout << "Try the following options by entering command mentioned" << std::endl;
        std::cout << "\033[38;2;0;0;255m" << "ADD" << std::endl;
        std::cout << "SEARCH" << std::endl;
        std::cout << "EXIT" << "\033[0m" << std::endl;
        std::cin >> option;
        if (option.compare("ADD") == 0)
            get_input(entry);
        else if (option.compare("SEARCH") == 0)
            entry.show_phonebook();
        else if (option.compare("EXIT") == 0 || std::cin.eof())
            std::exit(0);
        else
        {
            std::cout <<"Invalid input. Please enter a valid command." << std::endl;
            std::cin.clear();
        }           
    }
}
