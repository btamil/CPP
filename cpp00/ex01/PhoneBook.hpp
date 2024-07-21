/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:27:49 by tponnusa          #+#    #+#             */
/*   Updated: 2024/03/07 13:55:58 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP

#define PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook {
    private:
        Contact contacts[8];
        int     index;
    public:
        PhoneBook(void);
    void search_contact(int index);
    void add_to_phonebook(
            std::string f_name, std::string l_name, std::string n_name, std::string ph_no, std::string secret);
    void show_phonebook();
};

#endif




