/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.h
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

#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__

#include <iostream>
#include "Utils.h"

namespace sdds {
	const unsigned int MAX_MENU_ITEMS = 20;
	class Menu;

	class MenuItem {
		friend class Menu;
		char* item;

		void setItemName(const char* itemName);

		MenuItem();
		MenuItem(const char* item);
		~MenuItem();

		bool isEmpty();

		operator bool() const;
		operator const char* () const;

		MenuItem(MenuItem& item) = delete;
		MenuItem& operator=(MenuItem& item) = delete;

		std::ostream& displayItem(std::ostream& os = std::cout);
	};

	class Menu {
		char* menuName;
		MenuItem* itemList[MAX_MENU_ITEMS];
		unsigned noOfItems;

		void setTitle(const char* title);
		

	public:
		unsigned int run();

		Menu();
		Menu(const char* title);
		~Menu();
		
		operator bool() const;
		unsigned int operator ~();
		operator int() const;
		operator unsigned int() const;
		const char* operator[](unsigned index)const;

		std::ostream& display(std::ostream& os)const;
		void displayMenu(std::ostream& os) const;

		Menu& operator<<(const char* menuitemContent);

		Menu(Menu& menu) = delete;
		Menu& operator=(Menu& menu) = delete;
	};

	std::ostream& operator<<(std::ostream& os, const Menu& menu);
}

#endif // SDDS_MENU_H__