//CRA_Account.cpp

#include <iostream>
#include <string.h>
#include "CRA_Account.h"
using namespace std;
using namespace sict;
void CRA_Account::set(const char* familyName, const char* givenName, int sin)
{
	sin_ = sin;
	if (isValid()) {
		strcpy(family_Name, familyName);
		strcpy(given_Name, givenName);
	}
	else {
		sin_ = 0;
	}
		

	
}

bool CRA_Account::isValid() const
{
	bool check;
	if (sin_ > MIN_SIN &&sin_ < MAX_SIN) 
	{
		check = true;
	}
	else 
	{
		check = false;
	}
	return check;
}

void CRA_Account::display() const
{
	if (isValid()) {
		cout << "Family Name: " << family_Name << endl;
		cout << "Given Name : " << given_Name << endl;
		cout << "CRA Account: " << sin_ << endl;
	}
	else {
		cout << "Account object is empty!" << endl;
	}
}