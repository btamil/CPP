/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:24:38 by tponnusa          #+#    #+#             */
/*   Updated: 2024/03/20 14:58:30 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{}

Harl::~Harl()
{}

void Harl::debug( void )
{
    std::cout << "I love having extra bacon for my "
    << "7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money. "
    << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
    
void Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free."
    << " I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    void	(Harl::*funcPtr[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
    std::string complaints[4] = {"debug", "info", "warning", "error"};
    for (int i = 0;i < 4;i++)
    {
        if (complaints[i] == level)
        {
           (this->*funcPtr[i])();
        }
    }
}



