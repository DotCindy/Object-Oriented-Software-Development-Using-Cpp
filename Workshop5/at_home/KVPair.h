/*
Name:   Cindy Le
Email:  cle15@myseneca.ca
Date:   Feb 18, 2019
OOP345 - Workshop 5
*/

#ifndef SICT_KVPAIR_H
#define SICT_KVPAIR_H

#include <iostream>
#include <iomanip>

extern int fieldWidth;

namespace sict {
	template<typename K, typename V>
	class KVPair {
		K m_key;
		V m_value;
	public:
		KVPair() : m_key{ }, m_value{ } {}
		KVPair(const K& key, const V& value) : m_key{ key }, m_value{ value } {}
		
		template<typename F>
		void display(std::ostream& os, F f) const {
			os << std::left << std::setw(fieldWidth);
			os << m_key << " : ";
			os << std::right << std::setw(fieldWidth);
			os << m_value;
			os << std::setw(fieldWidth);
			os << f(m_value) << std::endl;
		}
	};
}

#endif
