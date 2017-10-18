#include "Contact.h"
#include <iostream>
#include <string.h>
using namespace std;
using namespace sict;

Contact::Contact() {
	name[0] = '\0';
	np = 0;
	phoneNum = nullptr;
}
Contact::Contact(const char* name_, const long long* phoneNum_, int np_) {
	bool isValid;
	if (name_ == nullptr)
		isValid = false;
	else
		isValid = true;
	cout << isValid;
	if (isValid) {
		if (valid(phoneNum_)) {
			strcpy_s(name, name_);
			if (np_ > 0) {
				np = np_;
				phoneNum = new long long[np];
				for (int i = 0; i < np; i++)
					phoneNum[i] = phoneNum_[i];
			}
			else {
				phoneNum = nullptr;
			}
		}
		else if(name_[0] == '\0'){
			phoneNum = nullptr;
			strcpy_s(name, name_);
		}
		else {
			phoneNum = nullptr;
			for (int j = 0; j < 19; j++)
				name[j] = name_[j];
		}
	}
	else {
		name[0] = '\0';
		phoneNum = nullptr;
	}
}
	

Contact::~Contact() {
	delete [] phoneNum;
	phoneNum = nullptr;
}
bool Contact::isEmpty() const {
	bool check;
	if (name[0] == '\0' && phoneNum == nullptr)
		check = true;
	else
		check = false;
	return check;
}

bool Contact::valid(const long long* phone) {
	bool valid;
	int coun, area, line;
	if (phone != nullptr) {
		coun = *phone / 10000000000;
		area = (int)(*phone - (coun * 10000000000)) / 10000000;
		line = *phone - coun * 10000000000 - area * 10000000;
		if (coun > 0 && (area / 100 >= 1) && (line / 1000000 >= 1))
			valid = true;
		else
			valid = false;
	}
	else {
		valid = false;
	}
	return valid;
}

void Contact::display() const{
	int coun, area, line;
	if (isEmpty()) {
		cout << "Empty contact!" << endl;
	}
	else {
		cout << name << endl;
		if (phoneNum == nullptr) {
			cout << "";
		}
		else {

			for (int i = 0; i < np; i++) {
				coun = phoneNum[i] / 10000000000;
				area = (int)(phoneNum[i] - (coun * 10000000000)) / 10000000;
				line = phoneNum[i] - coun * 10000000000 - area * 10000000;
				cout << "(+" << coun << ") " << area << " " << line << endl;
			}
		}
	}
}