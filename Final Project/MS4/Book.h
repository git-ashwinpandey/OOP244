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
		operator bool()const;

		void set(int member_id = 0);
		char type()const;

		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& istr);
	};
}

#endif //!SDDS_BOOK_H__