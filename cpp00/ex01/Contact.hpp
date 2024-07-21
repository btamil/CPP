/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:47:46 by tponnusa          #+#    #+#             */
/*   Updated: 2024/03/07 13:55:36 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
#include <iomanip>
#include <string>

class Contact {
    private:
        std::string index;
        std::string first_name;
        std::string last_name;
        std::string nick_name;
        std::string phone_no;
        std::string dark_secret;
    public:
        void set_contact(std::string f_name, std::string l_name, std::string n_name, std::string ph_no, std::string dark_secret);
        void display_all(int index);
        void display_contact(int index);
        
};

#endif