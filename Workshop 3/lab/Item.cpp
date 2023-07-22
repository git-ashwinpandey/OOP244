/*
Full Name  : Ashwin Pandey
Student ID#: 156027211
Email      : apandey21@myseneca.ca
*/

#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Item.h"

using namespace std;
namespace sdds {

    void Item::setName(const char* name) {
        strnCpy(m_itemName, name, 20);
    }

    void Item::setEmpty() {
        strCpy(m_itemName, "");
        m_price = 0.0;
        m_taxed = false;
    }

    void Item::set(const char* name, double price, bool taxed) {
        if (price < 0 || name == nullptr){
                setEmpty();
        } else {
            setName(name);
            m_price = price;
            m_taxed = taxed;
        }
    }

    void Item::display()const {
        if (isValid()) {
            cout << "| " 
                << left << setw(20) << setfill('.') << m_itemName
                << " | "; 
            cout << right << setw(7) << fixed << setfill(' ')
                << setprecision(2) <<  price()
                << " | "; 
            cout << (m_taxed ? "Yes" : "No ") 
                << " |" << endl;
        }
        else {
            cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
        }
    }

    bool Item::isValid()const {
        return (m_itemName != nullptr && m_price > 0) ? true : false;
    }
            
    double Item::price()const {
        return m_price;
    }

    double Item::tax()const {
        return m_taxed ? m_price * TAX_RATE: 0.0;
    }
    
}