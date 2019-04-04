/*
Name:   Cindy Le
Email:  cle15@myseneca.ca
Date:   Mar 6, 2019
OOP345 - Workshop 6
*/

#include "Product.h"

extern int FW;

namespace sict {
	Product::Product(std::string& product, double price) 
		: m_productNo(product), m_price(price) {}

	double Product::price() const {
		return m_price;
	}

	void Product::display(std::ostream& os) const {
		os << std::setw(FW) << m_productNo << std::setw(FW) << m_price;
	}

	std::ostream& operator<<(std::ostream& os, const iProduct& p) {
		p.display(os);
		return os;
	}

	iProduct* readRecord(std::ifstream& file) {
		iProduct* product = nullptr;
		std::string product_num = "";
		double price = 0.0;
		file >> product_num >> price;
		product = new Product(product_num, price);
		return product;
	}
}
