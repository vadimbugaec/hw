#include <iostream>

int main()
{
	int radius = 0;
	std::cout << "Enter the radius of circle: ";
	std::cin >> radius;

	double p = 3.14;

	double square = p * radius * radius;
	double length = 2 * p * radius;

	std::cout << "Square of the circle: " << square << std::endl;
	std::cout << "Perimeter of the circle: " << length << std::endl;

	return 0;
}