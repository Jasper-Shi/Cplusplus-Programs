#include "Account.h"

using namespace std;

namespace ict{ 
	
	// constructor   
	Account::Account() {
		setBalance(1.0);
	}
	Account::Account(double blc) {
		if (blc < 0)
			setBalance(1.0);
		else
			setBalance(blc);
	}

	// credit (add) an amount to the account balance
	void Account::credit(double amt) {
		balance = balance + amt;
	}
	
	// debit (subtract) an amount from the account balance return bool 
	bool Account::debit(double amt) {
		bool res;
		if (amt < balance) {
			balance = balance - amt;
			res = true;
		}
		else {
			res = false;
		}
		return res;
	}

	double Account::getBalance() const
	{
		return balance;
	} 

	void Account::setBalance( double newBalance )
	{
		balance = newBalance;
	} 
}