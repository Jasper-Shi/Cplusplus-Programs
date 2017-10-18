#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

namespace sict {
	class Contact {
		char name[20];
		int np;
		long long* phoneNum;
	public:
		Contact();
		Contact(const char*, const long long phoneNum_[], int);
		~Contact();
		bool isEmpty() const;
		bool valid(const long long*);
		void display() const;
	};
}

#endif
