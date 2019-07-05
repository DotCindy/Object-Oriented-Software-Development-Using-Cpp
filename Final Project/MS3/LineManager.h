/*
Name:   Cindy Le
Email:  cle15@myseneca.ca
Date:   Mar 28, 2019
OOP345 - Milestone 3
*/

#ifndef SICT_LINEMANAGER_H
#define SICT_LINEMANAGER_H
#include <iostream>
#include "Station.h"

namespace sict {
	class LineManager {
		std::vector <Station*> v_station;
		std::vector <size_t> v_index;
		std::vector <CustomerOrder> v_custOrder;
		size_t m_count;
		size_t m_next;
		std::ostream* o_stream;
	public:
		LineManager(std::vector<Station*>& station, std::vector<size_t>& size, std::vector<CustomerOrder> custorder, size_t index, std::ostream& os);
		void display(std::ostream& os) const;
		bool run(std::ostream& os);
	};
}

#endif
