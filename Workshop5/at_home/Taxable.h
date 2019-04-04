/*
Name:   Cindy Le
Email:  cle15@myseneca.ca
Date:   Feb 18, 2019
OOP345 - Workshop 5
*/

#ifndef SICT_TAXABLE_H
#define SICT_TAXABLE_H

namespace sict {
	class Taxable {
		float m_tax;
	public:
		Taxable(float tax) : m_tax{ tax } {}

		float operator()(float price) {
			return (price * (m_tax + 1));
		}
	};
}

#endif
