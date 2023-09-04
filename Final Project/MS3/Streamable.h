/* Citation and Sources...
Final Project Milestone 2
Module: Streamable
Filename: Streamable.h
Version 1.0
Author	Ashwin Pandey

Revision History
-----------------------------------------------------------
Date      Reason
2023/07/15  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_STREAMABLE_H__
#define SDDS_STREAMABLE_H__


#include <iostream>
namespace sdds {
	class Streamable {
	public:
		virtual std::ostream& write(std::ostream&) const = 0;
		virtual std::istream& read(std::istream&) = 0;
		virtual bool conIO(const std::ios&) const = 0;
		virtual operator bool() const = 0;
		virtual ~Streamable() {};
	};
	std::istream& operator>>(std::istream&, Streamable&);
	std::ostream& operator<<(std::ostream&, const Streamable&);
}

#endif //!SDDS_STREAMABLE_H__