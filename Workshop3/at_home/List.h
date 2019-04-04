/*
Name:   Cindy Le
Email:  cle15@myseneca.ca
Date:   Jan 30, 2018
OOP345 - Workshop 3
*/

#ifndef SICT_LIST_H
#define SICT_LIST_H

#include <iostream>

namespace sict {
	template <typename T, int N>
	class List {
		T t[N];
		size_t n{ 0u };
	public:
		size_t size() const {
			return n;
		}

		const T& operator[](size_t i) const {
			return t[i];
		}

		void operator+=(const T& tt) {
			if (n < N) {
				t[n++] = tt;
			}
		}
	};

	template <typename T, typename L, typename V, int N>
	class LVList : public List<T, N> {
	public:
		V accumulate(const L& label) const {
			SummableLVPair<L, V> summable;
			V LVListSum = summable.getInitialValue();

			for (size_t i = 0; i < ((List<T, N>&)*this).size(); i++) {
				if (label == ((List<T, N>&)*this)[i].getLabel()) {
					LVListSum = ((List<T, N>&)*this)[i].sum(label, LVListSum);
				}
			}
			return LVListSum;
		}
	};
}

#endif
