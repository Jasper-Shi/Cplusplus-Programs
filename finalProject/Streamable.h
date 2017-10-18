#ifndef SICT_Streamable_H
#define SICT_Streamable_H
#include <iostream>
#include <fstream>
using namespace std;

namespace sict {
	class Streamable {
	public:
		virtual fstream& store(fstream& file, bool addNewLine = true)const = 0;
		virtual fstream& load(std::fstream& file) = 0;
		virtual ostream& write(ostream& os, bool linear)const = 0;
		virtual istream& read(istream& is) = 0;
	};
}
#endif // !Streamable_H

