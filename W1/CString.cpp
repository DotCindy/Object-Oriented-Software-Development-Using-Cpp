/*
Name:	Cindy Le
Email:	cle15@myseneca.ca
Date:	Sep 13, 2018
OOP345 - Workshop 1
*/

#define _CRT_SECURE_NO_WARNINGS
#include "CString.h"

namespace w1 {
	CString::CString(const char *pString) {
		if (pString == nullptr) {
			m_string[0] = '\0';
		}
		else {
			strncpy(m_string, pString, MAX);
			m_string[MAX] = '\0';
		}
	}

	void CString::display(std::ostream& os) const {
		os << m_string;
	}

	std::ostream& operator<<(std::ostream& os, const CString& str) {
		str.display(os);
		return os;
	}
}
