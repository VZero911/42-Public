#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    this->_accountIndex = this->_nbAccounts++;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_totalAmount += initial_deposit;
    
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account(void)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

int Account::getNbAccounts(void)
{
    return Account::_nbAccounts;
}

int Account::getTotalAmount(void)
{
    return Account::_totalAmount;
}

int Account::getNbDeposits(void)
{
    return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts 
              << ";total:" << Account::_totalAmount 
              << ";deposits:" << Account::_totalNbDeposits 
              << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
    int p_amount = this->_amount;
    this->_amount += deposit;
    this->_nbDeposits++;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;
    
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex 
              << ";p_amount:" << p_amount 
              << ";deposit:" << deposit 
              << ";amount:" << this->_amount 
              << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    int p_amount = this->_amount;
    
    if (withdrawal > this->_amount)
    {
        Account::_displayTimestamp();
        std::cout << "index:" << this->_accountIndex 
                  << ";p_amount:" << p_amount 
                  << ";withdrawal:refused" << std::endl;
        return false;
    }
    
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals++;
    
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex 
              << ";p_amount:" << p_amount 
              << ";withdrawal:" << withdrawal 
              << ";amount:" << this->_amount 
              << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    
    return true;
}

int Account::checkAmount(void) const
{
    return this->_amount;
}

void Account::displayStatus(void) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex 
              << ";amount:" << this->_amount 
              << ";deposits:" << this->_nbDeposits 
              << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
    std::time_t t = std::time(NULL);
    std::tm* now = std::localtime(&t);
    
    std::cout << "[" << (now->tm_year + 1900)
              << std::setfill('0') << std::setw(2) << (now->tm_mon + 1)
              << std::setfill('0') << std::setw(2) << now->tm_mday
              << "_"
              << std::setfill('0') << std::setw(2) << now->tm_hour
              << std::setfill('0') << std::setw(2) << now->tm_min
              << std::setfill('0') << std::setw(2) << now->tm_sec
              << "] ";
}