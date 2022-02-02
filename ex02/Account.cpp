/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:23:45 by hbaddrul          #+#    #+#             */
/*   Updated: 2022/02/02 13:20:54 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>

#include "Account.hpp"

using std::cout;
using std::endl;

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) {
    return _nbAccounts;
}

int Account::getTotalAmount(void) {
    return _totalAmount;
}

int Account::getNbDeposits(void) {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    cout << "accounts:" << _nbAccounts << ";";
    cout << "total:" << _totalAmount << ";";
    cout << "deposits:" << _totalNbDeposits << ";";
    cout << "withdrawals:" << _totalNbWithdrawals << endl;
}

Account::Account(int initial_deposit) {
    _accountIndex = _nbAccounts++;
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    cout << "index:" << _accountIndex << ";";
    cout << "amount:" << _amount << ";";
    cout << "created" << endl;
}

Account::~Account(void) {
    _displayTimestamp();
    cout << "index:" << _accountIndex << ";";
    cout << "amount:" << _amount << ";";
    cout << "closed" << endl;
}

void Account::makeDeposit(int deposit) {
    _totalAmount += deposit;
    ++_totalNbDeposits;
    _amount += deposit;
    ++_nbDeposits;
    _displayTimestamp();
    cout << "index:" << _accountIndex << ";";
    cout << "p_amount:" << _amount - deposit << ";";
    cout << "deposit:" << deposit << ";";
    cout << "amount:" << _amount << ";";
    cout << "nb_deposits:" << _nbDeposits << endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    bool success = withdrawal <= _amount;
    _displayTimestamp();

    if (success) {
        _totalAmount -= withdrawal;
        ++_totalNbWithdrawals;
        _amount -= withdrawal;
        ++_nbWithdrawals;
        cout << "index:" << _accountIndex << ";";
        cout << "p_amount:" << _amount + withdrawal << ";";
        cout << "withdrawal:" << withdrawal << ";";
        cout << "amount:" << _amount << ";";
        cout << "nb_withdrawals:" << _nbDeposits << endl;
    } else {
        cout << "index:" << _accountIndex << ";";
        cout << "p_amount:" << _amount << ";";
        cout << "withdrawal:refused" << endl;
    }

    return success;
}

int Account::checkAmount(void) const {
    return _amount;
}

void Account::displayStatus(void) const {
    _displayTimestamp();
    cout << "index:" << _accountIndex << ";";
    cout << "amount:" << _amount << ";";
    cout << "deposits:" << _nbDeposits << ";";
    cout << "withdrawals:" << _nbWithdrawals << endl;
}

void Account::_displayTimestamp(void) {
    char ts[18];
    time_t now;
    struct tm tm;

    time(&now);
    localtime_r(&now, &tm);
    strftime(ts, sizeof(ts), "[%Y%m%d_%H%M%S]", &tm);
    cout << ts << " ";
}
