#include "AmaPerishable.h"

// AmaPersishable.cpp

sict::AmaPerishable::AmaPerishable() : AmaProduct::AmaProduct('P')
{
	AmaProduct('P');
}


void sict::AmaPerishable::expiry(const Date & value)
{
	expiry_ = value;
}

fstream & sict::AmaPerishable::store(fstream & file, bool addNewLine) const
{
	AmaProduct::store(file, false);
	file << ",";
	expiry_.write(file);
	if (addNewLine)
		file << endl;
	// TODO: insert return statement here
	return file;
}

fstream & sict::AmaPerishable::load(fstream & file)
{
	AmaProduct::load(file);
		
	expiry_.read(file);
	file.ignore();
	// TODO: insert return statement here
	return file;
}

ostream & sict::AmaPerishable::write(ostream & ostr, bool linear) const
{
	AmaProduct::write(ostr, linear);
	if (err_.isClear()) {
		if (linear) {
			expiry_.write(ostr);
		}
		else {
			ostr << endl << "Expiry date: ";
			expiry_.write(ostr);
		}
	}
	return ostr;
	
}

istream & sict::AmaPerishable::read(istream & istr)
{
	Date temp;
	AmaProduct::read(istr);
	if (err_.isClear()) {
		cout << "Expiry date (YYYY/MM/DD): ";
		istr >> temp;
		
		if (temp.bad()) {
			switch (temp.errCode()) {
			case 1:
				err_.message("Invalid Date Entry");
				break;
			case 2:
				err_.message("Invalid Year in Date Entry");
				break;
			case 3:
				err_.message("Invalid Month in Date Entry");
				break;
			case 4:
				err_.message("Invalid Day in Date Entry");
				break;
			}
			istr.setstate(ios::failbit);
		}
		else {
			expiry_ = temp;
		}
	}
	return istr;
}


