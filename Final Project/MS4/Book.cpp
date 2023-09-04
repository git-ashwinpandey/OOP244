#include "Book.h"
#include <iomanip>

using namespace std;
namespace sdds {
	void Book::setEmpty() {
		m_author = nullptr;
	}

	Book::Book() : Publication() {
		setEmpty();
	}

	Book::~Book() {
		delete[] m_author;
	}

	Book::Book(const Book& other) : Publication(other) {
		if (m_author != nullptr) {
			delete[] m_author;
			m_author = nullptr;
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
			delete[] m_author;
			m_author = nullptr;
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
		if (m_author != nullptr && Publication::operator bool()) {
			return true;
		}
		return false;
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
		char temp_author[256];
		
		Publication::read(istr);

		if (m_author != nullptr) {
			delete[] m_author;
			m_author = nullptr;
		}
		

		if (conIO(istr)) {
			istr.ignore();
			cout << "Author: ";
			
		}
		else {
			istr.ignore(1000, '\t');
		}

		istr.get(temp_author, 256);

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