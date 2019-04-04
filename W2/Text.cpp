/*
Name:	Cindy Le
Email:	cle15@myseneca.ca
Date:	Sep 20, 2018
OOP345 - Workshop 2
*/

#include "Text.h"

namespace w2 {
	Text::Text(const std::string file) {
		std::fstream fs(file);
		std::string newLine;
		int count = 0;

		if (fs.fail()) {
			m_size = 0;
			delete[] p_str;
		}
		else {
			while(getline(fs, newLine)) {
				count++;
			}
			fs.close();
			m_size = count;
			p_str = new std::string[m_size];

			fs.open(file);
			count = 1;
			while (getline(fs, newLine)) {
				p_str[count] = newLine;
				count++;
			}
		}
	}

	//copy constructor
	Text::Text(const Text& obj) {
		*this = obj;
	}

	//copy assignment operator
	Text& Text::operator=(const Text& obj) {
		if (this != &obj) {
			m_size = obj.m_size;
			delete[] this->p_str;
			p_str = new std::string[m_size];
			for (int i = 0; i < m_size; i++) {
				p_str[i] = obj.p_str[i];
			}
		}
		return *this;
	}

	//move constructor
	Text::Text(Text&& obj) {
		*this = std::move(obj);
	}

	//move assignment operator
	Text& Text::operator=(Text&& obj) {
		if (this != &obj) {
			m_size = obj.m_size;
			delete[] this->p_str;
			p_str = obj.p_str;
			obj.p_str = nullptr;
		}
		return *this;
	}

	//destructor
	Text::~Text() {
		delete[] p_str;
		p_str = nullptr;
	}

	//returns number of records of text data
	size_t Text::size() const {
		return m_size;
	}
}
