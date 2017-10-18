#define _CRT_SECURE_NO_WARNINGS
#include "Product.h"
#include "general.h"
#include "Streamable.h"
#include <iostream>
#include <string.h>

using namespace sict;

Product::Product() {
	sku_[0] = '\0';
	name_ = nullptr;
	price_ = 0.0;
	quantity_ = 0;
	qtyNeeded_ = 0;
}

Product::Product(const char* sku, const char* name) {
	Product::sku(sku);

	Product::name(name);
	
	price(0);
	quantity(0);
	qtyNeeded(0);
}

Product::Product(const char* sku, const char* name, double price, bool taxed, int quantity) {

	Product::sku(sku);

	Product::name(name);

	qtyNeeded_ = 0;

	quantity_ = quantity;

	price_ = price;

	Product::taxed(taxed);

}

//copy construcotr
Product::Product(const Product& src) {
	//shallow copy
	sku(src.sku_);

	quantity(src.quantity_);

	price(src.price_);

	taxed(src.taxed_);

	qtyNeeded(src.qtyNeeded_);
	//allocate dynamic memory
	name(src.name_);
}


Product& Product::operator=(const Product& source) {
	if (this != &source) {
		//shallow copy
		sku(source.sku_);

		quantity(source.quantity_);

		price(source.price_);

		taxed(source.taxed_);

		qtyNeeded(source.qtyNeeded_);
		//deallocate
		delete[] name_;
		if (source.name_ != nullptr)
			Product::name(source.name_);
		else
			name_ = nullptr;
	}
	return *this;
}

Product::~Product() {
	delete[] name_;
}

//Setters
void Product::sku(const char* sku) {
	if (sku != nullptr) {
		strncpy(sku_, sku, MAX_SKU_LEN);
		sku_[MAX_SKU_LEN] = '\0';
	}
	else
	{
		sku_[0] = '\0';
	}
}
void Product::name(const char* name) {
	if (name != nullptr) {
		int len = strlen(name);
		name_ = new char[len + 1];
		strncpy(name_, name, len);
		name_[len] = '\0';
	}
	else {
		name_ = nullptr;
	}
}
void Product::price(double price) {
	price_ = price;
}
void Product::taxed(bool taxed) {
	if (taxed == true || taxed == false)
		taxed_ = taxed;
	else
		taxed_ = true;
}
void Product::quantity(int quantity) {
	quantity_ = quantity;
}
void Product::qtyNeeded(int qtyNeeded) {
	qtyNeeded_ = qtyNeeded;
}

//Getter
const char* Product::sku() const {
	return sku_;
}
const char* Product::name() const {
	return name_;
}
double Product::price() const {
	return price_;
}
bool Product::taxed() const {
	return taxed_;
}
int Product::quantity() const {
	return quantity_;
}
int Product::qtyNeeded() const {
	return qtyNeeded_;
}
double Product::cost() const {
	double rtn;
	if (taxed_ == true)
		rtn = price_ + price_ * TAX;
	else
		rtn = price_;
	return rtn;
}

bool Product::isEmpty() const{
	bool isEmpty;
	if (sku_[0] == '\0' && name_ == nullptr && price_ == 0.0 && quantity_ == 0 && qtyNeeded_ == 0)
		isEmpty = true;
	else
		isEmpty = false;
	return isEmpty;
}

//Overloading operator
bool Product::operator==(const char* sku) {
	bool same = false;
	if (*sku_ == *sku)
		same = true;
	return same;
}

int Product::operator+=(int qtyReceived) {
	quantity_ = quantity_ + qtyReceived;
	return quantity_;
}

int Product::operator-=(int qtyReduced) {
	int sum;
	sum = quantity_ - qtyReduced;
	return sum;
}


double& sict::operator+=(double& total, const Product& product) {
	total += product.cost() * product.quantity();
	return total;
}

std::istream & sict::operator >> (std::istream & is, Product & p)
{
	// TODO: insert return statement here
	p.read(is);
	return is;
}

std::ostream & sict::operator<<(std::ostream & os, Product & p)
{
	// TODO: insert return statement here
	p.write(os, true);
	return os;
}


