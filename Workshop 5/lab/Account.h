/*
Full Name  : Ashwin Pandey
Student ID#: 156027211
Email      : apandey21@myseneca.ca
*/
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;

      bool isValid();
      operator bool() const;
      operator int() const;
      operator double() const;
      bool operator ~() const;
      Account& operator=(int number);
      Account& operator=(Account& otherAccount);
      Account& operator+=(double deposit);
      Account& operator-=(double withdraw);
      Account& operator<<(Account& otherAccount);
      Account& operator>>(Account& otherAccount);
   };

  double operator+(const Account& first, const Account& second);
  double& operator+=(double& first, const Account& second);
   
   
}
#endif // SDDS_ACCOUNT_H_