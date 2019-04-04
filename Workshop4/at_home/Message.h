/*
Name:   Cindy Le
Email:  cle15@myseneca.ca
Date:   Feb 7, 2019
OOP345 - Workshop 4
*/

#ifndef SICT_MESSAGE_H
#define SICT_MESSAGE_H

#include <iostream>
#include <string>

namespace sict {
	class Message {
		std::string m_user;
		std::string m_reply;
		std::string m_tweet;
	public:
		Message();
		Message(const std::string& str);
		bool empty() const;
		void display(std::ostream& os) const;
	};
}

#endif
