/*
Full Name  : Ashwin Pandey
Student ID#: 156027211
Email      : apandey21@myseneca.ca
*/

#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Bill.h"

using namespace std;
namespace sdds {
    double Bill::totalTax()const {
        double totalTax = 0.0;
        for (int i = 0; i < m_noOfItems; i++) {
            totalTax += m_items[i].tax();
        }
        return totalTax;
    }

    double Bill::totalPrice()const {
        double totalPrice = 0.0;
        for (int i = 0; i < m_noOfItems; i++) {
                totalPrice += m_items[i].price();
        }
        return totalPrice;
    }

    void Bill::Title()const {
        cout << "+--------------------------------------+" << endl;
        if (isValid()) {
            cout << "| "
                << left << setw(36) << m_title
                << " |" << endl; 
        } else {
            cout << "| "
                << left << setw(36) << "Invalid Bill"
                << " |" << endl; 
        }

        cout << "+----------------------+---------+-----+" << endl;
        cout << "| Item Name            | Price   + Tax |" << endl;
        cout << "+----------------------+---------+-----+" << endl;

    }

    void Bill::footer()const {
        cout << "+----------------------+---------+-----+" << endl;
        if (isValid()) {
            cout << "|                Total Tax: "
                << right << setw(10) << fixed << setprecision(2) << totalTax() 
                << " |" << endl;
                
            cout << "|              Total Price: "
                << right << setw(10) << fixed << setprecision(2) << totalPrice() 
                << " |" << endl;
                
            cout << "|          Total After Tax: "
                << right << setw(10) << fixed << setprecision(2) 
                << totalTax()+totalPrice() 
                << " |" << endl;
        } else {
            cout << "| Invalid Bill                         |" << endl;
        }
        cout << "+--------------------------------------+" << endl;
    }

    void Bill::setEmpty() {
        strCpy(m_title, "");
        m_items = nullptr;
    }

    bool Bill::isValid()const {
        bool ok = false;
        if (m_title[0] != '\0' && m_items != nullptr) {
            for (int i = 0; i < m_noOfItems; i++) {
                if (m_items[i].isValid()) {
                    ok = true;
                } else {
                    ok = false;
                }
            } 
        }
        return ok;
    }


    void Bill::init(const char* title, int noOfItems) {
        if (noOfItems <= 0 || title == nullptr) {
            setEmpty();
        } else {
            m_noOfItems = noOfItems;
            m_itemsAdded = 0;
            strnCpy(m_title, title, 36);
            m_items = new Item[m_noOfItems];
            for (int i = 0; i < m_noOfItems; i++) {
                m_items[i].setEmpty();
            }
        }
    }

    bool Bill::add(const char* item_name, double price, bool taxed) {
        bool ok = false;

        if (m_itemsAdded < m_noOfItems) {
            m_items[m_itemsAdded].set(item_name, price, taxed);
            m_itemsAdded++;
            ok = true;
        }
        return ok;

    }

    void Bill::display()const {
        Title();
        for (int i = 0; i < m_noOfItems; i++) {
            m_items[i].display();
        }
        footer();
    }

    void Bill::deallocate() {
        delete [] m_items;
        m_items = nullptr;
    }

}