/*
Full Name  : Ashwin Pandey
Student ID#: 156027211
Email      : apandey21@myseneca.ca
*/

#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__

#include <iostream>
#include "cstring.h"

namespace sdds {
	class Text {
		char* m_filename;
		char* m_content;
		int getFileLength()const;
		void setEmpty();
	protected:
		const char& operator[](int index)const;
	public:
		Text(const char* filename = nullptr);
		Text(const Text& other);
		~Text();

		Text& operator=(const Text& other);
		operator int()const;

		void read();
		virtual void write(std::ostream& os)const;
	};

	std::ostream& operator<<(std::ostream& os, const Text& text);
}
#endif // !SDDS_TEXT_H__

