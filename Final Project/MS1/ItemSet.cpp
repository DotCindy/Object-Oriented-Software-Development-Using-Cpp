/*
Name:   Cindy Le
Email:  cle15@myseneca.ca
Date:   Mar 4, 2019
OOP345 - Milestone 1
*/

#include "ItemSet.h"
#include "Utilities.h"

namespace sict {
	size_t ItemSet::m_fieldWidth = 1;
	const int CODE_WIDTH = 5;
	const int QUAN_WIDTH = 3;
	ItemSet::ItemSet(std::string& str) {
		Utilities utl;
		std::string token;
		std::vector<std::string> tokens;
		size_t position = 0;
		bool more = true;

		while (more) {
			token = utl.extractToken(str, position);
			tokens.push_back(token);
			m_fieldWidth = (tokens.size() == 1 &&
				utl.getFieldWidth() > m_fieldWidth) ? utl.getFieldWidth() : m_fieldWidth;

			if (position == str.size()) {
				more = false;
			}
		}

		m_name = tokens[0];

		int serial = atoi(tokens[1].c_str());
		m_serialNum = serial;

		int qty = atoi(tokens[2].c_str());
		m_quantity = qty;

		m_description = tokens[3];
	}

	const std::string& ItemSet::getName() const {
		return m_name;
	}

	const unsigned int ItemSet::getSerialNumber() const {
		return m_serialNum;
	}

	const unsigned int ItemSet::getQuantity() const {
		return m_quantity;
	}

	ItemSet& ItemSet::operator--() {
		--m_quantity;
		m_serialNum++;
		return *this;
	}

	void ItemSet::display(std::ostream& os, bool full) const {
		os << std::setw(m_fieldWidth) << std::setfill(' ') << std::left
			<< m_name << " [" << std::setw(CODE_WIDTH) << std::setfill('0') << std::right
			<< m_serialNum << "]";
		if (full) {
			os << " Quantity " << std::setw(QUAN_WIDTH) << std::setfill(' ') << std::left << m_quantity
				<< " Description: " << m_description;
		}
		os << std::endl;
	}
}
