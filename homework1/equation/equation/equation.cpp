#include <iostream>
#include <limits>
#include <cmath>

int main()
{
	const double epsilon = std::numeric_limits <double> ::epsilon();
	double a, b, c;

	std::cout << "The quadratic equation is ax^2 + bx + c = 0" << "\n";
	std::cout << "Enter a, b, c: ";
	std::cin >> a >> b >> c;

	if (std::abs(a) < epsilon)
	{

		if (b != 0.0)
		{
			double x_0 = (-c) / b;
			std::cout << "The solution is  " << "x = " << x_0;
		}
		else if (std::abs(c) < epsilon)
		{
			std::cout << "The solution is any number";
		}
		else
		{
			std::cout << "No solutions";
		}
	}
	else
	{
		double D = pow(b, 2) - (4.0 * a * c);
		if (D < 0.0)
		{
			std::cout << "No real roots";
		}

		else if (std::abs(D) < epsilon)
		{

			double x = (-b) / (2.0 * a);

			std::cout << "The solution is  " << "x_1 = x_2 = " << x;
		}

		else
		{
			double d = std::sqrt(D);
			double x1 = (-b + d) / (2.0 * a);
			double x2 = (-b - d) / (2.0 * a);

			std::cout << "The solutions are" << "\n" << "x_1 = " << x1 << "\n" << "x_2 = " << x2;
		}
	}
	return 0;
}