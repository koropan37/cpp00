#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {

}

Account::Account(void) {

}

Account::~Account(void) {

}

int Account::getNbAccounts(void) { return _nbAccounts; }
int Account::getTotalAmount(void) { return _totalAmount; }
int Account::getNbDeposits(void) { return _totalNbDeposits; }
int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

void Account::displayAccountsInfos(void) {
	_displayTimestamp();
}

void Account::makeDeposit(int deposit) {

}

bool Account::makeWithdrawal(int withdrawal) {

}

int Account::checkAmount(void)const { return _amount; }

void Account::displayStatus(void)const {

}

void Account::_displayTimestamp(void) {
	time_t time = std::time(NULL);
	std::tm tm = *std::localtime(&time);
	char timestamp[32];

	std::strftime(timestamp, sizeof(timestamp), "[%Y%m%d_%H%M%S] ", &tm);
	std::cout << timestamp;
}
