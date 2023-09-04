/* Citation and Sources...
Final Project Milestone 2
Module: Publication
Filename: Publication.h
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

#ifndef SDDS_PUBLICATION_H__
#define SDDS_PUBLICATION_H__

#include <iostream>
#include "Date.h"
#include "Streamable.h"
#include "Lib.h"
#include "Utils.h"


namespace sdds {
	class Publication : public Streamable {
		
		// maximum length of title
		char* m_title;
		//Shelf ID
		char m_shelfId[SDDS_SHELF_ID_LEN + 1];
		// Membership ID
		int m_membership;
		int m_libRef;
		Date m_date;

		// Private helper function to clear attributes and free memory
		void clearAttributes();

	public:
		virtual void set(int member_id = 0);
		// Sets the membership attribute to either zero or a five-digit integer.
		void setRef(int value);
		// Sets the **libRef** attribute value
		void resetDate();
		// Sets the date to the current date of the system.
		Publication();
		~Publication();
		Publication(const Publication& publication);
		Publication& operator=(const Publication& publication);

		virtual char type()const;
		//Returns the character 'P' to identify this object as a "Publication object"
		bool onLoan()const;
		//Returns true is the publication is checkout (membership is non-zero)
		Date checkoutDate()const;
		//Returns the date attribute
		bool operator==(const char* title)const;
		//Returns true if the argument title appears anywhere in the title of the 
		//publication. Otherwise, it returns false; (use strstr() function in <cstring>)
		operator const char* ()const;
		//Returns the title attribute
		operator bool()const; 
		//Returns true if neither of the title or shelfId attributes is null or empty.Otherwise, it will return false.
		int getRef()const;
		//Returns the libRef attirbute. 

		bool conIO(const std::ios& io) const;
		std::ostream& write(std::ostream& os) const;
		std::istream& read(std::istream& istr);
	};
}

#endif //!SDDS_PUBLICATION_H__