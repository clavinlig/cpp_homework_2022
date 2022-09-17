#include <iostream>

int main()
{
	int x, y;
	std::cout << "print x:" << " ";
	std::cin >> x;
	std::cout << "print y:" << " ";
	std::cin >> y;

	x = x + y;
	y = x - y;
	x = x - y;

	std::cout << "x = " << x << '\n' << "y = " << y;

	return 0;
}