// TODO: add your headers here 
#include "Passenger.h"
#include <iostream>
#include <string.h>

// TODO: continue your namespace here
using namespace std;
using namespace sict;
    // TODO: implement the default constructor here
Passenger::Passenger() {
	passeName[0] = '\0';
	destination[0] = '\0';
	yod = 0;
	mod = 0;
	dod = 0;
}

	// TODO: implement the constructor with 5 parameters here
Passenger::Passenger(char* name, char* desti, int yod_, int mod_, int dod_) {
	if (name == nullptr || desti == nullptr || *name == '\0' || *desti == '\0' || (yod_ != 2017 && yod_ != 2018 && yod_ != 2019 && yod_ != 2020) || mod_ < 1 || mod_>12 || dod_ < 1 || dod_>31) {
		passeName[0] = '\0';
		destination[0] = '\0';
		yod = 0;
		mod = 0;
		dod = 0;
	}
	else {
		strcpy_s(passeName, name);
		strcpy_s(destination, desti);
		yod = yod_;
		mod = mod_;
		dod = dod_;
	}
}
	// TODO: implement the constructor with 2 parameters here
Passenger::Passenger (char* name, char* desti) {
	
	if (name == nullptr || desti == nullptr || *name == '\0' || *desti == '\0' ) {
		passeName[0] = '\0';
		destination[0] = '\0';
		yod = 0;
		mod = 0;
		dod = 0;
	}
	else {
	strcpy_s(passeName, name);
	strcpy_s(destination, desti);
	yod = 2017;
	mod = 7;
	dod = 1;
	}
}

    // TODO: implement isEmpty query here
bool Passenger::isEmpty() const {
	bool check;
	
	if (passeName[0] == '\0' && destination[0] == '\0' ) {
		check = true;

	}
	else {
		check = false;
	}

	return check;
}
    // TODO: implement display query here
void Passenger::display() const {
	cout << passeName << " - " << destination << " on " << yod << "/";
	cout.fill('0');
	cout.width(2);
	cout << mod << "/" << dod << endl;
}

const char* Passenger::name() const {
	
	return passeName;
}

bool Passenger::canTravelWith(const Passenger& friends) const {
	bool check;
	int cmp;
	cmp = strcmp(friends.destination, destination);
	if (cmp == 0 && friends.yod == yod && friends.mod == mod && friends.dod == dod) {
		check = true;
	}
	else {
		check = false;
	}
	return check;
}