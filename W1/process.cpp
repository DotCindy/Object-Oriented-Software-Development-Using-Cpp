/*
Name:	Cindy Le
Email:	cle15@myseneca.ca
Date:	Sep 13, 2018
OOP345 - Workshop 1
*/

#include <iostream>
#include "CString.h"
#include "process.h"

int count = 0;
void process(const char* str, std::ostream& os) {
	w1::CString foo(str);
	os << count++ << ": " << foo << std::endl;

}
