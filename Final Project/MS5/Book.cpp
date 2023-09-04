/* Citation and Sources...
Final Project Milestone 5
Module: Book
Filename: Book.cpp
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

#include "Book.h"
#include <iomanip>

using namespace std;
namespace sdds {
	void Book::setEmpty() {
		delete[] m_author;
		m_author = nullptr;
	}

	Book::Book() : Publication() {
		m_author = nullptr;
	}

	Book::~Book() {
		delete[] m_author;
	}

	Book::Book(const Book& other) : Publication(other) {
		if (m_author != nullptr) {
			setEmpty();
		}
		if (other) {
			m_author = new char[strLen(other.m_author) + 1];
			strCpy(m_author, other.m_author);
		}
	}

	Book& Book::operator=(const Book& other) {
		if (this == &other) // Self-assignment check
			return *this;

		//Call base assignment
		Publication::operator=(other);

		if (m_author != nullptr) {
			setEmpty();
		}

		//Deep copy title
		if (other.m_author != nullptr) {
			m_author = new char[strLen(other.m_author) + 1];
			strCpy(m_author, other.m_author);
		}
		else {
			m_author = nullptr;
		}

		return *this;
	}

	Book::operator bool()const {
		return (m_author != nullptr && Publication::operator bool());
	}

	char Book::type() const {
		return 'B';
	}

	std::ostream& Book::write(std::ostream& os) const {
		Publication::write(os);

		char limAuthor[SDDS_AUTHOR_WIDTH + 1];
		strnCpy(limAuthor, m_author, SDDS_AUTHOR_WIDTH);
		if (conIO(os)) {
			os << " ";
			os << std::setw(SDDS_AUTHOR_WIDTH) << std::left << std::setfill(' ') << limAuthor << " |";
		}
		else {
			os << "\t" << m_author;
		}

		return os;
	}

	std::istream& Book::read(std::istream& istr) {
		char temp_author[SDDS_MAX_CHAR];
		
		Publication::read(istr);

		if (m_author != nullptr) {
			setEmpty();
		}
		

		if (conIO(istr)) {
			istr.ignore();
			cout << "Author: ";
			
		}
		else {
			istr.ignore(1000, '\t'); 
		}

		istr.get(temp_author, SDDS_MAX_CHAR);

		if (istr) {
			m_author = new char[strLen(temp_author) + 1];
			strCpy(m_author, temp_author);
		}

		return istr;
	}

	void Book::set(int member_id) {
		Publication::set(member_id);
		resetDate();
	}

}