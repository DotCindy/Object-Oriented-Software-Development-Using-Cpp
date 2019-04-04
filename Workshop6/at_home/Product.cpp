/*
Name:   Cindy Le
Email:  cle15@myseneca.ca
Date:   Mar 6, 2019
OOP345 - Workshop 6
*/

#include "Product.h"

extern int FW;

namespace sict {
	std::ostream& operator<<(std::ostream& os, const iProduct& p) {
		p.display(os);
		return os;
	}

	iProduct* readRecord(std::ifstream& file) {
		iProduct* ptr = nullptr;
		std::string line = "";
		std::string product_num = "";
		double price = 0.0;
		char tax = ' ';
		while (std::getline(file, line, '\n')) {
			size_t count = std::count(line.begin(), line.end(), ' ');
			std::stringstream stream(line);
			if (count == 2) {
				stream >> product_num >> price >> tax;
				ptr = new TaxableProduct(product_num, price, tax);
				break;
			}
			if (count == 1) {
				stream >> product_num >> price >> tax;
				ptr = new Product(product_num, price);
				break;
			}
		}
		return ptr;
	}

	Product::Product(std::string& product, double price) 
		: m_productNo(product), m_price(price) {}

	double Product::price() const {
		return m_price;
	}

	void Product::display(std::ostream& os) const {
		os << std::setw(FW) << m_productNo << std::setw(FW) << m_price;
	}

	TaxableProduct::TaxableProduct(std::string& product, double price, char taxCode) 
	: Product(product, price) {
		m_taxCode = taxCode;
	}

	double TaxableProduct::price() const {
		double total;
		if (m_taxCode == 'H') {
			total = Product::price() * m_HST;
		}
		else if (m_taxCode == 'P') {
			total = Product::price() * m_PST;
		}
		else {
			total = Product::price();
		}
		return total;
	}

	void TaxableProduct::display(std::ostream& os) const {
		Product::display(os);
		if (m_taxCode == 'H') {
			os << " HST";
		}
		else if (m_taxCode == 'P') {
			os << " PST";
		}
		else {
			os << "";
		}
	}
}
