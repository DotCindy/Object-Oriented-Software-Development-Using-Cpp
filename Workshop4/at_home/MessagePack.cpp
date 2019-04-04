/*
Name:   Cindy Le
Email:  cle15@myseneca.ca
Date:   Feb 7, 2019
OOP345 - Workshop 4
*/

#include "MessagePack.h"

namespace sict {
	MessagePack::MessagePack() : p_message(nullptr), no_msg(0) {}

	MessagePack::MessagePack(Message* message[], int max) {
		if (max > 0 && message != nullptr) {
			this->p_message = new Message[max];
			no_msg = 0;
			for (int i = 0; i < max; i++) {
				if (!message[i]->empty()) {
					this->p_message[no_msg++] = *message[i];
				}
			}
		}
	}

	MessagePack::MessagePack(const MessagePack& mp) {
		*this = mp;
	}
	
	MessagePack& MessagePack::operator=(const MessagePack& mp) {
		if (&mp != this) {
			no_msg = mp.no_msg;

			delete[] p_message;
			p_message = new Message[no_msg];

			for (int i = 0; i < no_msg; i++) {
				p_message[i] = mp.p_message[i];
			}
		}
		return *this;
	}

	MessagePack::MessagePack(MessagePack&& mp) {
		*this = std::move(mp);
	}

	MessagePack& MessagePack::operator=(MessagePack&& mp) {
		if (&mp != this) {
			delete[] p_message;
			no_msg = mp.no_msg;
			p_message = mp.p_message;
			mp.no_msg = 0;
			mp.p_message = nullptr;
		}
		return *this;
	}

	void MessagePack::display(std::ostream& os) const {
		for (int i = 0; i < no_msg; i++) {
			if (!p_message[i].empty()) {
				p_message[i].display(os);
			}
		}
	}

	size_t MessagePack::size() const {
		return no_msg;
	}

	MessagePack::~MessagePack() {
		delete[] p_message;
	}

	std::ostream& operator<<(std::ostream& os, const MessagePack& mp) {
		mp.display(os);
		return os;
	}
}
