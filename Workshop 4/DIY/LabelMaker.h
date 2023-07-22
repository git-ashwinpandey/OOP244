/*
Full Name  : Ashwin Pandey
Student ID#: 156027211
Email      : apandey21@myseneca.ca
*/

#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include "Label.h"

namespace sdds {
    class LabelMaker {
        int noOfLabels;
        Label* labels;

        public:
            LabelMaker(int noOfLabels);

            void readLabels();
            void printLabels();

            ~LabelMaker();
    };
}

#endif // !LABELMAKER_HPP