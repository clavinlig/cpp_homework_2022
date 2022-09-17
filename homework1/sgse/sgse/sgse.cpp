#include <iostream>
#include <string>

int main()
{
	const int lenght_cm = 100;
	const int mass_g = 1000;
	const int charge_fr = 3000000000;
	const int force_din = 100000;

	double value;
	std::string unit;

	std::cout << "This is a converter from SI to SGSE" << '\n' << "Please, enter your value and unit in SI: " << '\n';
	std::cin >> value >> unit;

	if (unit == "m") {
		double L = value * lenght_cm;
		std::cout << "In SGSE: " << L << " cm";
		return 0;
	}

	if (unit == "kg") {
		double M = value * mass_g;
		std::cout << "In SGSE: " << M << " g";
		return 0;
	}

	if (unit == "cl") {
		double Q = value * charge_fr;
		std::cout << "In SGSE: " << Q << " fr";
		return 0;
	}

	if (unit == "N") {
		double F = value * force_din;
		std::cout << "In SGSE: " << F << " din";
		return 0;
	}
	std::cout << "We dont have such unit.";

	return 0;
}