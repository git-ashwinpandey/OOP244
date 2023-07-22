/*
Full Name  : Ashwin Pandey
Student ID#: 156027211
Email      : apandey21@myseneca.ca
*/

#ifndef SDDS_MOTORVEHICLE_H__
#define SDDS_MOTORVEHICLE_H__
#include <iostream>
namespace sdds {
	class MotorVehicle {
		char license[9];
		char location[64];
		int year;

	public:
		MotorVehicle();
		MotorVehicle(const char* license, int year);
		void moveTo(const char* address);
		std::ostream& write(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
	};

	std::ostream& operator<<(std::ostream& ostr, const MotorVehicle& motorVehicle);
	std::istream& operator>>(std::istream& istr, MotorVehicle& motorVehicle);
}

#endif //!SDDS_MOTORVEHICLE_H__