/*
Name:   Cindy Le
Email:  cle15@myseneca.ca
Date:   Feb 7, 2019
OOP345 - Workshop 4
*/

#include "Notifications.h"

namespace sict {
	Notifications::Notifications() : ap_message(nullptr), max_addr(0), no_addr(0) {}

	Notifications::Notifications(int max) {
		if (max > 0) {
			max_addr = max;
			ap_message = new const Message*[max];
			no_addr = 0;
		}
	}

	Notifications::Notifications(Notifications& n) {
		*this = n;
	}

	Notifications& Notifications::operator=(const Notifications& n) {
		if (&n != this) {
			max_addr = n.max_addr;
			no_addr = n.no_addr;

			delete[] ap_message;
			ap_message = *new const Message**[max_addr];

			for (int i = 0; i < max_addr; i++) {
				ap_message[i] = n.ap_message[i];
			}
		}
		return *this;
	}

	Notifications::Notifications(Notifications&& n) {
		*this = std::move(n);
	}

	Notifications& Notifications::operator=(Notifications&& n) {
		if (&n != this) {
			delete[] ap_message;
			ap_message = n.ap_message;
			max_addr = n.max_addr;
			no_addr = n.no_addr;
			n.ap_message = nullptr;
			n.max_addr = 0;
			n.no_addr = 0;
		}
		return *this;
	}

	Notifications& Notifications::operator+=(const Message& msg) {
		if (!msg.empty() && no_addr < max_addr) {
			ap_message[no_addr++] = &msg;
		}
		return *this;
	}

	Notifications& Notifications::operator-=(const Message& msg) {
		bool found = false;
		int i = 0;
		for (; i < no_addr && !found; i++) {
			if (ap_message[i] == &msg) {
				found = true;
			}
		}

		if (found) {
			for (; i < no_addr - 1; i++) {
				ap_message[i] = ap_message[i + 1];
			}
			ap_message[i] = nullptr;
			no_addr--;
		}
		return *this;
	}

	void Notifications::display(std::ostream& os) const {
		for (int i = 0; i < no_addr; i++) {
			(*ap_message[i]).display(os);
		}
	}

	size_t Notifications::size() const {
		return no_addr;
	}

	Notifications::~Notifications() {
		delete[] ap_message;
		ap_message = nullptr;
	}
	std::ostream& operator<<(std::ostream& os, const Notifications& n) {
		n.display(os);
		return os;
	}
}
