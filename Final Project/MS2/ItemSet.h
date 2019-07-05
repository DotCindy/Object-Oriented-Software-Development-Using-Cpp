/*
Name:   Cindy Le
Email:  cle15@myseneca.ca
Date:   Mar 4, 2019
OOP345 - Milestone 1
*/

#ifndef SICT_ITEMSET_H
#define SICT_ITEMSET_H
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

namespace sict {
	class ItemSet {
		std::string m_name;
		std::string m_description;
		unsigned int m_serialNum;
		unsigned int m_quantity;
		static size_t m_fieldWidth;
	public:
		ItemSet(std::string& str);
		const std::string& getName() const;
		const unsigned int getSerialNumber() const;
		const unsigned int getQuantity() const;
		ItemSet& operator--();
		void display(std::ostream& os, bool full) const;
	};
}

#endif
