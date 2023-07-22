/*
Full Name  : Ashwin Pandey
Student ID#: 156027211
Email      : apandey21@myseneca.ca
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }

   Account::operator bool() const {
      if (m_number >= 10000 && m_number <= 99999&& m_balance >= 0) {
            return true;
      }
      return false;
   }

   Account::operator int() const {
      return m_number;
   }

   Account::operator double() const {
      return m_balance;
   }
   
   bool Account::operator ~() const {
      if (m_number == 0) {
         return true;
      }
      return false;
   }

   Account& Account::operator=(int number) {
      if (m_number == 0) {
         if (number >= 10000 && m_number <= 99999) {
            m_number = number;
         } else {
            setEmpty();
         }
      }
      return *this;
   }

   Account& Account::operator=(Account& otherAccount) {
      if (~*this == true && otherAccount) {
         m_number = otherAccount.m_number;
         m_balance = otherAccount.m_balance;
         otherAccount.m_balance = 0;
         otherAccount.m_number = 0;
      }
      return *this;
   }

   Account& Account::operator+=(double deposit) {
      if (!(m_number == -1 || deposit < 0)) {
         m_balance += deposit;
      }
      return *this;
   }

   Account& Account::operator-=(double withdraw) {
      if (!(m_number == -1 || withdraw < 0 || m_balance < withdraw)) {
         m_balance -= withdraw;
      }
      return *this;
   }

   Account& Account::operator<<(Account& otherAccount) {
      if ((this) && otherAccount.m_balance > 0 && this != &otherAccount) {
         *this += otherAccount.m_balance;
         otherAccount.m_balance = 0;
      }
      return *this;
   }

   Account& Account::operator>>(Account& otherAccount) {
      if (otherAccount && m_balance > 0 && this != &otherAccount) {
         otherAccount += m_balance;
         m_balance = 0;
      }
      return *this;
   }

   
   double operator+(const Account& first, const Account& second) {
      double sum = 0;
      if (first && second) {
         sum += (double) first + (double) second;
      }
      return sum;
   }

   double& operator+=(double& first, const Account& second) {
      if (second) {
         first += (double)(second);
      }
      return first;
   }
}

