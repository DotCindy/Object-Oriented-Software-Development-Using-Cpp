/*
Name:   Cindy Le
Email:  cle15@myseneca.ca
Date:   Feb 7, 2019
OOP345 - Workshop 4
*/

#ifndef SICT_MESSAGEPACK_H
#define SICT_MESSAGEPACK_H

#include <iostream>
#include "Message.h"

namespace sict {
	class MessagePack {
		Message* p_message;
		size_t no_msg;
	public:
		MessagePack();
		MessagePack(Message* message[], int max);

		MessagePack(const MessagePack& mp);
		MessagePack& operator=(const MessagePack& mp);
		MessagePack(MessagePack&& mp);
		MessagePack& operator=(MessagePack&& mp);

		void display(std::ostream& os) const;
		size_t size() const;

		~MessagePack();
	};
	std::ostream& operator<<(std::ostream& os, const MessagePack& mp);
}

#endif
