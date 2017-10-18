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
Contact::Contact(const char* name_, const long long phoneNum_[], int np_) {
	bool isValid;
	int num = 0;
	int validNum = 0;
	if (name_ == nullptr)
		isValid = false;
	else
		isValid = true;
	if (isValid) {
		if (phoneNum_ != nullptr && np_ > 0) {
			strcpy_s(name, name_);
			for (int a = 0; a < np_; a++) {
				if (valid(&phoneNum_[a])) {
					validNum = validNum + 1;
				}
			}
			np = validNum;
			phoneNum = new long long[np];
			for (int i = 0; i < np_; i++){
				if (valid(&phoneNum_[i])) {
					phoneNum[num] = phoneNum_[i];
					num++;
				}
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
		area = (long long)(*phone - (coun * 10000000000)) / 10000000;
		line = *phone - coun * 10000000000 - area * 10000000;
		if (coun > 0 && coun < 100 && area / 100 >= 1 && (line / 1000000 >= 1)){
			valid = true;
		}	
		else{
			valid = false;
		}	
	}
	else {
		valid = false;
	}
	return valid;
}

void Contact::display() const{
	int coun, area, line, line2;
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
				area = (long long)(phoneNum[i] - (coun * 10000000000)) / 10000000;
				line = phoneNum[i] - coun * 10000000000 - area * 10000000;
				line2 = line / 10000;
				cout << "(+" << coun << ") " << area << " " << line2 << "-" << line - line2 * 10000 << endl;
			}
		}
	}
}
