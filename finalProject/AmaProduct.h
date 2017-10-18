// AmaProduct.h
#ifndef sict_AmaProduct_H
#define sict_AmaProduct_H

#include "Product.h"
#include "ErrorMessage.h"
#include "general.h"
#include <fstream>
namespace sict {
	class AmaProduct : public Product {
		char fileTag_;
		char unit_[11];
	protected:
		ErrorMessage err_;
	public:
		
		AmaProduct(char = 'N');
		const char* unit()const;
		void unit(const char* value);
		fstream& store(fstream& file, bool addNewLine = true)const;
		fstream& load(fstream& file);
		ostream& write(ostream& os, bool linear)const;
		istream& read(istream& istr);
	};
}
#endif

