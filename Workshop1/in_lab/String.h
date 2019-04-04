/*
Name:   Cindy Le
Email:  cle15@myseneca.ca
Date:   Jan 17, 2018
OOP345 - Workshop 1
*/

#ifndef SICT_STRING_H
#define SICT_STRING_H
#include <iostream>
#include <cstring>

namespace sict {
	const int INITIAL = 3;
	class String {
		char* p_string = nullptr;
	public:
		String(const char *pString = nullptr);
		void display(std::ostream& os) const;
	};
	std::ostream& operator<<(std::ostream& os, const String& str);
}

#endif
