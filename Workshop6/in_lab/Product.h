/*
Name:   Cindy Le
Email:  cle15@myseneca.ca
Date:   Mar 6, 2019
OOP345 - Workshop 6
*/

#ifndef SICT_PRODUCT_H
#define SICT_PRODUCT_H
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

namespace sict {
	class iProduct {
	public:
		virtual double price() const = 0;
		virtual void display(std::ostream& os) const = 0;
	};

	std::ostream& operator<<(std::ostream& os, const iProduct& p);
	iProduct* readRecord(std::ifstream& file);

	class Product : public iProduct {
		double m_price;
		std::string m_productNo;
	public:
		Product(std::string& product, double price);
		double price() const;
		void display(std::ostream& os) const;
	};
}

#endif
