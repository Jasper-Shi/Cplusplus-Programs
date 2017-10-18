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
	int n = 0, validNum = 0;
	if (name_ == nullptr)
		isValid = false;
	else
		isValid = true;
	if (isValid) {
	
		if (phoneNum_ != nullptr && np_ > 0) {
			while (n < np_) {
				if (valid(phoneNum_[n]))
					validNum++;
				n++;
			}
			np = validNum;
			long long* phoneNum = nullptr;
			phoneNum = new long long[validNum];
			for (int a = 0; a < np_; a++) {
				if (valid(phoneNum_[a])) {
	
					strcpy_s(name, name_);
					
					phoneNum[a] = phoneNum_[a];
					cout << phoneNum[a] << endl;

				}
			}
		}
		else if(name_[0] == '\0') {
			name[0] = '\0';
			phoneNum = nullptr;
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

bool Contact::valid(const long long phone) {
	bool valid;
	int coun, area, line;
	
	cout<<phone<<endl;
	coun = phone / 10000000000;
	area = (long long)(phone - (coun * 10000000000)) / 10000000;
	line = phone - coun * 10000000000 - area * 10000000;
	cout<<"coun: "<<coun<<"  area: "<<area<<"  line: "<<line<<endl;
	if (coun > 0 && coun < 100 && (area / 100 >= 1) && (line / 1000000 >= 1)){
		valid = true;
		
	}	
	else{
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
				area = (long long)(phoneNum[i] - (coun * 10000000000)) / 10000000;
				line = phoneNum[i] - coun * 10000000000 - area * 10000000;
				cout << "(+" << coun << ") " << area << " " << line << endl;
			}
		}
	}
}
