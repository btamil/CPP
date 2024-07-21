/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:24:42 by tponnusa          #+#    #+#             */
/*   Updated: 2024/03/20 14:52:44 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP
#include <iostream>

class Harl {
    typedef void (Harl::*functionPointer)(void);
    private:
        void debug( void );
        void info( void );
        void warning( void ); 
        void error( void );
    public:
        Harl();
        ~Harl();
        void    complain( std::string level );
};

#endif