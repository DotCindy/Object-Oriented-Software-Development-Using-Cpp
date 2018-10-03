/*
Name:	Cindy Le
Email:	cle15@myseneca.ca
Date:	Sep 13, 2018
OOP345 - Workshop 1
*/

#ifndef W1_CSTRING_H
#define W1_CSTRING_H
#include <iostream>

extern int STORED;

namespace w1 {
	const int MAX = 3;
	class CString {
		char m_string[20];
	public:
		CString(const char *pString = nullptr);
		void display(std::ostream& os) const;
	};
	std::ostream& operator<<(std::ostream& os, const CString& str);
}

#endif
