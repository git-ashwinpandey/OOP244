/*
Full Name  : Ashwin Pandey
Student ID#: 156027211
Email      : apandey21@myseneca.ca
*/

#include "Truck.h"
#include "cstring.h"

using namespace std;
namespace sdds {
	Truck::Truck(const char* license, int year, double capacity, const char* address) : 
		MotorVehicle(license, year), capacity(capacity), load(0) {
		moveTo(address);
	}

	bool Truck::addCargo(double cargo) {
		if (load + cargo <= capacity) {
			load += cargo;
			return true;
		}
		else if (load + cargo >= capacity && load != capacity) {
			load = capacity;
			return true;
		}
		return false;
	}

	bool Truck::unloadCargo() {
		if (load > 0.0) {
			load = 0.0;
			return true;
		}
		return false;
	}

	std::ostream& Truck::write(std::ostream& ostr) const {
		MotorVehicle::write(ostr);
		ostr << " | "<< load << "/" << capacity;
		return ostr;
	}

	std::istream& Truck::read(std::istream& istr) {
		MotorVehicle::read(istr);
		cout << "Capacity: ";
		istr >> capacity;
		istr.ignore();
		cout << "Cargo: ";
		istr >> load;
		istr.ignore();
		return istr;
	}

	
	std::ostream& operator<<(std::ostream& ostr, const Truck& truck) {
		return truck.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, Truck& truck) {
		return truck.read(istr);
	}

}

