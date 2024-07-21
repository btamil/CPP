/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:56:38 by tponnusa          #+#    #+#             */
/*   Updated: 2024/03/27 17:34:46 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

# define SCAVTRAP_DEFAULT_HIT_POINTS 100
# define SCAVTRAP_DEFAULT_ENERGY_POINTS 50
# define SCAVTRAP_DEFAULT_ATTACK_DAMAGE 20

class ScavTrap : virtual public ClapTrap {
    public:
        ScavTrap();
        ScavTrap(std::string arg_name);
        ScavTrap(ScavTrap const& obj);
        ScavTrap& operator=(ScavTrap const& obj);
        ~ScavTrap();

        void attack(const std::string & target);
        void guardGate( void );
};

#endif