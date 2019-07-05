/*
Name:   Cindy Le
Email:  cle15@myseneca.ca
Date:   Mar 28, 2019
OOP345 - Milestone 3
*/

#ifndef SICT_STATION_H
#define SICT_STATION_H
#include <iostream>
#include <deque>
#include "CustomerOrder.h"
#include "ItemSet.h"

namespace sict {
	class Station {
		std::deque <CustomerOrder*> d_custOrder;
		ItemSet* m_itemSet;
	public:
		Station(std::string& str);
		Station(const Station&) = delete;
		Station& operator=(const Station&) = delete;
		Station(Station&&) = delete;
		Station& operator=(Station&&) = delete;

		void display(std::ostream& os) const;
		void fill(std::ostream& os);
		const std::string& getName() const;
		bool hasAnOrderToRelease() const;
		Station& operator--();
		Station& operator+=(CustomerOrder&& order);
		bool pop(CustomerOrder& ready);
		void validate(std::ostream& os) const;
	};
}

#endif
