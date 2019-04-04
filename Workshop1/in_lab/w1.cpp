/*
Name:   Cindy Le
Email:  cle15@myseneca.ca
Date:   Jan 17, 2018
OOP345 - Workshop 1
*/

#include <iostream>
#include "process.h"

int main(int argc, char* argv[]) {
	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}

	if (argc < 2) {
		std::cout << "***Insufficient number of arguments***" << std::endl;
		return 1;
	}

	std::cout << std::endl;

	for (int i = 1; i < argc; i++) {
		sict::process(argv[i]);
	}

	return 0;
}
