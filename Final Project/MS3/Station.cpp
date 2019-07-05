/*
Name:   Cindy Le
Email:  cle15@myseneca.ca
Date:   Mar 28, 2019
OOP345 - Milestone 3
*/

#include "Station.h"

namespace sict {
	Station::Station(std::string& str) {
		this->m_itemSet = new ItemSet(str);
	}

	void Station::display(std::ostream& os) const {
		m_itemSet->display(os, m_itemSet->getQuantity());
	}

	void Station::fill(std::ostream& os) {
		if (d_custOrder.size() > 0) {
			if (!d_custOrder[d_custOrder.size()]->isFilled()) {
				d_custOrder[d_custOrder.size()]->isFilled();
			}
		}
	}

	const std::string& Station::getName() const {
		return m_itemSet->getName();
	}

	bool Station::hasAnOrderToRelease() const {
		bool release = false;
		if (d_custOrder[0]->isFilled() || m_itemSet->getQuantity() == 0) {
			release = true;
		}
		return release;
	}

	Station& Station::operator--() {
		--m_itemSet;
		return *this;
	}

	Station& Station::operator+=(CustomerOrder&& order) {
		d_custOrder.push_back(&order);
		return *this;
	}

	bool Station::pop(CustomerOrder& ready) {
		bool filled = false;
		d_custOrder.pop_back();
		if (ready.isFilled()) {
			filled = true;
		}
		return filled;
	}

	void Station::validate(std::ostream& os) const {
		os << " getItem(): " << m_itemSet->getName() << std::endl;
		os << " getSerialNumber(): " << m_itemSet->getSerialNumber() << std::endl;
		os << " getQuantity(): " << m_itemSet->getQuantity() << std::endl;
	}
}
