//CRA_Account.h
#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

// NAMESSPACE_ACCOUNT_H

namespace sict {
#define MAX_NAME_LENGTH 41
#define MIN_SIN 100000000
#define MAX_SIN 999999999
#define MAX_YRS 4

	

	class CRA_Account {
		char family_Name[MAX_NAME_LENGTH];
		char given_Name[MAX_NAME_LENGTH];
		int sin_;
		int m_year[MAX_YRS];
		double m_balance[MAX_YRS];
		int m_years;
	public:
		void set(const char* familyName, const char* givenName, int sin);
		void set(int year, double balance);
		bool isValid() const;
		void display() const;
	};
}
#endif