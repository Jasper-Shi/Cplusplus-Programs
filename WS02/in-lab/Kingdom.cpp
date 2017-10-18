/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date ???????????
// Author ?????????
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/


// TODO: include the necessary headers
#include"Kingdom.h"
#include<iostream>
using namespace std;
using namespace sict;
Kingdom kingdom;
// TODO: the sict namespace
void sict::display(const Kingdom& kingdom) {

	// TODO:definition for display(...) 
	cout << " " << kingdom.m_name << ", ";
	cout << "population " << kingdom.m_population << endl;
}