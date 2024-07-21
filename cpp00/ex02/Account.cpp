
#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

//Initialize private variables
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(void)
{}

Account::Account(int initial_deposit)
{
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	//finding total amount
	Account::_totalAmount += this->_amount;	
	Account::_nbAccounts++;

//displaying when account is created.
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" << "amount:"
	<< this->checkAmount() << ";" << "created" << std::endl;
}

//destructor also prints value
Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" << "amount:"
	<< this->checkAmount() << ";" << "closed" << std::endl;
}

// get value of the total number of accounts
int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

// get value of the total amoount of money of all accounts
int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

// get value of the total number of deposits
int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

// get value of the total number of withdrawals
int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

//display all the account information
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout <<
	"accounts:" << getNbAccounts() << ";" <<
	"total:" << getTotalAmount() << ";" <<
	"deposits:" << getNbDeposits() << ";" <<
	"withdrawals:" << getNbWithdrawals() <<
	std::endl;
}

// make a deposit
void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout <<
	"index:" << this->_accountIndex << ";" <<
	"p_amount:" << this->checkAmount() << ";" <<
	"deposit:" << deposit << ";";
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	std::cout <<
	"amount:" << this->checkAmount() << ";" <<
	"nb_deposits:" << this->_nbDeposits <<
	std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout <<
	"index:" << this->_accountIndex << ";" <<
	"p_amount:" << this->checkAmount() << ";";
	if (this->checkAmount() < withdrawal)
	{
		std::cout <<
		"withdrawal:refused" <<
		std::endl;
		return (false);
	}
	else
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		std::cout <<
		"withdrawal:" << withdrawal << ";" <<
		"amount:" << this->checkAmount() << ";" <<
		"nb_withdrawals:" << this->_nbWithdrawals <<
		std::endl;
		return (true);
	}
}

// displays the whole status of an account
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout <<
	"index:" << this->_accountIndex << ";" <<
	"amount:" << this->checkAmount() << ";" <<
	"deposits:" << this->_nbDeposits << ";" <<
	"withdrawals:" << this->_nbWithdrawals <<
	std::endl;
}

// returns the amount of money of the account
int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

// displays the timestamp in the correct format
void	Account::_displayTimestamp( void )
{
	time_t current_time = std::time(NULL);
	struct tm local_time = *std::localtime(&current_time);
	
	std::cout << "[" << local_time.tm_year + 1900 <<
	std::setfill('0') << std::setw(2) << local_time.tm_mon + 1 <<
	std::setfill('0') << std::setw(2) << local_time.tm_mday << "_" <<
	std::setfill('0') << std::setw(2) << local_time.tm_hour <<
	std::setfill('0') << std::setw(2) << local_time.tm_min <<
	std::setfill('0') << std::setw(2) << local_time.tm_sec <<
	"] "; 
}
