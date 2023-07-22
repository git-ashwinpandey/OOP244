/*
Full Name  : Ashwin Pandey
Student ID#: 156027211
Email      : apandey21@myseneca.ca
*/

#include <string.h>
#include <cstring>
#include "LblShape.h"

using namespace std;
namespace sdds {
	LblShape::LblShape() {
		m_label = nullptr;
	}

	LblShape::LblShape(const char* label) {
		m_label = nullptr;
		if (label != nullptr) {
			m_label = new char[strlen(label) + 1];
			strcpy(m_label, label);
		}
	}

	const char* LblShape::label() const {
		return m_label;
	}

	void LblShape::getSpecs(std::istream& is)  {
		char temp[50];
		is.getline(temp, 100, ',');
		if (m_label != nullptr) {
			delete[] m_label;
		}
		m_label = new char[strlen(temp) + 1];
		strcpy(m_label, temp);
	}

	LblShape::~LblShape() {
		delete[] m_label;
	}
}
