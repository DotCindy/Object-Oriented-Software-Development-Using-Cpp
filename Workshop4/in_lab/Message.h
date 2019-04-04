/*
Name:   Cindy Le
Email:  cle15@myseneca.ca
Date:   Feb 7, 2019
OOP345 - Workshop 4
*/

#define _CRT_SECURE_NO_WARNINGS
#ifndef SICT_MESSAGE_H
#define SICT_MESSAGE_H

#include <iostream>
#include <string>

namespace sict {
	class Message {
		std::string m_user;
		std::string m_reply;
		std::string m_tweet;
		std::string m_file;
		bool b_reply;
	public:
		Message();
		Message(const std::string& str);
		bool empty() const;
		void display(std::ostream& os) const;
	};
}

#endif
