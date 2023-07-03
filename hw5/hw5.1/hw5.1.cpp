#include <iostream>

int main()
{
	int a, b, c;
	
	std::cout << "Enter first number: ";
	std::cin >> a;
	std::cout << "Enter second number: ";
	std::cin >> b;
	std::cout << "Enter third number: ";
	std::cin >> c;

	int max = a;

	if (b > max)
	{
		max = b;
	}
	
	if (c > max)
	{
		max = c;
	}

	std::cout << "Max number: " << max;
	return 0;
}
