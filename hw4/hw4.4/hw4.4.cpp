#include <iostream>

int main()
{
	int width = 0;
	std::cout << "Enter the width of the rectangle: ";
	std::cin >> width;

	int height = 0;
	std::cout << "Enter the height of the rectangle: ";
	std::cin >> height;

	int Square = width * height;
	int Perimeter = (width * 2) + (height * 2);

	std::cout << "Square of the rectangle: " << Square << std::endl;
	std::cout << "Perimeter of the rectangle: " << Perimeter << std::endl;

	return 0;
}
