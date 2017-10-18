// Product.h
#ifndef SICT_PRODUCT_H
#define SICT_PRODUCT_H

#include <iostream>
#include "general.h"
#include "Streamable.h"
namespace sict {
	class Product : public Streamable {
		char sku_[MAX_SKU_LEN + 1];
		char *name_;
		double price_;
		bool taxed_;
		int quantity_;
		int qtyNeeded_;
	public:
		Product();
		Product(const char*, const char*);
		Product(const char* sku, const char* name, double price, bool taxed, int quantity);
		Product(const Product& src);
		Product& operator=(const Product&);
		virtual ~Product();
//Setters
		void sku(const char* sku);
		void name(const char* name);
		void price(double price);
		void taxed(bool taxed);
		void quantity(int quantity);
		void qtyNeeded(int qtyNeeded);
//Getter
		const char* sku() const;
		const char* name() const;
		double price() const;
		bool taxed() const;
		int quantity() const;
		int qtyNeeded() const;
		double cost() const;
//isEmpty
		bool isEmpty() const;
// Member Operator overloads
		bool operator==(const char*);
		int operator+=(int);
		int operator-=(int);
	};
	double& operator+=(double&, const Product&);

	std::istream& operator >> (std::istream& is, Product& p);
	std::ostream& operator << (std::ostream& os, Product& p);
}

#endif // !SICT_PRODUCT_H
