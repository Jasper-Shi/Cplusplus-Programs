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
#ifndef SICT_DATE_H__
#define SICT_DATE_H__
#include <iostream>

namespace sict{

   class Date {
   private:
	   int year_;
	   int mon_;
	   int day_;
	   int readErrorCode_;
      int value()const;
	  void errCode(int errorCode);
 
   public:
	   Date();
	   Date(int year, int mon, int day);
      int mdays()const;
	  bool operator==(const Date& D)const;
	  bool operator!=(const Date& D)const;
	  bool operator<(const Date& D)const;
	  bool operator>(const Date& D)const;
	  bool operator<=(const Date& D)const;
	  bool operator>=(const Date& D)const;
	  int errCode()const;
	  bool bad()const;
	  std::istream& read(std::istream& istr);
	  std::ostream& write(std::ostream& ostr)const;
   };
   std::ostream& operator<<(std::ostream& os, const Date& d);
   std::istream& operator>>(std::istream& is, Date& d);



}
#endif