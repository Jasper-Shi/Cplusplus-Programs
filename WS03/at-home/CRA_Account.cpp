	//CRA_Account.cpp

#include <iostream>
#include <stdio.h>
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
		m_years = 0;
	}
	else {
		sin_ = 0;
	}
		

	
}

void CRA_Account::set(int year, double balance) 
{
	if (isValid())
	{
		if (m_years < MAX_YRS) {
			m_year[m_years] = year;
			m_balance[m_years] = balance;
			m_years++;
		}
	}
}

bool CRA_Account::isValid() const
{
	bool check;
	int digit[9], sin;
	int sum1 = 0, sum2, sum3, set1, set2, res;


	if (sin_ > MIN_SIN &&sin_ < MAX_SIN) 
	{
		sin = sin_;
		for (int i = 8; i >= 0; i--) {
			digit[i] = sin % 10;
			sin = sin / 10;
		}
		for (int i = 1; i < 9; i += 2) {
			set1 = digit[i] * 2 % 10;
			set2 = digit[i] * 2 / 10;
			sum1 = sum1 + set1 + set2;
		}
		sum2 = digit[0] + digit[2] + digit[4] + digit[6];
		sum3 = sum1 + sum2;

		if (sum3 % 10 == 0)
			res = 0;
		else
			res = 10 - sum3 % 10;

		if (res == digit[8])
			check = true;
		else
			check = false;

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

		for (int i = 0; i < m_years; i++) {
			if (m_balance[i] < 2)
				cout << "Year (" << m_year[i] << ") refund due: " << -m_balance[i] << endl;
			else if (m_balance[i] > -2)
				cout << "Year (" << m_year[i] << ") balance owing: " << m_balance[i] << endl;
			else
				cout << "Year (" << m_year[i] << ") No balance owing or refund due" << endl;
		}
	}
	else {
		cout << "Account object is empty!" << endl;
	}
}