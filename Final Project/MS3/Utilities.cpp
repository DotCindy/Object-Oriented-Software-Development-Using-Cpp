/*
Name:   Cindy Le
Email:  cle15@myseneca.ca
Date:   Mar 4, 2019
OOP345 - Milestone 1
*/

#include "Utilities.h"

namespace sict {
	char Utilities::m_delim = ' ';
	Utilities::Utilities() : m_fieldWidth{ 1 } {}

	const std::string Utilities::extractToken(const std::string& str, size_t& next_pos) {
		std::string token;

		while (next_pos < str.size()) {
			if (str.at(next_pos) == m_delim) {
				next_pos++;
				break;
			}
			else {
				token += str.at(next_pos);
				next_pos++;
			}
		}
		setFieldWidth(token.size());
		return token;
	}

	const char Utilities::getDelimiter() const {
		return m_delim;
	}

	size_t Utilities::getFieldWidth() const {
		return m_fieldWidth;
	}

	void Utilities::setDelimiter(const char d) {
		m_delim = d;
	}

	void Utilities::setFieldWidth(size_t fw) {
		m_fieldWidth = fw;
	}
}
