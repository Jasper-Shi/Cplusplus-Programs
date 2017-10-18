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
	if (name_ == nullptr)
		isValid = false;
	else
		isValid = true;
	if (isValid) {
		if (phoneNum_ != nullptr && np_ > 0) {
			cout<<"2"<<endl;
			strcpy(name, name_);
			cout<<"3"<<endl;
			if (np_ > 0) {
				np = np_;
				cout<<np<<endl;
				phoneNum = new long long[np];
				for (int i = 0; i < np; i++){
					phoneNum[i] = phoneNum_[i];
					cout<<phoneNum[i]<<endl;
				}
			}
			else {
				phoneNum = nullptr;
			}
		}
		else if(name_[0] == '\0'){
			phoneNum = nullptr;
			strcpy(name, name_);
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
	cout<<"end"<<endl;
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
		cout<<"coun: "<<coun<<"  area: "<<area<<"  line: "<<line<<endl;
		if (coun > 0 && (area / 100 >= 1) && (line / 1000000 >= 1)){
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
