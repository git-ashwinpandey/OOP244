#include <string>
#include "Menu.h"
#include <iomanip>
#include <limits>
using namespace std;

namespace sdds {
	//MenuItem
	void MenuItem::setItemName(const char* itemName) {
		item = new char[strLen(itemName) + 1];
		strCpy(item, itemName);
	}
	
	MenuItem::MenuItem() {
		item[0] = '\0';
	}

	MenuItem::MenuItem(const char* item) {
		setItemName(item);
	}

	bool MenuItem::isEmpty()
	{
		return (item[0] == '\0');
	}

	MenuItem::operator bool()const {
		return (item[0] == '\0');
	}

	MenuItem::operator const char*()const {
		return (const char*)item;
	}

	std::ostream& MenuItem::displayItem(std::ostream& os) {
		if (!isEmpty()) {
			os << item;
		}
		return os;
	}

	MenuItem::~MenuItem() {
		delete[] item;
		item = nullptr;
	}

	//Menu
	void Menu::setTitle(const char* title) {
		menuName = new char[strLen(title) + 1];
		strCpy(menuName, title);
	}

	unsigned int Menu::run() {
		bool ok = true;

		unsigned int selection;
		
		displayMenu(std::cout);
		
		while (ok) {
			cin >> selection;
			if (cin) {
				if (validSelection(selection, int(noOfItems), 0)) {
					ok = false;
				} 
			}
			if (ok) {
				cout << "Invalid Selection, try again: ";
			}
			cin.clear();
			cin.ignore(1000, '\n');
		}
		
		return selection;
	}

	Menu::Menu(): itemList{} {
		menuName = nullptr;
		noOfItems = 0;
	}

	Menu::Menu(const char* title): itemList{} {
		noOfItems = 0;
		setTitle(title);
	}

	Menu::~Menu() {
		for (int i = 0; i < int(MAX_MENU_ITEMS); i++) {
			delete itemList[i];
		}
		delete[] menuName;
	}

	Menu::operator bool() const {
		return (noOfItems >= 1);
	}

	unsigned int Menu::operator ~() {
		return run();
	}

	Menu::operator int() const {
		return noOfItems;
	}

	Menu::operator unsigned int() const {
		return noOfItems;
	}

	std::ostream& Menu::display(std::ostream& os)const {
		if (*this) {
			os << menuName;
		}
		return os;
	}

	void Menu::displayMenu(std::ostream& os) const {
		if (menuName != nullptr) {
			os << menuName << ":\n";
		}
			for (int i = 0; i < int(noOfItems); i++) {
				os << std::setw(2) << i + 1 << "- ";
				itemList[i]->displayItem() << "\n";
			}
			os << " 0- Exit\n> ";
		
	}

	const char* Menu::operator[](unsigned index) const
	{
		index = index % MAX_MENU_ITEMS;
		if (*this) {
			return *itemList[index];
		}
		
		return nullptr;
	}

	Menu& Menu::operator<<(const char* menuitemContent) {
		if (noOfItems + 1 < MAX_MENU_ITEMS) {
			itemList[noOfItems] = new MenuItem(menuitemContent);
			noOfItems++;
		}

		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const Menu& menu) {
		return menu.display(os);
	}

}