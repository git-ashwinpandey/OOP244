/*
Full Name  : Ashwin Pandey
Student ID#: 156027211
Email      : apandey21@myseneca.ca
*/

#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_

namespace sdds {
    class Food {

        char m_foodName[31];
        int m_calorie;
        char m_timeOfConsumption[11];

        void setName(const char* name);
        void setTime(const int time);
        
        public:
        void setEmpty();
        void set(const char* name, int calories, int time);
        void display()const;
        bool isValid()const;
        int calorie()const;

    };
}


#endif // !SDDS_FOOD_H_