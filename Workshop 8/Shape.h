/*
Full Name  : Ashwin Pandey
Student ID#: 156027211
Email      : apandey21@myseneca.ca
*/

#ifndef _SDDS_SHAPE_H_
#define _SDDS_SHAPE_H_

#include <iostream>
namespace sdds {
	class Shape {
	public:
		virtual void draw(std::ostream& os) const = 0;
		virtual void getSpecs(std::istream& is) = 0;
		virtual ~Shape();
	};
	std::ostream& operator<<(std::ostream& os, const Shape& shape);
	std::istream& operator>>(std::istream& is, Shape& shape);
}

#endif // !_SDDS_SHAPE_H_