/*
Full Name  : Ashwin Pandey
Student ID#: 156027211
Email      : apandey21@myseneca.ca
*/

#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H

#include <iostream>

namespace sdds {
    class Label {
        char m_labelCharacters[9];
        char* m_labelText;

        void setLabelChar(const char* labelChar);
        void setLabelText(const char* labelText);

        public:
            Label();
            Label(const char* frameArg);
            Label(const char* frameArg, const char* content);
            ~Label();
            void readLabel();
            std::ostream& printLabel()const;
    };
}

#endif // !LABEL_HPP