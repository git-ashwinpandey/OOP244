/*
Full Name  : Ashwin Pandey
Student ID#: 156027211
Email      : apandey21@myseneca.ca
*/

#ifndef SDDS_TRUCK_H__
#define SDDS_TRUCK_H__

#include <iostream>
#include "MotorVehicle.h"


namespace sdds {
	class Truck : public MotorVehicle {
		double capacity;
		double load;

	public:
		Truck(const char* license, int year, double capacity, const char * address);
		bool addCargo(double cargo);
		bool unloadCargo();

		std::ostream& write(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
	};

	std::ostream& operator<<(std::ostream& ostr, const Truck& truck);
	std::istream& operator>>(std::istream& istr, Truck& truck);
}

#endif //!SDDS_TRUCK_H__