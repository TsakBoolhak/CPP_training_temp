// ************************************************************************** //
//                                                                            //
//                Account.cpp for GlobalBanksters United                //
//                Created on  : Mon Jan 24 01:08:15 2022                      //
//                Last update : Mon Jan 24 05:25:06 2022                      //
//       Made by : Aurelien "Tsak" Cabiac <real_account@realmail.com>         //
//                                                                            //
// ************************************************************************** //

#include "Account.hpp"
#include <iostream>

static void	displayLabelValue( const char *const label, const int value ) {

		std::cout << label << ':' << value;

		return ;
}

/******************************************************************************/
/*                                  Public                                    */
/*                                  Members                                   */
/******************************************************************************/

Account::Account( int initial_deposit ) : _accountIndex ( _nbAccounts ), _amount ( initial_deposit ), _nbDeposits ( 0 ), _nbWithdrawals ( 0 ) {

	Account::_totalAmount += _amount;
	Account::_nbAccounts++;
	_displayTimestamp();
	std::cout << ' ';
	displayLabelValue( "index", _accountIndex );
	std::cout << ';';
	displayLabelValue( "amount", _amount );
	std::cout << ';';
	std::cout << "created" << std::endl;
}

Account::~Account( void ) {

	_totalAmount -= _amount;
	_totalNbDeposits -= _nbDeposits;
	_totalNbWithdrawals -= _nbWithdrawals ;
	_nbAccounts--;
	_displayTimestamp();
	std::cout << ' ';
	displayLabelValue( "index", _accountIndex );
	std::cout << ';';
	displayLabelValue( "amount", _amount );
	std::cout << ';';
	std::cout << "closed" << std::endl;
}




int		Account::getNbAccounts( void ) {
	
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void ) {

	return Account::_totalAmount;
}

int	Account::getNbDeposits( void ) {

	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {

	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ) {

	Account::_displayTimestamp();
	std::cout << ' ';
	displayLabelValue( "accounts", Account::_nbAccounts );
	std::cout << ';';
	displayLabelValue( "total", Account::_totalAmount );
	std::cout << ';';
	displayLabelValue( "deposits", Account::_totalNbDeposits );
	std::cout << ';';
	displayLabelValue( "withdrawals", Account::_totalNbWithdrawals );
	std::cout << std::endl;

	return ;
}

void	Account::makeDeposit( int deposit ) {

	Account::_displayTimestamp();
	std::cout << ' ';
	displayLabelValue( "index", Account::_accountIndex );
	std::cout << ';';
	displayLabelValue( "p_amount", Account::_amount );
	std::cout << ';';

	if (Account::_amount + deposit >= Account::_amount){

		this->_amount += deposit;
		this->_nbDeposits++;
		Account::_totalNbDeposits++;
		Account::_totalAmount += deposit;
		displayLabelValue( "deposit", deposit );
		std::cout << ';';
		displayLabelValue( "amount", Account::_amount );
		std::cout << ';';
		displayLabelValue( "nb_deposits", Account::_nbDeposits );
	}

	else {

		std::cout << "deposit:failed";
	}

	std::cout << std::endl;

	return ;
}

bool	Account::makeWithdrawal( int withdrawal ) {

	bool	ret = false;

	Account::_displayTimestamp();
	std::cout << ' ';
	displayLabelValue( "index", Account::_accountIndex );
	std::cout << ';';
	displayLabelValue( "p_amount", Account::_amount );
	std::cout << ';';

	if (this->_amount - withdrawal > 0){
		ret = true;
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		displayLabelValue( "withdrawal", withdrawal );
		std::cout << ';';
		displayLabelValue( "amount", this->_amount );
		std::cout << ';';
		displayLabelValue( "nb_withdrawals", this->_nbWithdrawals );
	}

	else {

		std::cout << "withdrawal:refused";
	}
	
	std::cout << std::endl;

	return ret;
}

int		Account::checkAmount( void ) const {

	return this->_amount;
}

void	Account::displayStatus( void ) const {

	this->_displayTimestamp();
	std::cout << ' ';
	displayLabelValue( "index", this->_accountIndex );
	std::cout << ';';
	displayLabelValue( "amount", this->_amount );
	std::cout << ';';
	displayLabelValue( "deposits", this->_nbDeposits );
	std::cout << ';';
	displayLabelValue( "withdrawals", this->_nbWithdrawals );
	std::cout << std::endl;

	return ;
}


/******************************************************************************/
/*                                 Private                                    */
/*                                 Members                                    */
/******************************************************************************/

Account::Account( void ) :  _accountIndex ( _nbAccounts ), _amount ( 0 ), _nbDeposits ( 0 ), _nbWithdrawals ( 0 ) {

	Account::_totalAmount += Account::_amount;
	Account::_nbAccounts++;
	Account::_displayTimestamp();
	std::cout << ' ';
	displayLabelValue( "index", Account::_accountIndex );
	std::cout << ';';
	displayLabelValue( "amount", Account::_amount );
	std::cout << ';';
	std::cout << "created" << std::endl;
}




void	Account::_displayTimestamp( void ) {

	time_t		timer;
	struct tm	*timeinfo;

	time( &timer );
	timeinfo = localtime(&timer);

	char		output[128];

	strftime( output, 128, "[%Y%m%d_%H%M%S]", timeinfo );

	std::cout << output;

	return ;
}

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;
