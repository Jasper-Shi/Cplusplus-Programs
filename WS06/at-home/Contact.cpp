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
			np = 0;
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

Contact::Contact(const Contact& src) {
	phoneNum = nullptr;
	*this = src;
}

Contact& Contact::operator=(const Contact& src) {
	int validNum = 0, num = 0;
	//check for self-assignment
	if (this != &src) {
		//Shallow copy
		strcpy_s(name, src.name);
		np = src.np;
		//deallocate previously allocated dynami memory
		delete[] phoneNum;
		//allocate new dynamic memory
		if (src.phoneNum != nullptr && np > 0) {
			for (int a = 0; a < np; a++) {
				if (valid(&src.phoneNum[a])) {
					validNum = validNum + 1;
				}
			}
			np = validNum;
			phoneNum = new long long[np];
			for (int i = 0; i < src.np; i++) {
				if (valid(&src.phoneNum[i])) {
					phoneNum[num] = src.phoneNum[i];
					num++;
				}
			}
		}
		else {
			phoneNum = nullptr;
		}
	}
	return *this;
}

Contact& Contact::operator+=(const long long phone) {
	if (valid(&phone)) {
		np = np + 1;
		if (np <= 1) {
			phoneNum = new long long[np];
			phoneNum[np - 1] = phone;
		}
		else {
			long long *temp = new long long[np];
			for (int i = 0; i < np - 1; i++) {
				temp[i] = phoneNum[i];
			}
			temp[np - 1] = phone;
			delete[] phoneNum;
			phoneNum = temp;
		}

	}
	return *this;
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
