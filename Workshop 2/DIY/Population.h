/*
Full Name  : Ashwin Pandey
Student ID#: 156027211
Email      : apandey21@myseneca.ca
*/

#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds {

    struct Population {
      char* postalCode;
      int population;
   };

   //sorts the dynamic array of employees based on the number of the population .
   void sort();
   // loads a population structure with its values from the file
   bool load(Population &population);
   // allocates the dyanmic array of population and loads all the file
   // records into the array
   bool load(const char filename[]);
   
   // displays a polulation record on the screen:
   void display(const Population &population);

   // first sorts the polulation then displays all the population on the screen
   void display();

   //Sum up the total population 
   int sumPopulation(Population *population);
   
   // first will deallocate all the names in the polulation elements
   // then it will deallocate the polulation array 
   void deallocateMemory();

}

#endif // SDDS_POPULATION_H_