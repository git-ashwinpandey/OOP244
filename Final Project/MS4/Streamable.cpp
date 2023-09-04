/* Citation and Sources...
Final Project Milestone 2
Module: Streamable
Filename: Streamable.cpp
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

#include "Streamable.h"
namespace sdds {
	std::istream& operator>>(std::istream& is, Streamable& stream)
	{ 
		return stream.read(is);
	}

	std::ostream& operator<<(std::ostream& os, const Streamable& stream)
	{
		if (stream) {
			return stream.write(os);
		}
		return os;
	}


}