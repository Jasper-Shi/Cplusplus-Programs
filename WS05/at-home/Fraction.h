// TODO: header file guard
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H




// TODO: create namespace
namespace sict {
	// TODO: define the Fraction class
	class Fraction {
		int num_;
		int den_;
		int gcd() const; // returns the greatest common divisor of num and denom
		int max() const; // returns the maximum of num and denom
		int min() const; // returns the minimum of num and denom
		void reduce();   // simplifies a Fraction by dividing the 
						 // numerator and denominator to their greatest common divisor 
	public:
		// TODO: declare the member functions
		Fraction();
		Fraction(int, int);
		bool isEmpty() const;
		void display() const;
		// TODO: declare the + operator overload
		Fraction operator+(const Fraction& fra);
		//Declare the * operator overload
		Fraction operator*(const Fraction& fra);
		//Declare the == operator overload
		bool operator==(const Fraction& fra);
		//Declare the != operator overload
		bool operator!=(const Fraction& fra);
		//Declare the += operator overload
		Fraction& operator+=(const Fraction fra);
		
	};
}
#endif