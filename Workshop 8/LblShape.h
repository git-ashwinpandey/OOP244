/*
Full Name  : Ashwin Pandey
Student ID#: 156027211
Email      : apandey21@myseneca.ca
*/

#ifndef _SDDS_LBLSHAPE_H_
#define _SDDS_LBLSHAPE_H_

#include "Shape.h"

namespace sdds {
	class LblShape : public Shape {
		char* m_label;
		
	protected:
		const char* label() const;

	public:
		void getSpecs(std::istream& is);

		LblShape();
		LblShape(const char* label);
		~LblShape();

		LblShape(const LblShape&) = delete;
		LblShape& operator=(const LblShape&) = delete;
	};
}

#endif // !_SDDS_LBLSHAPE_H_