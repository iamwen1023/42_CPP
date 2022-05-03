#include <iostream>
#include "Account.hpp"
#include <ctime>
#include <iomanip>


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit):_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    this->_accountIndex = Account::_nbAccounts;
    Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex;
    std::cout << ";amount:" << this->_amount << ";created\n";
    return ;
}
Account::~Account()
{
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex;
    std::cout << ";amount:" << this->_amount << ";closed\n";
    return ;
}

void Account::_displayTimestamp(void)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);

    std::cout << "[" << 1900 + ltm->tm_year;
    std::cout << std::setw(2) << std::setfill('0') << 1 + ltm->tm_mon;
    std::cout << std::setw(2) << std::setfill('0') << ltm->tm_mday << "_";
    std::cout << std::setw(2) << std::setfill('0') << ltm->tm_hour;
    std::cout << std::setw(2) << std::setfill('0') << ltm->tm_min;
    std::cout << std::setw(2) << std::setfill('0') << ltm->tm_sec << "]";
}

int Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
    Account::_displayTimestamp();
    std::cout << " accounts:" << Account::getNbAccounts()
    << ";total:" << Account::getTotalAmount()
    << ";deposits:" << Account::getNbDeposits()
    << ";withdrawals:" << Account::getNbWithdrawals() 
    << "\n";
}

void	Account::makeDeposit( int deposit )
{
    int p_amount(this->_amount);

    this->_amount += deposit;
    this->_nbDeposits++;
    Account::_totalNbDeposits++;
    Account::_totalAmount += deposit;
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex  
    << ";p_amount:" << p_amount
    << ";deposit:" << deposit
    << ";amount:" << this->_amount
    << ";nb_deposits:" << this->_nbDeposits 
    << "\n";
}

bool	Account::makeWithdrawal( int withdrawal )
{
    int p_amount(this->_amount);
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex  
        << ";p_amount:" << p_amount;
    if(this->_amount < withdrawal)
    {
        std::cout<< ";withdrawal:refused\n";
        return false;
    }
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals++;
    std::cout << ";withdrawal:" << withdrawal
        << ";amount:" << this->_amount
        << ";nb_withdrawals:" << this->_nbWithdrawals
        << "\n";
    return true;
}

int		Account::checkAmount( void ) const
{
    return (this->_amount);
}
void	Account::displayStatus( void ) const
{
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex  
    << ";amount:" << this->_amount
    << ";deposits:" << this->_nbDeposits
    << ";withdrawals:" << this->_nbWithdrawals 
    << "\n";
}
