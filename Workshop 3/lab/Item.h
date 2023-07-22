/*
Full Name  : Ashwin Pandey
Student ID#: 156027211
Email      : apandey21@myseneca.ca
*/

#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_
namespace sdds {
   class Item {
      const double TAX_RATE = 0.13;
      char m_itemName[21];
      double m_price;
      bool m_taxed;
      void setName(const char* name);
   public:
      void setEmpty();
      void set(const char* name, double price, bool taxed);
      void display()const;
      bool isValid()const;
      double price()const;
      double tax()const;
   };
}

#endif // !SDDS_SUBJECT_H
