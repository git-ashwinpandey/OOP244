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

#include "LibApp.h"
#include <iomanip>

using namespace std;
namespace sdds {
	LibApp::LibApp(const char* filename) : m_mainMenu("Seneca Library Application"),
		m_exitMenu("Changes have been made to the data, what would you like to do?"),
		m_pubTypeMenu("Choose the type of publication:") {

		m_changed = false;

		if (filename != nullptr) {
			strCpy(this->filename, filename);
		}
		
		m_loadedP = 0;

		m_mainMenu << "Add New Publication" << "Remove Publication"
			<< "Checkout publication from library" << "Return publication to library";
		m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu";
		m_pubTypeMenu << "Book" << "Publication";

		load();
	}

	LibApp::~LibApp() {
		for (int i = 0; i < m_loadedP; i++) {
			delete m_pub[i];
		}
	}

	
	bool LibApp::confirm(const char* message) {
		Menu confirm(message);
		confirm << "Yes";
		return confirm.run();
	}

	void LibApp::load() {
		cout << "Loading Data" << endl;
		ifstream infile(filename);
		char type{};
		for (int i = 0; infile; i++) {
			infile >> type;
			infile.ignore();
			if (infile) {
				if (type == 'P')
					m_pub[i] = new Publication;
				else if (type == 'B')
					m_pub[i] = new Book;
				if (m_pub[i]) {
					infile >> *m_pub[i];
				}
				m_loadedP++;
				m_lastLibRef = m_pub[i]->getRef();
			}
		}
		
	}

	void LibApp::save() {
		cout << "Saving Data" << endl;
		ofstream onfile(filename);
		for (int i = 0; i < m_loadedP; i++) {
			if (m_pub[i]->getRef() != 0) {
				onfile << *m_pub[i] << endl;
			}
		}
		onfile.close();
	}

	int LibApp::search(int method) {
		int libRef = 0;
		char temp_title[SDDS_MAX_CHAR];
		int userSelection = m_pubTypeMenu.run();
		char selection{};
		if (userSelection == 1) {
			selection = 'B';
		}
		else if (userSelection == 2) {
			selection = 'P';
		}

		cout << "Publication Title: ";
		cin.getline(temp_title, SDDS_MAX_CHAR);
		PublicationSelector selector("Select one of the following found matches:", 15);
		switch (method) {
		case 1:
			for (int i = 0; i < m_loadedP; i++) {
				if (m_pub[i]->operator==(temp_title) && m_pub[i]->type() == selection && m_pub[i]->getRef() != 0) {
					selector << m_pub[i];
				}
			}
			break;
		case 2:
			for (int i = 0; i < m_loadedP; i++) {
				if (m_pub[i]->operator==(temp_title) && m_pub[i]->type() == selection && m_pub[i]->getRef() != 0 && m_pub[i]->onLoan()) {
					selector << m_pub[i];
				}
			}
			break;
		case 3:
			for (int i = 0; i < m_loadedP; i++) {
				if (m_pub[i]->operator==(temp_title) && m_pub[i]->type() == selection && m_pub[i]->getRef() != 0 && !m_pub[i]->onLoan()) {
					selector << m_pub[i];
				}
			}
			break;
		default:
			break;
		}

		if (selector) {
			selector.sort();
			libRef = selector.run();

			if (libRef != 0) {
				cout << *getPub(libRef) << endl;
			}
			else {
				cout << "Aborted!";
			}
		}
		else {
			cout << "No matches found!";
		}
		return libRef;		
	}

	Publication* LibApp::getPub(int libRef) {
		for (int i = 0; i < m_loadedP; i++) {
			if (m_pub[i]->getRef() == libRef) {
				return m_pub[i];
			}
		}
		return nullptr;
	}

	void LibApp::returnPub() {
		cout << "Return publication to the library" << endl;
		int refNo = search(SDDS_SEARCH_ON_LOAN);
		if (refNo != 0 && confirm("Return Publication?")) {
			int period = Date() - getPub(refNo)->checkoutDate();
			if (period > SDDS_MAX_LOAN_DAYS) {
				double penalty = (period - SDDS_MAX_LOAN_DAYS) * 0.5;
				cout << "Please pay $" << fixed << setprecision(2) << penalty << " penalty for being " << period - SDDS_MAX_LOAN_DAYS << " days late!" << endl;
			}
			getPub(refNo)->set(0);
			m_changed = true;
			cout << "Publication returned";
		}
		cout << endl;
	}

	void LibApp::newPublication() {
		if (m_loadedP == SDDS_LIBRARY_CAPACITY) {
			cout << "Library is at its maximum capacity!" << endl;
		}
		else {
			cout << "Adding new publication to the library" << endl;
			
			int userSelection = m_pubTypeMenu.run();
			Publication* pub = nullptr;

			if (userSelection == 0) {
				cout << "Aborted!" << endl;
			}
			else {
				if (userSelection == 1) {
					pub = new Book();
					cin >> *pub;
				}
				else if (userSelection == 2) {
					pub = new Publication();
					cin >> *pub;
				}

				if (cin.fail()) {
					cin.ignore(1000, '\n');
					cin.clear();
					cout << "Aborted!";
					exit(0);
				}
				else {
					if (confirm("Add this publication to the library?")) {
						if (*pub) {
							m_lastLibRef++;
							pub->setRef(m_lastLibRef);
							m_pub[m_loadedP] = pub;
							m_loadedP++;
							m_changed = true;
							cout << "Publication added" << endl;
						}
						else {
							cout << "Failed to add publication!";
							delete pub;
						}
					}
				}
			}
		}
	}

	void LibApp::removePublication() {
		cout << "Removing publication from the library" << endl;
		int removeRef = search(SDDS_SEARCH_ALL);
		if (removeRef != 0 && confirm("Remove this publication from the library?")) {
			getPub(removeRef)->setRef(0);
			m_changed = true;
			cout << "Publication removed";
		}
		cout << endl;
	}

	void LibApp::checkOutPub() {
		cout << "Checkout publication from the library" << endl;
		int checkRef = search(SDDS_SEARCH_AVAILABLE);
		if (checkRef != 0 && confirm("Check out publication?")) {
			int memNo;
			cout << "Enter Membership number: ";
			cin >> memNo;
			while (!validSelection(memNo, 99999, 10000)) {
				cout << "Invalid membership number, try again: ";
				cin >> memNo;
			}
			getPub(checkRef)->set(memNo);
			m_changed = true;
			cout << "Publication checked out";
		}
		cout << endl;
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
