/*
Name:   Cindy Le
Email:  cle15@myseneca.ca
Date:   Mar 11, 2019
OOP345 - Milestone 2
*/

#include "CustomerOrder.h"

namespace sict {
	size_t CustomerOrder::m_fieldWidth = 1;
	size_t WD = 13;

	CustomerOrder::CustomerOrder() {
		m_customer = "";
		m_product = "";
		m_countItem = 0;
		m_listItem = nullptr;
	}

	CustomerOrder::CustomerOrder(const std::string& str) {
		Utilities utl;
		std::string token;
		std::vector<std::string> tokens;
		size_t position = 0;
		bool more = true;

		while (more) {
			token = utl.extractToken(str, position);
			tokens.push_back(token);
			m_fieldWidth = (tokens.size() == 1 && utl.getFieldWidth() > m_fieldWidth) ? utl.getFieldWidth() : m_fieldWidth;
			if (position == str.size()) {
				more = false;
			}
		}
		
		size_t delim_pos = str.find(utl.getDelimiter());
		m_customer = str.substr(0, delim_pos);

		if (m_fieldWidth < utl.getFieldWidth()) {
			m_fieldWidth = utl.getFieldWidth();
		}

		m_product = utl.extractToken(str, delim_pos);

		m_customer = tokens[0];
		m_product = tokens[1];

		m_countItem = std::count(str.begin(), str.end(), utl.getDelimiter());
		m_listItem = new ItemInfo[m_countItem];

		if (m_countItem > 0) {
			for (int i = 0; i < m_countItem ; i++) {
				m_listItem[i].s_itemName = utl.extractToken(str, delim_pos);
			}
		}
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& other) {
		*this = std::move(other);
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& other) {
		if (this != &other) {
			m_customer = other.m_customer;
			m_product = other.m_product;
			m_countItem = other.m_countItem;
			m_listItem = other.m_listItem;

			other.m_listItem = { nullptr };
		}
		return *this;
	}

	CustomerOrder::~CustomerOrder() {
		delete[] m_listItem;
		m_listItem = { nullptr };
	}

	void CustomerOrder::fillItem(ItemSet& item, std::ostream& os) {
		for (int i = 0; i < m_countItem; i++) {
			if (m_listItem[i].s_itemName == item.getName()) {
				if (item.getQuantity() == 0) {
					os << " Unable to fill " << m_customer
						<< " [" << m_product << "]["
						<< m_listItem[i].s_itemName << "]["
						<< m_listItem[i].s_serialNum << "]"
						<< " out of stock" << std::endl;
				}
				else {
					if (m_listItem[i].s_fillState) {
						os << " Unable to fill " << m_customer
							<< " [" << m_product << "]["
							<< m_listItem[i].s_itemName << "]["
							<< m_listItem[i].s_serialNum << "]"
							<< " already filled" << std::endl;
					}
					else {
						m_listItem[i].s_serialNum = item.getSerialNumber();
						m_listItem[i].s_fillState = true;
						item.operator--();
						os << " Filled " << m_customer
							<< " [" << m_product << "]["
							<< m_listItem[i].s_itemName << "]["
							<< m_listItem[i].s_serialNum << "]" << std::endl;
					}
				}
			}
		}
	}

	bool CustomerOrder::isFilled() const {
		bool filled;
		for (int i = 0; i < m_countItem; i++) {
			if (m_listItem[i].s_fillState) {
				filled = true;
			}
			else {
				filled = false;
			}
		}
		return filled;
	}

	bool CustomerOrder::isItemFilled(const std::string& item) const {
		bool itemFilled;
		for (int i = 0; i < m_countItem; i++) {
			if (m_listItem[i].s_itemName == item) {
				if (m_listItem->s_fillState) {
					itemFilled = true;
				}
			}
			else {
				itemFilled = false;
			}
		}
		return itemFilled;
	}

	std::string CustomerOrder::getNameProduct() const {
		return std::string(m_customer) + "[" + std::string(m_product) + "]";
	}

	void CustomerOrder::display(std::ostream& os, bool showDetail) const {
		os << std::left << std::setw(WD) << m_customer 
			<< " [" << m_product << "]" << std::endl;

		if (showDetail) {
			for (int i = 0; i < m_countItem; i++) {
				os << std::setfill(' ') << std::setw(WD + 1) << " " << std::right << m_listItem[i].s_itemName << std::endl;
			}
		}
	}
}
