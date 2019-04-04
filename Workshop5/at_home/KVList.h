/*
Name:   Cindy Le
Email:  cle15@myseneca.ca
Date:   Feb 18, 2019
OOP345 - Workshop 5
*/


#ifndef SICT_KVLIST_H
#define SICT_KVLIST_H
#include <iostream>

namespace sict {
	template<typename T>
	class KVList {
		T* m_list;
		int m_current;
		int m_max;
	public:
		KVList() : m_list{ nullptr }, m_current{ 0 }, m_max{ 0 } {}
		
		KVList(int n) {
			if (n > 0) {
				m_list = new T[n];
				m_current = { 0 };
				m_max = { n };
			}
			else {
				m_list = { nullptr };
			}
		}

		KVList(const KVList& kv) = delete;

		KVList& operator=(const KVList& kv) = delete;

		KVList(KVList&& kv) {
			if (this != &kv) {
				m_list = kv.m_list;
				m_current = kv.m_current;
				m_max = kv.m_max;

				kv.m_list = { nullptr };
				kv.m_current = { 0 };
				kv.m_max = { 0 };
			}
		}

		KVList& operator=(KVList&& kv) = delete;

		~KVList() {
			delete[] m_list;
			m_list = { nullptr };
		}

		const T& operator[](size_t i) const {
			if (i < 0 || i > m_max) {
				throw("Index passed is out-of-bounds");
			}
			else {
				return m_list[i];
			}
		}
		
		template<typename F>
		void display(std::ostream& os, F f) const {
			for (int i = 0; i < m_max; i++) {
				m_list[i].display(os, f);
			}
		}

		void push_back(const T& t) {
			if (m_current < m_max) {
				m_list[m_current++] = t;
			}
		}
	};
}

#endif
