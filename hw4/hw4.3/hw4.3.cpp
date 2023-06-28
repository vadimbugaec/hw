#include <iostream>

int main()
{
	int num = 0;
	std::cout << "Enter first number: ";
	std::cin >> num;

	int num2 = 0;
	std::cout << "Enter second number: ";
	std::cin >> num2;

	bool lessThan = num < num2;
	bool equal = num == num2;
	bool moreThan = num > num2;
	bool lessOrEqual = num <= num2;

	std::cout << "Num < num2: " << std::boolalpha << lessThan << std::endl;
	std::cout << "Num = num2: " << std::boolalpha << equal << std::endl;
	std::cout << "Num > num2: " << std::boolalpha << moreThan << std::endl;
	std::cout << "Num <= num2: " << std::boolalpha << lessOrEqual << std::endl;

	return 0;
}
