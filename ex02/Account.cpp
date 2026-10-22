#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <string>


// Constructor
Account::Account(int initial_deposit)
{
	_displayTimestamp();
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;

	_nbAccounts++;
	_totalAmount += initial_deposit;
}

// destructor

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount" << _amount << ";";
	std::cout << "closed" << std::endl;

}

// private variable

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Getter

int Account::getNbAccounts(void) { return _nbAccounts; }

int Account::getNbDeposits(void) { return _totalNbDeposits; }

int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

int Account::getTotalAmount(void) { return _totalAmount; }

int Account::checkAmount(void) const { return _amount; }



// public method

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	_amount += deposit;
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}
bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	if (checkAmount() >= withdrawal)
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << _amount << ";";
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
		return true;
	}
	std::cout << "withdrawal:refused" << std::endl;
	return false;
}


// public method to show status

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "index:" << _nbAccounts << ";"
	<< "total:" << _totalAmount << ";"
	<< "deposits:" << _totalNbDeposits << ";"
	<< "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}


// Private method to display the date in [19920104_091532]

void Account::_displayTimestamp(void)
{
	std::time_t now = std::time(NULL);
	std::tm* t = std::localtime(&now);
	std::string str;
	char buf[32];

	std::strftime(buf, 32, "%Y%m%d_%H%M%S", t);
	str = buf;
	std::cout << "[" << str << "] ";
}
