#include <iostream>
#include <vector>

int main()
{
	int len;
	std::vector <int> arr;

	std::cout << "Please, input length of your array: ";
	std::cin >> len;
	std::cout << "Please, input your array: ";
	for (size_t i = 0; i < len; ++i)
	{
		int number;
		std::cin >> number;
		arr.push_back(number);
	}

	for (size_t i = 1; i < len; i++)
	{
		int j = i;
		while (j > 0 && arr[j] < arr[j - 1])
		{
			std::swap(arr[j], arr[j - 1]);
			j -= 1;
		}
	}

	std::cout << "Here is your sorted array: ";
	for (size_t i = 0; i < len; i++)
	{
		std::cout << arr[i] << " ";
	}
	return 0;
}