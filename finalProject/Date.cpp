// Final Project Milestone 1
//
// Version 1.0
// Date 2017-07-05
// Author Ziyi Shi
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#include "Date.h"
#include "general.h"
#include <iomanip>
namespace sict{

   int Date::value()const {
      return year_ * 372 + mon_ * 31 + day_;
   }

   int Date::mdays()const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = mon_ >= 1 && mon_ <= 12 ? mon_ : 13;
      mon--;
      return days[mon] + int((mon == 1)*((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0));
   }

   void Date::errCode(int errorCode) {
	   if (errorCode >= 0 && errorCode <= 4)
		   readErrorCode_ = errorCode;
   }
   int Date::errCode()const { return readErrorCode_; }

   bool Date::bad()const { if (errCode() != 0)return true; else return false; }
   Date::Date() {
	   year_ = 0;
	   mon_ = 0;
	   day_ = 0;
	   readErrorCode_ = NO_ERROR;
   }
   Date::Date(int year, int mon, int day) {
	   if (year >= MIN_YEAR && year <= MAX_YEAR)
		   year_ = year;
	   if (mon >= 1 && mon <= 12) {
		   mon_ = mon;
	   }
	   if (day >= 1 && day <= mdays()) {
		   day_ = day;
	}
	   readErrorCode_ = NO_ERROR;
   }
   bool Date::operator==(const Date& D)const {
	   bool res;
	   if (this->value() == D.value())
		   res = true;
	   else
		   res = false;
	   return res;
   }
   bool Date::operator!=(const Date& D)const {
	   bool res;
	   if (this->value() != D.value())
		   res = true;
	   else
		   res = false;
	   return res;
   }
   bool Date::operator<(const Date& D)const {
	   bool res;
	   if (this->value() < D.value())
		   res = true;
	   else
		   res = false;
	   return res;
   }
   bool Date::operator>(const Date& D)const {
	   bool res;
	   if (this->value() > D.value())
		   res = true;
	   else
		   res = false;
	   return res;
   }
   bool Date::operator<=(const Date& D)const {
	   bool res;
	   if (this->value() <= D.value())
		   res = true;
	   else
		   res = false;
	   return res;
   }
   bool Date::operator>=(const Date& D)const {
	   bool res;
	   if (this->value() >= D.value())
		   res = true;
	   else
		   res = false;
	   return res;
   }
   std::istream& Date::read(std::istream& istr) {
	   istr >> year_;
	   if (!istr.fail() && (istr.get() == '/' || istr.get() == '-')) {
		   istr >> mon_;
		   if (!istr.fail() && (istr.get() == '/' || istr.get() == '-')) {
			   istr >> day_;
			   if (istr.fail()) {
				   errCode(CIN_FAILED);
			   }

		   }
		   else {errCode(CIN_FAILED); }

	   }

	   else {errCode(CIN_FAILED); }
	   if (!bad()) {
		   if (year_<MIN_YEAR || year_>MAX_YEAR)
			   readErrorCode_ = YEAR_ERROR;
		   else if (mon_ < 0 || mon_>12)
			   readErrorCode_ = MON_ERROR;
		   else if (day_ < 0 || day_ > mdays())
			   readErrorCode_ = DAY_ERROR;
	   }
	   return istr;
   }
   std::ostream& Date::write(std::ostream& ostr)const {
	   ostr << year_ << "/";
	   if (mon_ > 0 && mon_ < 10)
		   ostr << "0" << mon_ << "/";
	   else
		   ostr << mon_ << "/";
	   if (day_ > 0 && day_ < 10)
		   ostr << "0" << day_;
	   else
		   ostr << day_;
	   //ostr.unsetf(std::ios::fill('0')); //changed
	   return ostr;
   }
   std::ostream& operator<<(std::ostream& os, const Date& d) {
	   d.Date::write(os);
	   return os;
   }
   std::istream& operator >> (std::istream& is, Date& d) {
	   d.Date::read(is);
	   return is;
   }
}
