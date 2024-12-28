	#include "Account.hpp"
    #include <ctime>
    #include <iostream>

    int Account::_nbAccounts = 0;
    int Account::_totalAmount = 0;
    int Account::_totalNbDeposits = 0;
    int Account::_totalNbWithdrawals = 0;

    int	Account::getNbAccounts( void )
    {
            return (Account::_nbAccounts);
    };
	int	Account::getTotalAmount( void )
    {
        return (Account::_totalAmount);
    };
	int	Account::getNbDeposits( void )
    {
        return(Account::_totalNbDeposits);
    };
	int	Account::getNbWithdrawals( void )
    {
        return(Account::_totalNbWithdrawals);
    };
	void    Account::displayAccountsInfos( void )
    {
        _displayTimestamp();
        std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
    };

    Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) 
    {
        Account::_nbAccounts++;
        Account::_totalAmount += initial_deposit;
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
    }
    
    Account::~Account( void )
    {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
    };

	void	Account::makeDeposit( int deposit )
    {
    _displayTimestamp();
    _amount += deposit;
    _nbDeposits++;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount - deposit << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
    };

	bool	Account::makeWithdrawal( int withdrawal )
    {
        _displayTimestamp();
        if (_amount < withdrawal)
        {
            std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
            return false;
        }
        _amount -= withdrawal;
        _nbWithdrawals++;
        Account::_totalAmount -= withdrawal;
        Account::_totalNbWithdrawals++;
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount + withdrawal << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        return true;
    };

	int		Account::checkAmount( void ) const
    {
        return _amount;
    };

	void	Account::displayStatus( void ) const
    {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
    };

    void Account::_displayTimestamp(void) 
    {
    std::time_t now = std::time(0);
    std::tm *ltm = std::localtime(&now);
    std::cout << "[" << 1900 + ltm->tm_year
              << (ltm->tm_mon < 9 ? "0" : "") << 1 + ltm->tm_mon
              << (ltm->tm_mday < 10 ? "0" : "") << ltm->tm_mday << "_"
              << (ltm->tm_hour < 10 ? "0" : "") << ltm->tm_hour
              << (ltm->tm_min < 10 ? "0" : "") << ltm->tm_min
              << (ltm->tm_sec < 10 ? "0" : "") << ltm->tm_sec << "] ";
    }