#include <iostream>

enum class Weekdays
{
	Monday = 1,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};

int main()
{
	std::cout << "Numerical values of the days of the week:" << std::endl;
	
	std::cout << "Monday: " << int (Weekdays::Monday) << std::endl;
	std::cout << "Tuesday: " << int (Weekdays::Tuesday) << std::endl;
	std::cout << "Wednesday: " << int (Weekdays::Wednesday) << std::endl;
	std::cout << "Thursday: " << int (Weekdays::Thursday) << std::endl;
	std::cout << "Friday: " << int (Weekdays::Friday) << std::endl;
	std::cout << "Saturday: " << int (Weekdays::Saturday) << std::endl;
	std::cout << "Sunday: " << int (Weekdays::Sunday) << std::endl;

	int number;
	std::cout << "Enter number: ";
	std::cin >> number;

	bool trueorfalsevalue = number >= 1 && number <= 7;
	std::cout << "Bool format value: " << std::boolalpha << trueorfalsevalue << std::endl;
	return 0;
}