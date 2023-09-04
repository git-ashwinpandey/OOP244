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

		// Conversion operator to check if the MenuItem is empty
		operator bool() const;
		// Conversion operator to retrieve the content of the MenuItem
		operator const char* () const;

		MenuItem(MenuItem& item) = delete;
		MenuItem& operator=(MenuItem& item) = delete;

		// Display the content of the MenuItem
		std::ostream& displayItem(std::ostream& os = std::cout);
	};

	class Menu {
		char* menuName;
		MenuItem* itemList[MAX_MENU_ITEMS];
		unsigned noOfItems;

		//Sets the title of the Menu
		void setTitle(const char* title);
		

	public:
		// Run the menu and return user selection
		unsigned int run();

		Menu();
		Menu(const char* title);
		~Menu();
		
		// Conversion operator to check if the menu is valid (has at least one item)
		operator bool() const;
		// Run the menu and return user selection
		unsigned int operator ~();
		// Conversion operator to get the number of items in the menu
		operator int() const;
		// Conversion operator to get the number of items in the menu
		operator unsigned int() const;
		// Get the content of the MenuItem at the given index
		const char* operator[](unsigned index)const;
		// Display the title of the menu
		std::ostream& display(std::ostream& os)const;
		// Display the menu with all its items
		void displayMenu(std::ostream& os) const;
		// Overloaded << operator to add a new item to the menu
		Menu& operator<<(const char* menuitemContent);

		Menu(Menu& menu) = delete;
		Menu& operator=(Menu& menu) = delete;
	};

	// Overloaded << operator to display the title of the menu
	std::ostream& operator<<(std::ostream& os, const Menu& menu);
}

#endif // SDDS_MENU_H__