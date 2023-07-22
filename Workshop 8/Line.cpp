/*
Full Name  : Ashwin Pandey
Student ID#: 156027211
Email      : apandey21@myseneca.ca
*/

#include "Line.h"

using namespace std;
namespace sdds {
	Line::Line() {
		m_length = 0;
	}

	Line::Line(const char* tempString, int length) : LblShape(tempString) {
		m_length = length;
	}

	void Line::getSpecs(std::istream& is) {
		LblShape::getSpecs(is);
		is >> m_length;
		is.ignore(100, '\n');
	}


	void Line::draw(std::ostream& os) const{
		if (m_length > 0 && label() != nullptr) {
			os << label() << endl;
			for (int i = 0; i < m_length; i++) {
				os << '=';
			}
			//os << endl;
		}
	}
}