#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
	private:
		std::string name;
		unsigned int hit_pts;
		unsigned int engy_pts;
		unsigned int damage;
		static unsigned int const	defaultHitPoints = 10;
	public:
		ClapTrap();
		ClapTrap(std::string arg_name);
		ClapTrap(ClapTrap const& obj);
		ClapTrap& operator=(ClapTrap const& obj);
		~ClapTrap();

		std::string 	getName(void) const;
		unsigned int	getHitPoints(void) const;
		unsigned int	getEnergyPoints(void) const;
		unsigned int	getAttackDamage(void) const;
		
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif