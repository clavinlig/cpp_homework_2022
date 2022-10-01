#include<vector>
#include <iostream>
//*
int main()
{
	int len;
	int x;

	std::cout << "Please, input length of your sorted array: ";
	std::cin >> len;

	std::vector <int> arr(len);

	std::cout << "Please, input your array: ";

	for (size_t i = 0; i < len; ++i)
	{
		std::cin >> arr[i];
	}
	std::cout << "Please, input a required value: ";
	std::cin >> x;

	int left = 0, right = len - 1;


	while (left < right)
	{
		int middle = (left + right) / 2;
		if (arr[middle] < x)
		{
			left = middle + 1;
		}
		else
		{
			right = middle - 1;
		}
	}
	if (arr[left] == x)
	{
		std::cout << "there is such element";
		return 0;
	}
	std::cout << "there is no such element";

	return 0;
}

