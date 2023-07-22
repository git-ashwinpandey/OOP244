/*
Full Name  : Ashwin Pandey
Student ID#: 156027211
Email      : apandey21@myseneca.ca
*/

#ifndef _SDDS_RECTANGLE_H_
#define _SDDS_RECTANGLE_H_

#include "LblShape.h"

namespace sdds {
	class Rectangle : public LblShape {
		int m_width;
		int m_height;
		
	public:
		Rectangle();
		Rectangle(const char*, int, int);
		void getSpecs(std::istream& is);
		void draw(std::ostream& os) const;
	};
}

#endif // !_SDDS_RECTANGLE_H_