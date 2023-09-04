/* Citation and Sources...
Final Project Milestone 2
Module: LibApp
Filename: LibApp.cpp
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

#include <iostream>
#include "LibApp.h"

using namespace std;
namespace sdds {
	LibApp::LibApp() : m_mainMenu("Seneca Library Application"),
		m_exitMenu("Changes have been made to the data, what would you like to do?") {
		m_changed = false;
		m_mainMenu << "Add New Publication" << "Remove Publication"
			<< "Checkout publication from library" << "Return publication to library";
		m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
		load();
	}

	
	bool LibApp::confirm(const char* message) {
		Menu confirm(message);
		confirm << "Yes";
		return confirm.run();
	}

	void LibApp::load() {
		cout << "Loading Data" << endl;
	}

	void LibApp::save() {
		cout << "Saving Data" << endl;
	}

	void LibApp::search() {
		cout << "Searching for publication" << endl;
	}

	void LibApp::returnPub() {
		search();
		cout << "Returning publication" << endl;
		cout << "Publication returned" << endl;
		m_changed = true;
	}

	void LibApp::newPublication() {
		cout << "Adding new publication to library" << endl;
		if (confirm("Add this publication to library?")) {
			m_changed = true;
			cout << "Publication added" << endl;
		}
	}

	void LibApp::removePublication() {
		cout << "Removing publication from library" << endl;
		search();
		if (confirm("Remove this publication from the library?")) {
			m_changed = true;
			cout << "Publication removed" << endl;
		}
	}

	void LibApp::checkOutPub() {
		search();
		if (confirm("Check out publication?")) {
			m_changed = true;
			cout << "Publication checked out" << endl;
		}

	}

	void LibApp::run() {
		bool keepRunning = 1;
		int selectOption;
		while (keepRunning) {
			selectOption = m_mainMenu.run();
			if (selectOption == 1) {
				newPublication();
			}
			else if (selectOption == 2) {
				removePublication();
			}
			else if (selectOption == 3) {
				checkOutPub();
			}
			else if (selectOption == 4) {
				returnPub();
			}
			else if (selectOption == 0) {
				if (m_changed) {
					selectOption = m_exitMenu.run();
					if (selectOption == 1) {
						save();
						keepRunning = 0;
					}
					else if (selectOption == 2) {
					}
					else if (selectOption == 0) {
						selectOption = confirm("This will discard all the changes are you sure?");
						if (selectOption == 1) {
							keepRunning = 0;
						}
					}
				}
				else {
					keepRunning = 0;
				}
			}
			cout << endl;
		}
		cout << "-------------------------------------------" << endl;
		cout << "Thanks for using Seneca Library Application" << endl;
	}


}
