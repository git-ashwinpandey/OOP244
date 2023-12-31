/*
Full Name  : Ashwin Pandey
Student ID#: 156027211
Email      : apandey21@myseneca.ca
*/

#ifndef _SDDS_LINE_H_
#define _SDDS_LINE_H_

#include "LblShape.h"

namespace sdds {
	class Line : public LblShape{
		int m_length;

	public:
		Line();
		Line(const char*, int);

		void getSpecs(std::istream& is);

		void draw(std::ostream& os) const;
	};
}

#endif // !_SDDS_LINE_H_