/*
Full Name  : Ashwin Pandey
Student ID#: 156027211
Email      : apandey21@myseneca.ca
*/

#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
#include <iostream>

namespace sdds {
    class Mark {
        int m_marks;
        double m_gpa;
        char m_grade[2];
        void setInvalid();
        void setEmpty();
        void calcGPAGrade();

    public:
        Mark();
        Mark(int marks);

        bool isValid(int number);
        operator bool() const;
        operator int() const;
        operator double() const;
        operator char() const;
        bool operator ~() const;
        Mark& operator=(int marks);
        Mark& operator+=(int marks);

    };

    int& operator+=(int& number, const Mark& marks);
}

#endif //!SDDS_MARK_H_