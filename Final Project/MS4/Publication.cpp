/* Citation and Sources...
Final Project Milestone 2
Module: Publication
Filename: Publication.cpp
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

#include <cstring>
#include <iostream>
#include "Publication.h"
#include <iomanip>

using namespace std;
namespace sdds {
	Publication::Publication() : m_date(Date()) {
		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
	}

	Publication::~Publication() {
		delete[] m_title;
	}

	void Publication::clearAttributes() {
		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		resetDate();
	}

	void Publication::set(int member_id) {
		m_membership = member_id;
	}

	void Publication::setRef(int value) {
		m_libRef = value;
	}

	void Publication::resetDate() {
		m_date = Date();
	}

	char Publication::type() const {
		return 'P';
	}

	bool Publication::onLoan()const {
		return (m_membership != 0);
	}

	Date Publication::checkoutDate()const {
		return m_date;
	}

	bool Publication::operator==(const char* title)const {
		if (strstr(m_title, title) != nullptr) {
			return true;
		}
		return false;
	}

	Publication::operator const char* ()const {
		return m_title;
	}

	Publication::operator bool() const {
		return (m_title != nullptr && m_shelfId[0] != '\0');
	}

	Publication::Publication(const Publication& publication) {
		*this = publication;
	}

	Publication& Publication::operator=(const Publication& publication) {
		set(publication.m_membership);
		setRef(publication.m_libRef);
		strCpy(m_shelfId, publication.m_shelfId);
		m_date = publication.m_date;

		if (m_title)
		{
			delete[] m_title;
			m_title = nullptr;
		}

		// Deep Copying
		if (publication.m_title != nullptr) {
			m_title = new char[strlen(publication.m_title) + 1];
			strCpy(m_title, publication.m_title);
		}
		else {
			m_title = nullptr;
		}

		return *this;
	}

	int Publication::getRef()const {
		return m_libRef;
	}

	bool Publication::conIO(const std::ios& io) const {
		return (&io == &std::cin) || (&io == &std::cout);
	}

	std::ostream& Publication::write(std::ostream& os) const {
		char limTitle[SDDS_TITLE_WIDTH + 1];
		strnCpy(limTitle, m_title, SDDS_TITLE_WIDTH);
		if (conIO(os)) {
			os << "| " << std::setw(SDDS_SHELF_ID_LEN) << std::setfill(' ') << m_shelfId << " | ";
			os << std::left << std::setw(SDDS_TITLE_WIDTH) << std::setfill('.') << limTitle << " | ";
			    onLoan() ? os << setfill(' ') << setw(5) << m_membership  : os << setw(3) << " N/A ";
				os << " | " << m_date << " |";
		}
		else {
			os << type() << "\t" << m_libRef << "\t" << m_shelfId << "\t" << m_title << "\t";
			onLoan() ? os << setfill(' ') << setw(5) << m_membership : os << setw(3) << " N/A ";
			os << "\t" << m_date;
		}
		return os;
	}

	std::istream& Publication::read(std::istream& istr) {
		

		char temp_title[256];
		char temp_shelfID[SDDS_SHELF_ID_LEN + 1];
		int temp_membership = 0, temp_libRef = 0;
		Date temp_date;

		if (m_title) {
			delete[] m_title;
		}
		clearAttributes();

		if (conIO(istr)) {
			cout << "Shelf No: ";
			istr.getline(temp_shelfID, SDDS_SHELF_ID_LEN + 1);
			if (strlen(temp_shelfID) != SDDS_SHELF_ID_LEN) {
				istr.setstate(std::ios::failbit);
			}
			cout << "Title: ";
			istr.getline(temp_title, 256);
			cout << "Date: ";
			istr >> temp_date;
		}
		else {
			istr >> temp_libRef;
			istr.ignore();
			istr.getline(temp_shelfID, SDDS_SHELF_ID_LEN + 1, '\t');
			istr.getline(temp_title, 256, '\t');
			istr >> temp_membership;
			istr >> temp_date;
			//istr.ignore();
		}

		if (!temp_date) {
			istr.setstate(std::ios::failbit);
		}

		if (istr) {
			m_title = new char[strLen(temp_title) + 1];
			m_title[0] = '\0';
			m_shelfId[0] = '\0';
			strCpy(m_title, temp_title);
			strCpy(m_shelfId, temp_shelfID);
			m_membership = temp_membership;
			m_libRef = temp_libRef;
			m_date = temp_date;
		}

		return istr;
	}
}