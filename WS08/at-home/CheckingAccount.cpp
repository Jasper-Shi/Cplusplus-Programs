#include "CheckingAccount.h"

using namespace std;

namespace ict{    
	
	// TODO: define CheckingAccount class member functions here  

	void CheckingAccount::chargeFee()
	{
		setBalance(transactionFee);
	}

	CheckingAccount::CheckingAccount(double blc, double tranFee)
	{
		if (blc < 0)
			setBalance(1.0);
		else
			setBalance(blc);
		if (tranFee > 0)
			transactionFee = tranFee;
		else
			transactionFee = 0;

	}

	void CheckingAccount::credit(double blc)
	{
		Account::credit(blc);
		setBalance(getBalance() - transactionFee);
	}

	bool CheckingAccount::debit(double blc)
	{
		setBalance(getBalance() - transactionFee);
		return Account::debit(blc);
	}

	void CheckingAccount::display(ostream & cout)
	{
		cout << "Account type: Checking" << endl;
		cout << "Balance: $ ";
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << getBalance() << endl;
		cout << "Transaction Fee: ";
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << transactionFee << endl;
	}

}