#include <iostream>
#include <iomanip>

int main()
{
	double number = 3.14159;

	std::cout << "doubleNumber: " << number << std::endl;

	int convertedNumber = int(number);

	std::cout << "intNumber: " << convertedNumber << std::endl;

	std::cout << "$Number: "
		<< std::setw(20) << std::right << std::setfill('$') << number << std::endl;
	return 0;
}
