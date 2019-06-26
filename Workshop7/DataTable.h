/*
Name:   Cindy Le
Email:  cle15@myseneca.ca
Date:   Mar 14, 2019
OOP345 - Workshop 7
*/

#ifndef SICT_DATA_TABLE_H
#define SICT_DATA_TABLE_H

#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <algorithm>

extern int FW;
extern int ND;

namespace sict {
	template<typename T>
	class DataTable {
		std::vector<T> x;
		std::vector<T> y;
	public:
		DataTable(std::ifstream& file) {
			while (file.good()) {
				std::string line;
				std::getline(file, line);

				std::stringstream ss;

				if (!line.empty()) {
					ss.str(line);
					T xx, yy;
					ss >> xx >> yy;
					x.push_back(xx);
					y.push_back(yy);
				}
			}
		}

		T mean() const {
			T total = std::accumulate(y.begin(), y.end(), (T)0.0);
			return total / y.size();
		}

		T sigma() const {
			T f_mean = mean();
			T total = 0.0;
			for (size_t i = 0; i < y.size(); i++) {
				total += (y[i] - f_mean) * (y[i] - f_mean);
			}
			return std::sqrt(total / (y.size() - 1));
		}

		T median() const {
			std::vector <T> yy = y;
			std::sort(yy.begin(), yy.end());
			return yy[yy.size() / 2];
		}

		T slope() const {
			T xSize = x.size();
			T ySize = y.size();

			T xSum = std::accumulate(x.begin(), x.end(), 0.0) / xSize;
			T ySum = std::accumulate(y.begin(), y.end(), 0.0) / ySize;

			T numerator = 0.0;
			T denominator = 0.0;

			for (size_t i = 0; i < xSize; i++) {
				numerator += (x[i] - xSum) * (y[i] - ySum);
				denominator += (x[i] - xSum) * (x[i] - xSum);
			}
			return numerator / denominator;
		}

		T intercept() const {
			T xSize = x.size();
			T ySize = y.size();

			T xSum = std::accumulate(x.begin(), x.end(), 0.0) / xSize;
			T ySum = std::accumulate(y.begin(), y.end(), 0.0) / ySize;

			T numerator = 0.0;
			T denominator = 0.0;

			for (size_t i = 0; i < xSize; i++) {
				numerator += (x[i] - xSum) * (y[i] - ySum);
				denominator += (x[i] - xSum) * (x[i] - xSum);
			}

			return ySum - (slope() * xSum);
		}

		void displayData(std::ostream& os) const {
			os << "Data Values" << std::endl;
			os << "------------" << std::endl;
			os << std::setw(FW) << "x" << std::setw(FW) << "y" << std::endl;
			for (size_t i = 0; i < x.size(); i++) {
				os << std::setw(FW) << std::fixed << std::setprecision(ND) << x[i];
				os << std::setw(FW) << std::fixed << std::setprecision(ND) << y[i];
				os << std::endl;
			}
			os << std::endl;
		}

		void displayStatistics(std::ostream& os) const {
			os << "Statistics" << std::endl;
			os << "----------" << std::endl;
			os << "  y mean    = " << std::setw(FW) << mean() <<  std::endl;
			os << "  y sigma   = " << std::setw(FW) << sigma() << std::endl;
			os << "  y median  = " << std::setw(FW) << median() << std::endl;
			os << "  slope     = " << std::setw(FW) << slope() << std::endl;
			os << "  intercept = " << std::setw(FW) << intercept() << std::endl;
		}
	};
}

#endif
