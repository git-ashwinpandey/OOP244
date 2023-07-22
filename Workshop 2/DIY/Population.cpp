/*
Full Name  : Ashwin Pandey
Student ID#: 156027211
Email      : apandey21@myseneca.ca
*/

#include <iostream>
#include "Population.h"
#include "File.h"
#include "cstring.h"

using namespace std;
namespace sdds {

    int noOfPostalCode;
    Population* population;

    void sort() {
        int i, j;
        Population temp;
        for (i = noOfPostalCode - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (population[j].population > population[j + 1].population) {
                    temp = population[j];
                    population[j] = population[j + 1];
                    population[j + 1] = temp;
                }
            }
        }
    }

    bool load(Population &population) {
      bool ok = false;
      char code[128];

      if (read(code) && read(population.population))
      {
         population.postalCode = new char[strLen(code)+ 1];
         strCpy(population.postalCode, code);
         ok = true;
      }
   
      return ok;
   }

   bool load(const char filename[]) {
      bool ok = false;
      if (openFile(filename)) {
         noOfPostalCode = noOfRecords();
         population = new Population[noOfPostalCode];

         for (int i= 0; i<noOfPostalCode; i++){
            if (load(population[i])){
               ok = true;
            }
            else {
               ok = false;
               cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
            }
         }
      }
      else {
         cout << "Could not open data file: " << filename<< endl;
      }
      closeFile();
      return ok;
   }

   void display(const Population &population) {
      cout << population.postalCode << ":  " << population.population << endl; 
   }

   void display() {
      cout << "Postal Code: population" << endl;
      cout << "-------------------------" << endl;
      sort();
      for (int i = 0; i < noOfPostalCode; i++) {
         cout << i+1 << "- ";
         display(population[i]);
      }
      cout << "-------------------------" << endl;
      
      cout << "Population of Canada: " << sumPopulation(population) << endl;

   }

   int sumPopulation(Population *population) {
      int sum = 0;
      for (int i = 0; i < noOfPostalCode; i++) {
         sum += population[i].population;
      }
      return sum;
   }

   void deallocateMemory() {
      for (int i = 0; i < noOfPostalCode; i++) {
         delete[] population[i].postalCode;
      }
      delete [] population;
   }

   
}