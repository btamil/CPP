#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : 
							name("Original"), 
							hit_pts(CLAPTRAP_DEFAULT_HIT_POINTS), 
							engy_pts(CLAPTRAP_DEFAULT_ENERGY_POINTS), 
							damage(CLAPTRAP_DEFAULT_ATTACK_DAMAGE)
{
	std::cout << "ClapTrap " << this->name << " Default Constrctor called" << std::endl;
}

ClapTrap::ClapTrap(std::string arg_name) : 
											name(arg_name),
											hit_pts(CLAPTRAP_DEFAULT_HIT_POINTS), 
											engy_pts(CLAPTRAP_DEFAULT_ENERGY_POINTS), 
											damage(CLAPTRAP_DEFAULT_ATTACK_DAMAGE)
{
	std::cout << "ClapTrap " << this->name << " Parameter Constrctor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& obj)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	operator=(obj);
}

ClapTrap&	ClapTrap::operator=(ClapTrap const& obj)
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	this->name = obj.name;
	this->hit_pts = obj.hit_pts;
	this->engy_pts = obj.engy_pts;
	this->damage = obj.damage;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->name << " is destroyed" << std::endl;
}

std::string	ClapTrap::getName(void) const {
	return (this->name);
}

unsigned int	ClapTrap::getHitPoints(void) const {
	return (this->hit_pts);
}

unsigned int	ClapTrap::getEnergyPoints(void) const {
	return (this->engy_pts);
}

unsigned int	ClapTrap::getAttackDamage(void) const {
	return (this->damage);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->hit_pts > 0 && this-> engy_pts > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target
		 << ", causing " << this->damage << " points of damage!" << std::endl;
		this->hit_pts--;
		this->engy_pts--;
	}
	else if (this-> engy_pts == 0)
		std::cout << "ClapTrap " << this->name << " can not attack " << target << ", because no energy points" << std::endl;
	std::cout << "ClapTrap " << name << " has " << this->engy_pts << " energy points left now." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= 2147483648)
	{
		std::cout << "ClapTrap can't take negative values" << std::endl;
		return;
	}
	if (this->hit_pts == 0) {
		std::cout << "ClapTrap " << this->name << " can't take anymore damage" << std::endl;
		return;
	}
	if (amount > this->hit_pts)
		this->hit_pts = 0;
	else
		this->hit_pts -= amount;
	std::cout << "ClapTrap " << this->name << " takes " << amount << " damage!!"
		<< " and has " << this->hit_pts << " hit points now." << std::endl;
	
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (amount >= 2147483648)
	{
		std::cout << "ClapTrap can't take negative values" << std::endl;
		return;
	}
	if (this->hit_pts == 0) {
		std::cout <<"ClapTrap " << this->name
			<< " can't repair itself: it is too severely damaged." << std::endl;
		return ;
	}
	if (this->engy_pts == 0) {
		std::cout << "ClapTrap " << this->name << "has no ENERGY to repair itself!!" << std::endl;
		return;
	}
	if (this->hit_pts == CLAPTRAP_DEFAULT_HIT_POINTS)
	{
		std::cout << this->name << " is fully operational! No need of repairing it." << std::endl;
		return;
	}
	if (this->hit_pts + amount >= CLAPTRAP_DEFAULT_HIT_POINTS)
	{
		this->hit_pts = CLAPTRAP_DEFAULT_HIT_POINTS;
		std::cout << this->name << " is healed completely!\n";
		return;
	}
	else
		this->hit_pts += amount;
	std::cout << this->name << " has " << this->hit_pts << " hit points now." << std::endl;
}
