/*
Full Name  : Ashwin Pandey
Student ID#: 156027211
Email      : apandey21@myseneca.ca
*/

#ifndef SDDS_CALORIE_LIST_H_
#define SDDS_CALORIE_LIST_H_
#include "Food.h"

namespace sdds {
   class CalorieList {
      Food* m_food;
      int m_noOfItems;
      int m_itemsAdded;

      int totalCalorie()const;
      void Title()const;
      void footer()const;
      void setEmpty();
      bool isValid()const;

   public:
      void init(int size);
      bool add(const char* item_name, int calorie, int when);
      void display()const;
      void deallocate();
   };
}
#endif // !SDDS_CALORIE_LIST_H_
