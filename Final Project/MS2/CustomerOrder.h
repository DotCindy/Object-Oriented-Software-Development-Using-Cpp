/*
Name:   Cindy Le
Email:  cle15@myseneca.ca
Date:   Mar 11, 2019
OOP345 - Milestone 2
*/

#ifndef SICT_CUSTOMERORDER_H
#define SICT_CUSTOMERORDER_H
#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
#include <iomanip>
#include <vector>
#include "ItemSet.h"
#include "Utilities.h"

namespace sict {
	class CustomerOrder {
		struct ItemInfo {
			std::string s_itemName;
			std::string s_serialNum;
			bool s_fillState;
			ItemInfo() : s_itemName{ "" }, s_serialNum{ 0 }, s_fillState{ false } {}
		};

		std::string m_customer;
		std::string m_product;
		int m_countItem;
		ItemInfo* m_listItem;
		static size_t m_fieldWidth;
	public:
		CustomerOrder();
		CustomerOrder(const std::string& str);
		CustomerOrder(const CustomerOrder&) = delete;
		CustomerOrder& operator=(const CustomerOrder&) = delete;
		CustomerOrder(CustomerOrder&& other);
		CustomerOrder& operator=(CustomerOrder&& other);
		~CustomerOrder();
		void fillItem(ItemSet& item, std::ostream& os);
		bool isFilled() const;
		bool isItemFilled(const std::string& item) const;
		std::string getNameProduct() const;
		void display(std::ostream& os, bool showDetail = false) const;
	};
}

#endif
