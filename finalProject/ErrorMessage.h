// Final Project Milestone 2
// Version 1.0
// Date	2017-07-09
// Author	Ziyi Shi
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
#ifndef sict_ErrorMessage_H
#define sict_ErrorMessage_H
namespace sict {
	class ErrorMessage {
		char* message_;
	public:
		ErrorMessage();
		ErrorMessage(const char* errorMessage);
		ErrorMessage(const ErrorMessage& em) = delete;
		ErrorMessage& operator=(const ErrorMessage& em) = delete;
		ErrorMessage& operator=(const char* errorMessage);
		virtual ~ErrorMessage();
		void clear();
		bool isClear()const;
		void message(const char* value);
		const char* message()const;
	};
	std::ostream& operator<<(std::ostream& os, const ErrorMessage& em);
}
#endif