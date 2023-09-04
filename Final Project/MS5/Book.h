/* Citation and Sources...
Final Project Milestone 5
Module: Book
Filename: Book.h
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

#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__

#include "Publication.h"

namespace sdds {
	class Book : public Publication {
		char* m_author;
		
		void setEmpty();
	public:
		Book();
		~Book();
		Book(const Book& other);

		Book& operator=(const Book& other);

		// bool Conversion operator to check if the Book is valid (author + title + shelfid)
		operator bool()const;

		//Sets the membership id
		void set(int member_id = 0);

		//Type of Publication: return 'B' = Book, 'P' = Periodical
		char type()const;

		// Write Book data to output stream
		std::ostream& write(std::ostream& os) const;
		// Read Book data from input stream
		std::istream& read(std::istream& istr);
	};
}

#endif //!SDDS_BOOK_H__