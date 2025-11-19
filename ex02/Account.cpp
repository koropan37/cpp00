#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//[19920104_091532] index:0;amount:42;created
Account::Account(int initial_deposit)
	:_accountIndex(_nbAccounts++),
	 _amount(initial_deposit),
	 _nbDeposits(0),
	 _nbWithdrawals(0)
{
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout
		<< "index:"  << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "created" << std::endl;
}

//今回使われていない
Account::Account(void)
	:_accountIndex(_nbAccounts++),
	 _amount(0),
	 _nbDeposits(0),
	 _nbWithdrawals(0)
{
	_displayTimestamp();
	std::cout
		<< "index:"  << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "created" << std::endl;
}
//関数オーバーロード
//同じ名前の関数を、引数や戻り値を変えることで複数定義できる


//[19920104_091532] index:0;amount:47;closed
Account::~Account(void) {
	_displayTimestamp();
	std::cout
		<< "index:"  << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "closed"  << std::endl;
}

int Account::getNbAccounts(void) { return _nbAccounts; }
int Account::getTotalAmount(void) { return _totalAmount; }
int Account::getNbDeposits(void) { return _totalNbDeposits; }
int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

int Account::checkAmount(void)const { return _amount; }

//[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout
		<< "accounts:" 	  << getNbAccounts() 	<< ";"
		<< "total:"	 	  << getTotalAmount() 	<< ";"
		<< "deposits:" 	  << getNbDeposits() 	<< ";"
		<< "withdrawals:" << getNbWithdrawals() << std::endl;
}

//[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void Account::makeDeposit(int deposit) {
	int p_amount = _amount;

	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout
		<< "index:" 	  << _accountIndex 	  << ";"
		<< "p_amount:" 	  << p_amount 	  	  << ";"
		<< "deposit:"      << deposit         << ";"
		<< "amount:"	  << _amount		  << ";"
		<< "nb_deposits:" << _nbDeposits	  << std::endl;
}

//if   [19920104_091532] index:0;p_amount:47;withdrawal:refused
//else [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
bool Account::makeWithdrawal(int withdrawal) {
	int p_amount = _amount;

	_displayTimestamp();
	if( _amount < withdrawal) {
		std::cout
		<< "index:"   << _accountIndex << ";"
		<< "p_amount:" << p_amount	   << ";"
		<< "withdrawal:refused"		   << std::endl;
		return false;
	}
	else {
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout
		<< "index:" 		 << _accountIndex	<< ";"
		<< "p_amount:" 		 << p_amount 	 	<< ";"
		<< "withdrawal:" 	 << withdrawal 		<< ";"
		<< "amount:" 		 << _amount 	   	<< ";"
		<< "nb_withdrawals:" << _nbWithdrawals 	<< std::endl;
	}
	return true;
}

//[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
void Account::displayStatus(void)const {
	_displayTimestamp();
	std::cout
		<< "index:" 	  << _accountIndex 	<< ";"
		<< "amount:" 	  << _amount 		<< ";"
		<< "deposits:" 	  << _nbDeposits 	<< ";"
		<< "withdrawals:" << _nbWithdrawals <<std::endl;
}

//[19920104_091532]
void Account::_displayTimestamp(void) {
	time_t t = std::time(NULL);
	char timestamp[32];

	std::strftime(timestamp, sizeof(timestamp), "[%Y%m%d_%H%M%S] ", std::localtime(&t));
	std::cout << timestamp;
}
//std::time(NULL)でUNIX時間を取得
//std::localtime(&time)でローカル時刻に変更し
//std::strftimeで指定したフォーマットに変換[YYYYMMDD_HHMMSS]
