/*
Full Name  : Ashwin Pandey
Student ID#: 156027211
Email      : apandey21@myseneca.ca
*/

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   //Opens a file
   bool openFile(const char filename[]);

   //Close a file if it's open
   void closeFile();

   //Counts the no of lines in the .csv file
   int noOfRecords();

   //Read character in the csv file until delimeter ',' is reached and stores in an char array
   bool read(char readChar[]);

   //Read int values until newline is reached
   bool read(int &readChar);
}
#endif // !SDDS_FILE_H_
