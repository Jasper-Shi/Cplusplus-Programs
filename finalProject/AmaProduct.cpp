
// AmaProduct.cpp
#define _CRT_SECURE_NO_WARNINGS
#include "AmaProduct.h"
#include <iomanip>
#include <iostream>
#include <string.h>



sict::AmaProduct::AmaProduct(char fileTag)
{
	fileTag_ = fileTag;
}

const char * sict::AmaProduct::unit() const
{
	return unit_;
}

void sict::AmaProduct::unit(const char * value)
{
	int len = strlen(value);
	strncpy(unit_, value, len);
}

fstream & sict::AmaProduct::store(fstream & file, bool addNewLine) const
{
	file << fileTag_ << "," << sku() << "," << name() << "," << price() << "," << taxed() << "," << quantity() << "," << unit_ << "," << qtyNeeded();
	if (addNewLine)
		file << endl;
	// TODO: insert return statement here
	return file;
}

fstream & sict::AmaProduct::load(fstream & file)
{
	char sku__[MAX_SKU_LEN + 1];
	char name__[100];
	char unit[11];
	double price__;
	int quantity__, qtyNeeded__;
	bool taxed__;
	//read
	/*char temp[100];
	file.getline(sku__, MAX_SKU_LEN + 1, ',');
	file.getline(name__, 100, ',');
	file.getline(temp, 100, ',');	price__ = atof(temp);
	file.getline(temp, 100, ',');	taxed__ = atoi(temp);
	file.getline(temp, 100, ',');	quantity__ = atoi(temp);
	file.getline(unit, 11, ',');
	file.getline(temp, 100, ',');	qtyNeeded__ = atoi(temp);
	*/
	file.getline(sku__, MAX_SKU_LEN + 1, ',');
	file.getline(name__, 100, ',');
	file >> price__;	file.ignore();
	file >> taxed__;	file.ignore();
	file >> quantity__;	file.ignore();
	file.getline(unit, 11, ',');
	file >> qtyNeeded__;	file.ignore();
	//set
	sku(sku__);
	name(name__);
	price(price__);
	taxed(taxed__);
	quantity(quantity__);
	strcpy(unit_, unit);
	qtyNeeded(qtyNeeded__);
	// TODO: insert return statement here
	return file;
}

ostream & sict::AmaProduct::write(ostream & os, bool linear) const
{

	if (!err_.isClear()) {
		os << err_;
		return os;
	}
	else {
		if (linear) {
			os.width(MAX_UPC_LEN);
			os.setf(ios::left);
			os << sku() << "|";
			os.unsetf(ios::left);

			os.width(20);
			os.setf(ios::left);
			os << name() << "|";
			os.unsetf(ios::left);

			os.setf(ios::fixed);
			os.width(7);
			os.setf(ios::right);
			os.precision(2);
			os << cost() << "|";
			os.unsetf(ios::fixed);
			os.unsetf(ios::right);

			os.width(4);
			os.setf(ios::right);
			os << quantity() << "|";
			os.unsetf(ios::right);

			os.width(10);
			os.setf(ios::left);
			os << unit_ << "|";
			os.unsetf(ios::left);

			os.width(4);
			os.setf(ios::right);
			os << qtyNeeded() << "|";
			os.unsetf(ios::right);
		}
		else {
			if (taxed()) {
				os << "Sku: " << sku() << endl
					<< "Name: " << name() << endl
					<< "Price: " << setprecision(2) << std::fixed << price() << endl
					<< "Price after tax: " << setprecision(2) << std::fixed << cost() << endl
					<< "Quantity On Hand: " << quantity() << " " << unit_ << endl
					<< "Quantity Needed: " << qtyNeeded();
			}
			else {
				os.setf(ios::fixed);
				os.precision(2);
				os << "Sku: " << sku() << endl
					<< "Name: " << name() << endl
					<< "Price: " << price() << endl
					<< "Price after tax: " << "N/A" << endl
					<< "Quantity On Hand: " << quantity() << " " << unit_ << endl
					<< "Quantity Needed: " << qtyNeeded();
			}
		}
		return os;
	}
}

istream & sict::AmaProduct::read(istream & istr)
{
	char sku_[MAX_SKU_LEN + 1];
	char name_[50];
	char unit[11];
	double price_;
	char Taxed;
	bool taxed_;
	int quantity_;
	int qtyNeeded_;
	//insert
	cout << "Sku: ";
	//istr >> sku_;
	istr.ignore();
	istr.getline(sku_, MAX_SKU_LEN + 1, '\n');
	if (istr.fail()) {
		return istr;
	}
	else {
		sku(sku_);
		cout << "Name: ";
		//istr >> name_;
		
		istr.getline(name_, 50, '\n');
		
		if (istr.fail()) {
			return istr;
		}
		else {
			name(name_);
			cout << "Unit: ";
			//istr >> unit;
			
			istr.getline(unit, 11, '\n');

			if (istr.fail()) {
				return istr;
			}
			else {
				strcpy(unit_, unit);
				cout << "Taxed? (y/n): ";
				istr >> Taxed;
				if (Taxed != 'y' && Taxed != 'n' && Taxed != 'Y' && Taxed != 'N') {
					err_.message("Only (Y)es or (N)o are acceptable");
					istr.setstate(ios::failbit);
					return istr;
				}
				else {
					if (Taxed == 'y' || Taxed == 'Y') {
						taxed_ = true;
					}
					else if (Taxed == 'n' || Taxed == 'N') {
						taxed_ = false;
					}
					taxed(taxed_);//order might be wrong
					istr.clear();
					cout << "Price: ";
					istr >> price_;

					if (istr.fail()) {
						err_.message("Invalid Price Entry");
						return istr;
					}
					else {
						price(price_);
						cout << "Quantity On hand: ";
						istr >> quantity_;

						if (istr.fail()) {
							err_.message("Invalid Quantity Entry");
							return istr;
						}
						else {
							quantity(quantity_);
							cout << "Quantity Needed: ";
							istr >> qtyNeeded_;

							if (istr.fail()) {
								err_.message("Invalid Quantity Needed Entry");
								return istr;
							}
							else {
								qtyNeeded(qtyNeeded_); // not read newline
								err_.clear();
								return istr;
							}
						}
					}
				}
			}
		}
	}

}
