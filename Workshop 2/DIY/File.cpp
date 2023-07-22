/*
Full Name  : Ashwin Pandey
Student ID#: 156027211
Email      : apandey21@myseneca.ca
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }

   bool read(char readChar[]) {
      bool ok = false;
      if (readChar == nullptr || fptr == nullptr)
      {
         return ok;
      }

      if ((fscanf(fptr, "%[^,],", readChar) == 1))
      {
         ok = true;
      }
      return ok;
   }

   bool read(int &readChar) {
      bool ok = false;
      if (&readChar == nullptr || fptr == nullptr)
      {
         return ok;
      }

      if ((fscanf(fptr, "%d\n", &readChar) == 1))
      {
         ok = true;
      }
      return ok;
   }
}