/*
Full Name  : Ashwin Pandey
Student ID#: 156027211
Email      : apandey21@myseneca.ca
*/

#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Food.h"

using namespace std;
namespace sdds {

    void Food::setName(const char* name) {
        strnCpy(m_foodName, name, 30);
    }

    void Food::setTime(const int time) {
        switch (time) {
            case 1:
            strCpy(m_timeOfConsumption, "Breakfast");
            break;
                
            case 2:
            strCpy(m_timeOfConsumption, "Lunch");
            break;
                
            case 3:
            strCpy(m_timeOfConsumption, "Dinner");
            break;
                
            case 4:
            strCpy(m_timeOfConsumption, "Snack");
            break;
                
            default:
            strCpy(m_timeOfConsumption, "");
            }
    }
        
    void Food::setEmpty() {
        strCpy(m_foodName, "");
        m_calorie = 0;
        strCpy(m_timeOfConsumption, "");
    }

    void Food::set(const char* name, int calories, int time) {
        if (calories < 0 || calories > 3000 || name == nullptr || time < 1 || time > 4){
                setEmpty();
        } else {
            setName(name);
            m_calorie = calories;
            setTime(time);
        }
    }
    void Food::display()const {
        if (isValid()) {
            cout << "| " 
                << left << setw(30) << setfill('.') << m_foodName
                << " | "; 
            cout << right << setw(4) << setfill(' ') << calorie()
                << " | "; 
            cout << left << setw(10) << setfill(' ') << m_timeOfConsumption
                << " |" << endl;
        }
        else {
            cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
        }

    }
    bool Food::isValid()const {
        bool valid = false;
        if ((m_calorie > 0 && m_calorie <= 3000) && m_foodName != nullptr && m_timeOfConsumption != nullptr) {
            valid = true;
        }
        return valid;
    }

    int Food::calorie()const {
        return m_calorie;
    }

}