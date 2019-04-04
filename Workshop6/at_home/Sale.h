/*
Name:   Cindy Le
Email:  cle15@myseneca.ca
Date:   Mar 6, 2019
OOP345 - Workshop 6
*/

#ifndef SICT_SALE_H
#define SICT_SALE_H
#include <iostream>
#include <vector>
#include "Product.h"

namespace sict {
	class Sale {
		std::vector<iProduct*> m_prod;
	public:
		explicit Sale(const char* file);
		void display(std::ostream& os) const;
	};
}

#endif
