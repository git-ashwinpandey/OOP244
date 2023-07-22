/*
Full Name  : Ashwin Pandey
Student ID#: 156027211
Email      : apandey21@myseneca.ca
*/

#include <string.h>
#include "Rectangle.h"

using namespace std;
namespace sdds {
	Rectangle::Rectangle() : LblShape() {
		m_width = 0;
		m_height = 0;
	}

	Rectangle::Rectangle(const char* label, int width, int height) : LblShape(label) {
		
		m_width = width;
		m_height = height;

		if (m_height < 3 || m_width < (int)(strlen(label) + 2)) {
			m_width = 0;
			m_height = 0;
		}
	}

	void Rectangle::getSpecs(std::istream& is) {
		LblShape::getSpecs(is);
		is >> m_width;
		is.ignore(1, ',');
		is >> m_height;
		is.ignore(100, '\n');
	}

	void Rectangle::draw(std::ostream& os) const {
		if (m_width > 0 && m_height > 0 && label() != nullptr) {
			// First line
			os << '+';
			for (int i = 0; i < m_width - 2; i++)
				os << '-';
			os << '+' << std::endl;

			// Second line
			os << '|' << label();
			for (int i = strlen(label()); i < m_width - 2; i++)
				os << ' ';
			os << '|' << std::endl;

			// Remaining lines
			for (int i = 0; i < m_height - 3; i++) {
				os << '|';
				for (int j = 0; j < m_width - 2; j++)
					os << ' ';
				os << '|' << std::endl;
			}

			// Last line
			os << '+';
			for (int i = 0; i < m_width - 2; i++)
				os << '-';
			os << '+';
		}
	}
}