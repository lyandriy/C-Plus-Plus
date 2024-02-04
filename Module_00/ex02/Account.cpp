/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyandriy <lyandriy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:56:30 by lyandriy          #+#    #+#             */
/*   Updated: 2024/02/03 17:41:02 by lyandriy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit): _amount(initial_deposit), _nbDeposits(0),
	_nbWithdrawals(0), _accountIndex(0)
{
	_displayTimestamp();
	std::cout << " index:" << this->_nbAccounts
			<< ";amount:" << this->_amount
			<< ";created"
			<< std::endl;
	_totalAmount += initial_deposit;
	_accountIndex = _nbAccounts;
	_nbAccounts++;
}

Account::~Account()
{
	_nbAccounts--;
	_totalAmount -= this->_amount;
	_totalNbDeposits -= this->_nbDeposits;
	_totalNbWithdrawals -= this->_nbWithdrawals;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";closed"
			<< std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t	time;
	std::tm*	_time;

	time = std::time(0);
	_time = std::localtime(&time);
	std::cout << "[" << std::put_time(_time, "%Y%m%d_%H%M%S") << "]";
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts
			<< ";total:" << _totalAmount
			<< ";depoosits:" << _totalNbDeposits
			<< ";withdrawals:" << _totalNbWithdrawals
			<< std::endl;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";depoosits:" << this->_nbDeposits
			<< ";withdrawals:" << this->_nbWithdrawals
			<< std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
			<< ";p_amount:" << this->_amount
			<< ";depoosit:" << deposit;
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits += _nbDeposits;
	_totalAmount += deposit;
	std::cout << ";amount:" << this->_amount
			<< ";nb_deposits:" << this->_nbDeposits
			<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex
			<< ";p_amount:" << this->_amount;
	_amount -= withdrawal;
	if (_amount < 0)
	{
		_amount += withdrawal;
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	_nbWithdrawals++;
	_totalNbWithdrawals += _nbWithdrawals;
	_totalAmount -= withdrawal;
	std::cout << ";withdrawal:" << withdrawal
			<< ";amount:" << this->_amount
			<< ";nb_withdrawals:" << this->_nbWithdrawals
			<< std::endl;
	return (true);
}
