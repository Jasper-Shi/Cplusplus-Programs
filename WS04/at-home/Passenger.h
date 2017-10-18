// TODO: add header file guard here
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

// TODO: declare your namespace here
namespace sict {
// TODO: define the Passenger class here
	class Passenger {
		char passeName[32];
		char destination[32];
		int yod;
		int mod;
		int dod;
	public:
		Passenger();
		Passenger(char* name, char* desti, int yod_, int mod_, int dod_);
		Passenger(char* name, char* desti);
		bool isEmpty() const;
		void display() const;
		const char* name() const;
		bool canTravelWith(const Passenger&) const;
	};

	
}


#endif