#include "AidApp.h"
#include "AmaPerishable.h"
#include "AmaProduct.h"
#include <string.h>
#include <iomanip>
#include <iostream>

using namespace std;

void sict::AidApp::pause() const
{
	cout << endl;
	cout << "Press Enter to continue...";
	while (cin.get() != '\n');
	cin.ignore();
	cout << endl;
}

int sict::AidApp::menu()
{
	int choice;
	cout << "Disaster Aid Supply Management Program" << endl
		<< "1- List products" << endl
		<< "2- Display product" << endl
		<< "3- Add non-perishable product" << endl
		<< "4- Add perishable product" << endl
		<< "5- Add to quantity of purchased products" << endl
		<< "0- Exit program" << endl
		<< "> ";
	cin >> choice;
	cout << endl;
	if (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 0)
		return choice;
	else
		return -1;
}

void sict::AidApp::loadRecs() //logic from YuanSheng Lu
{
	int readIndex = 0;
	char ID;
	datafile_.open(filename_, ios::in); // file name might be wrong
	if (datafile_.fail()) {
		datafile_.clear();
		datafile_.close();
		datafile_.open(filename_, ios::out);
		datafile_.close();
	}
	else {
		do {

			//delete[] product_;
			
			datafile_ >> ID;
			if (!datafile_.fail()) { //prevent reading nothing with fail status
				if (ID == 'P') {
					product_[readIndex] = new AmaPerishable;
				}
				else if (ID == 'N') {
					product_[readIndex] = new AmaProduct;
				}
				if (ID == 'N' || ID == 'P') {
					datafile_.ignore();
					product_[readIndex]->load(datafile_);
					readIndex++;
				}
			}
		} while (!datafile_.fail());
	}
	noOfProducts_ = readIndex;
	datafile_.close();
}

void sict::AidApp::saveRecs()
{
	datafile_.open(filename_, ios::out);
	for (int i = 0; i < noOfProducts_; i++) {
		product_[i]->store(datafile_);
	}
	datafile_.close();
}

void sict::AidApp::listProducts() const
{
	double totalCost = 0.0;
	cout << " Row | SKU    | Product Name       | Cost  | QTY| Unit     |Need| Expiry   " << endl;
	cout << "-----|--------|--------------------|-------|----|----------|----|----------" << endl;
	for (int i = 0; i < noOfProducts_; i++) {
		cout.setf(ios::right);
		cout << "   " << (i + 1);
		cout.unsetf(ios::right);
		cout << " | " << *product_[i] << endl;//maybe *product_[i]
		totalCost += product_[i]->cost() * product_[i]->quantity();
		if (i == 9)
			pause();
	}
	cout << "---------------------------------------------------------------------------" << endl;
	cout.setf(ios::fixed);
	cout.width(7);
	cout.setf(ios::right);
	cout.precision(2);
	cout << "Total cost of support: $" << totalCost << endl;
	cout.unsetf(ios::fixed);
	cout.unsetf(ios::right);
}

int sict::AidApp::SearchProducts(const char * sku) const
{
	int rtn = -1;
	for (int i = 0; i < noOfProducts_; i++) {
		if (strcmp(product_[i]->sku(), sku) == 0)
			rtn = i;
	}
	if (rtn != -1)
		return rtn;
	else
		return -1;
}

void sict::AidApp::addQty(const char * sku)
{
	int qtyPurchased = 0;
	
	int index = SearchProducts(sku);
	if (index == -1) {
		cout << "Not found!" << endl;
	}
	else {
		int amtReq = 0;		amtReq = product_[index]->qtyNeeded() - product_[index]->quantity();

		product_[index]->write(cout, false);// might be wrong
		cout << endl << endl;
		cout << "Please enter the number of purchased items: ";
		cin >> qtyPurchased;
		if (cin.fail() || qtyPurchased < 0)
			cout << "Invalid quantity value! " << endl;//might have one more space
		else {
			if (qtyPurchased <= amtReq) {
				*product_[index] += qtyPurchased;
			}
			else {
				*product_[index] += amtReq;
				cout << "Too many items; only 999 is needed, please return the extra 99 items. " << endl;
			}
			saveRecs();
			cout << endl;
			cout << "Updated!" << endl << endl;
		}
	}
	cin.clear();
}

void sict::AidApp::addProduct(bool isPerishable)
{
	if (isPerishable == true) {
		product_[noOfProducts_] = new AmaPerishable;
		product_[noOfProducts_]->read(cin);

		noOfProducts_++;
		saveRecs();
		
		cout << endl;
		cout << "Product added" << endl << endl;
	}
	else {
	
		product_[noOfProducts_] = new AmaProduct;
		product_[noOfProducts_]->read(cin);
		
		noOfProducts_++;
		saveRecs();

		cout << endl;
		cout << "Product added" << endl << endl;
	}
}

int sict::AidApp::run()
{
	int sel;
	char sku[MAX_SKU_LEN + 1];
	do {
		sel = menu();

		if (sel == 1) {
			listProducts();
			pause();
		}

		else if (sel == 2) {
			cout << "Please enter the SKU: ";
			cin >> sku;
			cout << endl;
			if (SearchProducts(sku) != -1) {
				product_[SearchProducts(sku)]->write(cout, false);
				cout << endl;
			}
			else {
				cout << "Not found!" << endl;
			}
			pause();
		}

		else if (sel == 3) {
			addProduct(false);
			loadRecs();
			
		}

		else if (sel == 4) {
			addProduct(true);
			loadRecs();
			
		}

		else if (sel == 5) {
			cout << "Please enter the SKU: ";
			cin >> sku;
			cout << endl;
			addQty(sku);
			
		}

		else if (sel == 0) {
			cout << "Goodbye!!" << endl;
			
		}

		else {
			cout << "===Invalid Selection, try again.===" << endl;
			pause();
		}
	} while (sel != 0);

		return 0;
}

sict::AidApp::AidApp(const char * filename)
{
	strcpy(filename_, filename);

	for (int i = 0; i < MAX_NO_RECS; i++)
		product_[i] = nullptr;

	noOfProducts_ = 0;
	//load records
	loadRecs();
}
