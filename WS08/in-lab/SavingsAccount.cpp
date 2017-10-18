#include "SavingsAccount.h"

using namespace std;

namespace ict{ 
	
	// TODO: Implement SavingsAccount member functions here
	SavingsAccount::SavingsAccount(double blc, double rate) {
		if (blc < 0)
			setBalance(1.0);
		else
			setBalance(blc);
		if (rate < 0)
			interestRate = 0.0;
		else
			interestRate = rate;
	}

	double SavingsAccount::calculateInterest() {
		return getBalance() * interestRate;
	}

	void SavingsAccount::display(ostream& cout) {
		cout << "Account type: Saving" << endl;
		cout << "Balance: $ ";
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << getBalance() << endl;
		cout << "Interest Rate (%): ";
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << interestRate * 100 << endl;
	}
}