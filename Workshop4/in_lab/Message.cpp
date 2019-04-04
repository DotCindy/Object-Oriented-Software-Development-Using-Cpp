/*
Name:   Cindy Le
Email:  cle15@myseneca.ca
Date:   Feb 7, 2019
OOP345 - Workshop 4
*/

#include <iostream>
#include <string>
#include <fstream>
#include "Message.h"

namespace sict {
	Message::Message() {
		m_user = "";
		m_reply = "";
		m_tweet = "";
		m_file = "";
		b_reply = false;
	}

	Message::Message(const std::string& str) {
		m_file = str;
		size_t pos = 0;
		size_t reply_pos = 0;
		size_t past_end = std::string::npos;
		size_t reply_begin = str.find('@');
		size_t tweet_begin = str.find(' ');
		b_reply = false;

		m_user = str.substr(pos, tweet_begin);	//getting user

		if (m_user.length() != m_file.length()) {
			if (reply_begin != past_end) {
				b_reply = true;
				pos = reply_begin + 1;
				reply_pos = str.find(' ', pos + 1);
				m_reply = str.substr(pos, reply_pos - reply_begin - 1);	//reply
				pos = reply_pos + 1;	//position of begining of tweet
				m_tweet = str.substr(pos, past_end); //getting tweet
			}
			else {
				b_reply = false;
				pos = tweet_begin + 1;	//position of begining of tweet
				m_tweet = str.substr(pos, past_end); //getting tweet
			}
		}
		else {
			*this = Message();
		}
	}

	bool Message::empty() const {
		if (m_tweet.length() < 1 || m_user.length() < 1) {
			return true;
		}
		else {
			return false;
		}
	}

	void Message::display(std::ostream& os) const {
		if (m_user.length() > 1) {
			os << ">User  : " << m_user << std::endl;
			if (m_reply.length() > 0) {
				os << " Reply : " << m_reply << std::endl;
			}
			os << " Tweet : " << m_tweet << std::endl;
		}
	}
}
