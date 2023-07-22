/*
Full Name  : Ashwin Pandey
Student ID#: 156027211
Email      : apandey21@myseneca.ca
*/

#include <iostream>
#include "cstring.h"
#include "LabelMaker.h"
#include "Label.h"

using namespace std;
namespace sdds {
    LabelMaker::LabelMaker(int noOfLabels) {
        this->noOfLabels = noOfLabels;
        labels = new Label[noOfLabels];
    }

    void LabelMaker::readLabels() {
        cout << "Enter " << noOfLabels << " labels:" << endl;
        for (int i = 0; i < noOfLabels; i++) {
            cout << "Enter label number " << i+1 << endl;
            cout << "> ";
            labels[i].readLabel();
        }
    }

    void LabelMaker::printLabels() {
        for (int i = 0; i < noOfLabels; i++) {
            labels[i].printLabel();
            cout << endl;
        }
    }

    LabelMaker::~LabelMaker() {
        delete [] labels;
    }
}