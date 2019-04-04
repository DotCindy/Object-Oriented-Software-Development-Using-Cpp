/*
Name:   Cindy Le
Email:  cle15@myseneca.ca
Date:   Feb 7, 2019
OOP345 - Workshop 4
*/

#ifndef SICT_NOTIFICATIONS_H
#define SICT_NOTIFICATIONS_H

#include <iostream>
#include "Message.h"

namespace sict {
	class Notifications {
		const Message** ap_message;
		size_t max_addr;
		size_t no_addr;
	public:
		Notifications();
		Notifications(int max);

		Notifications(Notifications&);
		Notifications& operator=(const Notifications&);
		Notifications(Notifications&&);
		Notifications& operator=(Notifications&&);

		Notifications& operator+=(const Message& msg);
		Notifications& operator-=(const Message& msg);
		void display(std::ostream& os) const;
		size_t size() const;

		~Notifications();
	};
	std::ostream& operator<<(std::ostream&, const Notifications&);
}

#endif
