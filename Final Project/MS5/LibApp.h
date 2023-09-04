/* Citation and Sources...
Final Project Milestone 2
Module: LibApp
Filename: LipApp.h
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

#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H

#include <iostream>
#include <fstream>
#include "Lib.h"
#include "Menu.h"
#include "Book.h"
#include "Publication.h"
#include "PublicationSelector.h"

namespace sdds {
   class LibApp {
	   bool m_changed;
	   Menu m_mainMenu;
	   Menu m_exitMenu;
	   Menu m_pubTypeMenu;
	   char filename[SDDS_MAX_CHAR];
	   Publication* m_pub[SDDS_LIBRARY_CAPACITY]; // Publication Pointers Array
	   int m_loadedP; // No of Loaded Publication
	   int m_lastLibRef; // Last Loaded Library Reference

	   // return the result of a 'confirm' menu (yes or exit)
	   bool confirm(const char* message);

	   // Load the data of text file into inputstream
	   void load();

	   // Save the data into file
	   void save();

	   // Search the library for Book or Publication using title
	   int search(int method);

	   // Return a check out publication back to the library. Late Fees applies.
	   void returnPub();

	   // Find a Publication using publication reference number
	   Publication* getPub(int libRef);

	   // Add a Publication to the Library
	   void newPublication();

	   // Remove a Publication from the Library
	   void removePublication();

	   // Check out an available Publication from the Library
	   void checkOutPub();
   public:
	   LibApp(const char* filename);
	   ~LibApp();

	   // Run the Main Menu (m_mainMenu)
	   void run();
   };
}
#endif // !SDDS_LIBAPP_H



