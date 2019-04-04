/*
Name:   Cindy Le
Email:  cle15@myseneca.ca
Date:   Jan 30, 2018
OOP345 - Workshop 3
*/

#ifndef SICT_LVPAIR_H
#define SICT_LVPAIR_H

#include <iostream>

namespace sict {
	template<typename L, typename V>
	class LVPair {
		L m_label;
		V m_value;
	public:
		LVPair() {};
		LVPair(const L& label, const V& value)
			: m_label(label), m_value(value) {};

		void display(std::ostream& os) const {
			os << m_label << " : " << m_value << std::endl;
		}

	};

	template<typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair) {
		pair.display(os);
		return os;
	}
}

#endif
