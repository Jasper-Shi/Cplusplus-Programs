// TODO: insert header files
#include "Fraction.h"
#include <iostream>
// TODO: continue the namespace
using namespace std;
using namespace sict;
    // TODO: implement the default constructor
Fraction::Fraction() {
	num_ = 0;
	den_ = 0;
}
    // TODO: implement the two-argument constructor
Fraction::Fraction(int num, int den) {
	if (num >= 0 && den > 0) {
		num_ = num;
		den_ = den;
		reduce();
	}
	else {
		num_ = 0;
		den_ = 0;
	}
}
    // TODO: implement the max query
    // max returns the maximum of the numerator and denominator
    //
int Fraction::max() const {
	int res;
	if (num_ > den_) {
		res = num_;
	}
	else {
		res = den_;
	}
	return res;
}
    // TODO: implement the min query
    // min returns the maximum of the numerator and denominator
    //
int Fraction::min() const {
	int res;
	if (num_ > den_) {
		res = den_;
	}
	else {
		res = num_;
	}
	return res;
}
    // gcd returns the greatest common divisor of num and denom
    //
    int Fraction::gcd() const {
        int mn = min();  // min of numerator and denominator
        int mx = max();  // max of numerator and denominator
        int g_c_d = 1;
        bool found = false;

        for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
            if (mx % x == 0 && mn % x == 0) {
                found = true;
                g_c_d = x;
            }
        }
        return g_c_d;
    }

    // TODO: implement the reduce modifier
    // reduce simplifies the fraction by dividing the numerator and denominator by the greatest common divisor
    //
    void Fraction::reduce() {
		int divisor = gcd();
		num_ /= divisor;
		den_ /= divisor;
    }

    // TODO: implement the display query
    // display inserts num/denom into the output stream
    //
	void Fraction::display() const {
		if (num_ >= 0 && den_ > 0 && den_ != 1)
			cout << num_ << "/" << den_;
		else if (num_ >= 0 && den_ == 1)
			cout << num_;
		else if (num_ == 0 && den_ == 0)
			cout << "no fraction stored";			
	}

    // TODO: implement the isEmpty query
    // isEmpty returns true if Fraction object is in a safe empty state
    //
	bool Fraction::isEmpty() const {
		bool isEmpty;
		if (num_ == 0 && den_ == 0)
			isEmpty = true;
		else
			isEmpty = false;
		return isEmpty;
	}
    // TODO: implement the + operator
    // + operator adds the rhs to the current object and reduces the result
    //
	Fraction Fraction::operator+(const Fraction& fra) {
	
		if (num_ >= 0 && den_ > 0 && fra.num_ >= 0 && fra.den_ > 0) {
			num_ = num_ * fra.den_ + fra.num_ * den_;
			den_ = den_ * fra.den_;
			reduce();
			
		}
		else if ((num_ == 0 && den_ == 0) || (fra.num_ == 0 && fra.den_ == 0)) {
			num_ = 0;
			den_ = 0;
		}
		return *this;

	}


