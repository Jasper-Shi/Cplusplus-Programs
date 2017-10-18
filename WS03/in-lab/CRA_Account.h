//CRA_Account.h
#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

// NAMESSPACE_ACCOUNT_H

namespace sict {
#define MAX_NAME_LENGTH 41
#define MIN_SIN 100000000
#define MAX_SIN 999999999

	class CRA_Account {
		char family_Name[MAX_NAME_LENGTH];
		char given_Name[MAX_NAME_LENGTH];
		int sin_;
	public:
		void set(const char* familyName, const char* givenName, int sin);
		bool isValid() const;
		void display() const;
	};
}
#endif