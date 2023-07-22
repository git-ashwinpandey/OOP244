/*
Full Name  : Ashwin Pandey
Student ID#: 156027211
Email      : apandey21@myseneca.ca
*/

#include <iostream>
#include "cstring.h"

using namespace std;
namespace sdds
{
	// Copies the srouce character string into the destination
	void strCpy(char* des, const char* src)
	{
		int arrLength = 0;
		while (src[arrLength] != '\0')
		{
			des[arrLength] = src[arrLength];
			arrLength++;
		}
		des[arrLength] = '\0';
	}

	// Copies the source character string into the destination upto "len"
	// characters. The destination will be null terminated only if the number
	// of the characters copied is less than "len"
	/*void strnCpy(char* des, const char* src, int len)
	{
		int arrLength = 0;
		bool lessThanLen = false;

		if (des != nullptr && src != nullptr && len > 0) {
			while (arrLength < len) {
				if (src[arrLength] == '\0') {
					lessThanLen = true;
					break;
				}
				des[arrLength] = src[arrLength];
				arrLength++;
			}

		if (lessThanLen) {
			des[arrLength] = '\0';
		} else {
			des[len] = '\0';
		}

		}
	}*/

	// Copies the source character string into the destination upto "len"
	// characters. The destination will be null terminated only if the number
	// of the characters copied is less than "len"
	
	void strnCpy(char* des, const char* src, int len) {
		int arrLength = 0;
		bool lessThanLen = false;

		if (des != nullptr && src != nullptr && len > 0) {
			while (arrLength < len && !lessThanLen) {
				if (src[arrLength] == '\0') {
					lessThanLen = true;
				}
				else {
					des[arrLength] = src[arrLength];
					arrLength++;
				}
			}

			if (lessThanLen) {
				des[arrLength] = '\0';
			}
			else {
				des[len] = '\0';
			}
		}
	}

	// Compares two C-strings 
	// returns 0 i thare the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2
	int strCmp(const char* s1, const char* s2)
	{
		while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		
		if (*s1 > *s2)
		{
			return 1;
		}
		else if (*s2 > *s1)
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}

	// returns 0 i thare the same
	// return > 0 if s1 > s2
	// return < 0 if s1 < s2
	int strnCmp(const char* s1, const char* s2, int len)
	{
		int counter = 1;
		while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2 && counter < len)
		{
			s1++;
			s2++;
			counter++;
		}

		if (*s1 > *s2)
		{
			return 1;
		}
		else if (*s2 > *s1)
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}

	// returns the lenght of the C-string in characters
	int strLen(const char* s)
	{
		int length = 0;

		while (*s != '\0') {
			length++;
			s++;
		}

		return length;
	}

	// returns the address of first occurance of "str2" in "str1"
	// returns nullptr if no match is found
	const char* strStr(const char* str1, const char* str2)
	{
		int counter = 0, strLength = 0;
		bool foundStr = false;
		const char* temp = nullptr;
		const char* temp1 = str1;
		const char* temp2 = str2;

		while (*temp2 != '\0')
		{
			temp2++;
			strLength++;
		}

		temp2 = str2;

		while (*temp1 != '\0' && !foundStr)
		{
			if (*temp2 != '\0' && !foundStr)
			{
				if (*temp1 == *temp2)
				{
					temp = temp1;
					temp2++;
					counter++;
					
					if (counter == strLength)
					{
						foundStr = true;
					}
				}
			}
			temp1++;
		}

		if (!foundStr)
			return nullptr;
		else
			return temp- strLength + 1;
	}

	

	// Concantinates "src" C-string to the end of "des"
	void strCat(char* des, const char* src)
	{
		const char* tempSrc = src;

		while (*des != '\0')
		{
			des++;
		}

		while (*tempSrc != '\0')
		{
			*des = *tempSrc;
			tempSrc++;
			des++;
		}
		*des = '\0';
	}
}
