// Final Project Milestone 2
// Version 1.0
// Date	2017-07-07
// Author	Ziyi Shi
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "ErrorMessage.h"

namespace sict {
	ErrorMessage::ErrorMessage() {
		message_ = nullptr;
	}

	ErrorMessage::ErrorMessage(const char* errorMessage) {
		message_ = nullptr;
		message(errorMessage);
	}

	ErrorMessage& ErrorMessage::operator=(const char* errorMessage) {
		clear();
		message(errorMessage);
		return *this;
	}

	void ErrorMessage::clear() {
		delete[] message_;
		message_ = nullptr;
	}

	bool ErrorMessage::isClear()const {
		bool isClear;
		if (message_ == nullptr)
			isClear = true;
		else
			isClear = false;
		return isClear;
	}


	void ErrorMessage::message(const char* value) {
		delete[] message_;
		message_ = nullptr;
		message_ = new char[strlen(value) + 1];
		strcpy(message_, value);
	}

	const char* ErrorMessage::message()const {
		return message_;
	}

	ErrorMessage:: ~ErrorMessage() {
		delete[] message_;
		message_ = nullptr;
	}

	std::ostream& operator<<(std::ostream& os, const ErrorMessage& em) {
		if (!em.isClear()) {
			os << em.message();
		}
		return os;
	}
}
