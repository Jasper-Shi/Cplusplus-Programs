#ifndef SICT_CHECKINGACCOUNT_H__
#define SICT_CHECKINGACCOUNT_H__

#include "Account.h"

using namespace std;

namespace ict{
	class CheckingAccount : public Account {
		private:
			double transactionFee;

			// TODO: chargeFee subtract transaction fee form the balance
			void chargeFee();
		public:

			// TODO: constructor initializes balance and transaction fee 
			CheckingAccount(double blc, double tranFee);
			// TODO: Write a function prototype to override credit function
			void credit(double blc);
			// TODO: Write a function prototype to override debit function
			bool debit(double blc);
			// TODO: Write a function prototype to  override display function
			void display(ostream& cout);
	};
};
#endif
