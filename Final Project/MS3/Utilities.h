/*
Name:   Cindy Le
Email:  cle15@myseneca.ca
Date:   Mar 4, 2019
OOP345 - Milestone 1
*/

#ifndef SICT_UTILITIES_H
#define SICT_UTILITIES_H
#include <string>

namespace sict {
	class Utilities {
		static char m_delim;
		size_t m_fieldWidth;
	public:
		Utilities();
		const std::string extractToken(const std::string& str, size_t& next_pos);
		const char getDelimiter() const;
		size_t getFieldWidth() const;
		static void setDelimiter(const char d);
		void setFieldWidth(size_t);
	};
}

#endif
