/*
Name:   Cindy Le
Email:  cle15@myseneca.ca
Date:   Mar 6, 2019
OOP345 - Workshop 6
*/

#include "Sale.h"

extern int FW;

namespace sict {
	Sale::Sale(const char* file) {
		std::string buffer;
		int count = 0;
		std::ifstream fs;
		fs.open(file);
		if (fs.is_open()) {
			while (std::getline(fs, buffer)) {
				count++;
			}
			fs.clear();
			fs.seekg(0, std::ios::beg);
			for (int i = 0; i < count; i++) {
				m_prod.push_back(readRecord(fs));
			}
			fs.close();
		}
	}

	void Sale::display(std::ostream& os) const {
		double total = 0.0;
		os << "Product No" << std::setw(FW) << "Cost" << std::endl;
		for (auto& i : m_prod) {
			os << *i;
			os << std::fixed << std::setprecision(2) << std::endl;
			total += i->price();
		}
		os << std::setw(FW) << "Total" << std::setw(FW) << total << std::endl;
	}
}
