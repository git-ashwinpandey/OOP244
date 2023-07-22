/*
Full Name  : Ashwin Pandey
Student ID#: 156027211
Email      : apandey21@myseneca.ca
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mark.h"

using namespace std;
namespace sdds {
    void Mark::setInvalid() {
        m_marks = -1;
    }

    void Mark::setEmpty() {
        m_marks = 0;
    }

    void Mark::calcGPAGrade() {
        if (isValid(m_marks)) {
            if (m_marks >= 0 && m_marks < 50) {
                m_grade[0] = 'F';
                m_gpa = 0.0;
            } else if (m_marks >= 50 && m_marks < 60) {
                m_grade[0] = 'D';
                m_gpa = 1.0;
            } else if (m_marks >= 60 && m_marks < 70) {
                m_grade[0] = 'C';
                m_gpa = 2.0;
            } else if (m_marks >= 70 && m_marks < 80) {
                m_grade[0] = 'B';
                m_gpa = 3.0;
            } else if (m_marks >= 80 && m_marks <= 100) {
                m_grade[0] = 'A';
                m_gpa = 4.0;
            }
            
        } else {
            m_grade[0] = 'X';
            m_gpa = 0.0;
        }
        m_grade[1] = '\0';
    }

    Mark::Mark() {
        m_marks = 0;
    }

    Mark::Mark(int marks) {
        if (marks < 0 || marks > 100) {
            setInvalid();
        } else {
            m_marks = marks;
            calcGPAGrade();
        }
    }

    bool Mark::isValid(int number) {
        return (number >= 0 && number <= 100);
    }

    Mark::operator bool() const {
        if (m_marks >= 0 && m_marks <= 100) {
            return true;
        }
        return false;
    }

    Mark::operator int() const {
        if (m_marks >= 0 && m_marks <= 100) {
            return m_marks;
        } else {
            return 0;
        }
    }

    Mark::operator double() const {
        return m_gpa;
    }

    Mark::operator char() const {
        return m_grade[0];
    }

    bool Mark::operator ~() const {
        if (m_marks == 0) {
            return true;
        }
        return false;
    }

    Mark& Mark::operator=(int marks) {
        m_marks = marks;
        if (!isValid(m_marks)) {
            setInvalid();
        }
        calcGPAGrade();
        return *this;
    }

    Mark& Mark::operator+=(int marks) {
      if (isValid(marks) && isValid(m_marks)) {
        m_marks += marks;
        if (!isValid(m_marks)) {
            setInvalid();
        }
      }
      calcGPAGrade();
      return *this;
   }

   int& operator+=(int& number, const Mark& marks) {
    if (marks) {
        number += (int)marks;
    }
    return number;
   }

}
