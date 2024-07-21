/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:56:38 by tponnusa          #+#    #+#             */
/*   Updated: 2024/03/22 18:26:36 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string		name;

	public:
		DiamondTrap();
		DiamondTrap(std::string arg_name);
		~DiamondTrap();
		DiamondTrap(DiamondTrap const&);
		DiamondTrap&	operator=(DiamondTrap const&);

		void			display(std::ostream& stream) const;
		void 			attack(const std::string &target);
		void			whoAmI() const;
};

std::ostream&	operator<<(std::ostream &os, DiamondTrap const& obj);

#endif