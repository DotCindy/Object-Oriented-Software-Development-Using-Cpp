/*
Name:	Cindy Le
Email:	cle15@myseneca.ca
Date:	Sep 20, 2018
OOP345 - Workshop 2
*/

#ifndef W2_TEXT_H
#define W2_TEXT_H
#include <string>
#include <fstream>

namespace w2 {
	class Text {
		std::string* p_str;				//array of strings
		size_t m_size;					//number of records
	public:
		Text(const std::string file = "");	//constructor
		Text(const Text&);				//copy constructor
		Text& operator=(const Text&);	//copy assignment operator
		Text(Text&&);					//move constructor
		Text& operator=(Text&&);		//move assignment operator
		~Text();						//destructor
		size_t size() const;			//returns number of records
	};
}

#endif
