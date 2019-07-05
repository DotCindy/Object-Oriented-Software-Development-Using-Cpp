/*
Name:   Cindy Le
Email:  cle15@myseneca.ca
Date:   Mar 28, 2019
OOP345 - Milestone 3
*/

#include "LineManager.h"

namespace sict {
	LineManager::LineManager(std::vector<Station*>& station, std::vector<size_t>& size, std::vector<CustomerOrder> custorder, size_t index, std::ostream& os)
		: v_station(station), v_index(index), v_custOrder(custorder), m_count(index), m_next(v_index.at(m_count)), o_stream(&os) {}

	void LineManager::display(std::ostream& os) const {
		for (size_t i = 0; i < v_custOrder.size(); i++) {
			if (!v_custOrder[i].isFilled()) {
				v_custOrder[i].display(os);
			}
		}
	}

	bool LineManager::run(std::ostream& os) {
		bool runComplete = false;
		for (size_t i = 0; i < v_station.size(); i++) {
			if (!this->v_custOrder[v_custOrder.size()].isFilled()) {
				v_station[this->v_index[i]]->operator+=(std::move(v_custOrder[i]));
				v_station[this->v_index[i]]->fill(os);
			}
			runComplete = true;
		}
		return runComplete;
	}
}
