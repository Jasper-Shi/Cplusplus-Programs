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
}
	// TODO: implement the constructor with 2 parameters here
Passenger::Passenger (char* name, char* desti) {
	
	if (name == nullptr || desti == nullptr || *name == '\0' || *desti == '\0' ) {
		passeName[0] = '\0';
		destination[0] = '\0';
	}
	else {
	strcpy_s(passeName, name);
	strcpy_s(destination, desti);
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
	cout << passeName << " - " << destination;
}
