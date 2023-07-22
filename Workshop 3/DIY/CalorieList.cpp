/*
Full Name  : Ashwin Pandey
Student ID#: 156027211
Email      : apandey21@myseneca.ca
*/

#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "CalorieList.h"

using namespace std;
namespace sdds {
    int CalorieList::totalCalorie()const {
        int totalCalories = 0;
        for (int i = 0; i < m_noOfItems; i++) {
            totalCalories += m_food[i].calorie();
        }
        return totalCalories;
    }

    void CalorieList::Title()const {
        cout << "+----------------------------------------------------+" << endl;
        if (isValid()) {
            cout << "|  "
                << left << setw(50) << "Daily Calorie Consumption"
                << "|" << endl; 
        } else {
            cout << "| "
                << left << setw(50) << "Invalid Calorie Consumption list"
                << " |" << endl; 
        }

        cout << "+--------------------------------+------+------------+" << endl;
        cout << "| Food name                      | Cals | When       |" << endl;
        cout << "+--------------------------------+------+------------+" << endl;
    }

    void CalorieList::footer()const {
        cout << "+--------------------------------+------+------------+" << endl;
        if (isValid()) {
            cout << "|    Total Calories for today:   "
                << right << setw(6) << totalCalorie() << " |            |" << endl;
        } else {
            cout << "|    Invalid Calorie Consumption list                |" << endl;
        }
        cout << "+----------------------------------------------------+" << endl;
    }

    void CalorieList::setEmpty() {
        m_food = nullptr;
    }
    
    bool CalorieList::isValid()const {
        bool ok = true;
        if (m_food != nullptr) {
            for (int i = 0; i < m_noOfItems; i++) {
                if (!m_food[i].isValid()) {
                    ok = false;
                }
            } 
        }
        return ok;
    }

    void CalorieList::init(int size) {
        if (size <= 0) {
            setEmpty();
        } else {
            m_noOfItems = size;
            m_itemsAdded = 0;
            m_food = new Food[m_noOfItems];
            for (int i = 0; i < m_noOfItems; i++) {
                m_food[i].setEmpty();
            }
        }
    }

    bool CalorieList::add(const char* item_name, int calorie, int when) {
        bool ok = false;

        if (m_itemsAdded < m_noOfItems) {
            m_food[m_itemsAdded].set(item_name, calorie, when);
            m_itemsAdded++;
            ok = true;
        }
        return ok;
    }

    void CalorieList::display()const {
        Title();
        for (int i = 0; i < m_noOfItems; i++) {
            m_food[i].display();
        }
        footer();
    }

    void CalorieList::deallocate() {
        delete [] m_food;
        m_food = nullptr;
    }
}