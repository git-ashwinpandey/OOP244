/*
Full Name  : Ashwin Pandey
Student ID#: 156027211
Email      : apandey21@myseneca.ca
*/

#include <iomanip>
#include "MotorVehicle.h"
#include "cstring.h"

using namespace std;
namespace sdds {
	MotorVehicle::MotorVehicle() {
		location[0] = '\0';
		license[0] = '\0';
	}
	MotorVehicle::MotorVehicle(const char* license, int year): year(year) {
		strCpy(this->license, license);
		strCpy(location, "Factory");
	}

	void MotorVehicle::moveTo(const char* address) {
		if (strCmp(location, address) != 0) {
			
			cout << "|" << setw(8) << right << license << "| |" 
				 << setw(20) << right << location << " ---> " 
				 << setw(20) << left << address << "|" << endl;
			
			strCpy(location, address);
		}
	}

	std::ostream& MotorVehicle::write(std::ostream& ostr) const{
		ostr << "| " << year << " | " << license << " | " << location << "";
		return ostr;
	}

	std::istream& MotorVehicle::read(std::istream& istr) {
		cout << "Built year: ";
		istr >> year;
		istr.ignore();
		cout << "License plate: ";
		istr >> license;
		istr.ignore();
		cout << "Current location: ";
		istr >> location;
		return istr;
	}


	std::ostream& operator<<(std::ostream& ostr, const MotorVehicle& motorVehicle) {
		return motorVehicle.write(ostr);
	}

	std::istream& operator>>(std::istream& istr, MotorVehicle& motorVehicle) {
		return motorVehicle.read(istr);
	}


}