/*
Full Name  : Ashwin Pandey
Student ID#: 156027211
Email      : apandey21@myseneca.ca
*/

#include <iostream>
#include "cstring.h"
#include "Label.h"

using namespace std;

namespace sdds {
    void Label::setLabelChar(const char* labelChar) {
        if (labelChar != nullptr) {
            strCpy(m_labelCharacters, labelChar);
        }
    }

    void Label::setLabelText(const char* labelText) {
        if (labelText != nullptr) {

            m_labelText = new char[strLen(labelText) + 1];
            strCpy(m_labelText, labelText);
        }
    }

    Label::Label() {
        setLabelChar("+-+|+-+|");
        m_labelText = nullptr;
    }

    Label::Label(const char* frameArg) {
        setLabelChar(frameArg);
        m_labelText = nullptr;
    }

    Label::Label(const char* frameArg, const char* content) {
        setLabelChar(frameArg);
        setLabelText(content);
    }

    void Label::readLabel() {
        char userInput[71];
        cin.getline(userInput, 71);
        setLabelText(userInput);
    }

    std::ostream& Label::printLabel()const {
        if (m_labelText == nullptr) {
            return std::cout;
        }
        int width = strLen(m_labelText) + 2;

        //1st row
        cout << m_labelCharacters[0];
        for (int i = 0; i < width; i++) {
            cout << m_labelCharacters[1];
        }
        cout << m_labelCharacters[2] << endl;

        //2nd row
        cout << m_labelCharacters[7];
        for (int i = 0; i < width; i++) {
            cout << " ";
        }
        cout << m_labelCharacters[3] << endl;

        //3rd row
        cout << m_labelCharacters[7] << ' ';
        cout << m_labelText;
        cout << ' ' << m_labelCharacters[3] << endl;

        //4th row
        cout << m_labelCharacters[7];
        for (int i = 0; i < width; i++) {
            cout << " ";
        }
        cout << m_labelCharacters[3] << endl;

        //5th row
        cout << m_labelCharacters[6];
        for (int i = 0; i < width; i++) {
            cout << m_labelCharacters[5];
        }
        cout << m_labelCharacters[4];

        return std::cout;
    }

    Label::~Label() {
        delete [] m_labelText;
    }
}