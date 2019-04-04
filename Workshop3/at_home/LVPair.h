/*
Name:   Cindy Le
Email:  cle15@myseneca.ca
Date:   Jan 30, 2018
OOP345 - Workshop 3
*/

#ifndef SICT_LVPAIR_H
#define SICT_LVPAIR_H

#include <iostream>
#include <iomanip>

namespace sict {
	template<typename L, typename V>
	class LVPair {
		L m_label;
		V m_value;
	public:
		LVPair() {};
		LVPair(const L& label, const V& value)
			: m_label(label), m_value(value) {};
		
		const L& getLabel() const {
			return m_label;
		}

		const V& getValue() const {
			return m_value;
		}

		virtual void display(std::ostream& os) const {
			os << m_label << " : " << m_value << std::endl;
		}

	};

	template<typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair) {
		pair.display(os);
		return os;
	}

	template<typename L, typename V>
	class SummableLVPair : public LVPair<L, V> {
		static V m_initial;
		static size_t m_width;
	public:
		SummableLVPair() {};
		SummableLVPair(const L& label, const V& v)
			: LVPair<L, V>(label, v) {
			if (m_width < label.size()) {
				m_width = label.size() + 1;
			}
		};

		const V& getInitialValue() {
			return m_initial;
		}

		V sum(const L& label, const V& sum) const {
			V result = LVPair<L, V>::getValue() + sum;
			return result;
		}

		void display(std::ostream& os) const {
			os << std::left << std::setw(m_width);
			os << LVPair<L, V>::getLabel() << ": " << LVPair<L, V>::getValue() << std::endl;
		}
	};

	template<typename L, typename V>
	size_t SummableLVPair<L, V>::m_width = 0;

	template<>
	int SummableLVPair<std::string, int>::m_initial = 0;

	template<>
	std::string SummableLVPair<std::string, std::string>::m_initial = "";

	template<>
	std::string SummableLVPair<std::string, std::string>::sum(const std::string& label, const std::string& sum) const {
		std::string insertSpace = sum + " " + LVPair<std::string, std::string>::getValue();
		return insertSpace;
	}


}

#endif
