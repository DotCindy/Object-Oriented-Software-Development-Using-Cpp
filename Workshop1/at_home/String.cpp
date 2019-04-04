/*
Name:   Cindy Le
Email:  cle15@myseneca.ca
Date:   Jan 17, 2018
OOP345 - Workshop 1
*/

#define _CRT_SECURE_NO_WARNINGS
#include "String.h"

namespace sict {
	String::String(const char *pString) {
		if (pString == nullptr) {
			p_string[0] = '\0';
		}
		else {
			p_string = new char[strlen(pString) + 1];
			strncpy(p_string, pString, (strlen(pString) + 1));
		}
	}

	void String::display(std::ostream& os) const {
		os << p_string;
	}

	std::ostream& operator<<(std::ostream& os, const String& str) {
		static int currentItem = INITIAL - 1;
		currentItem++;
		os << currentItem << ": ";
		str.display(os);
		return os;
	}
}
