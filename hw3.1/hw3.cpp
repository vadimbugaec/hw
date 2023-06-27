#include <iostream>

int main()
{
	std::cout << "Enter integer 1:";
	int a;
	std::cin >> a;

	int b;
	std::cout << "Enter integer 2:";
	std::cin >> b;

	int c = a;
	a = b;
	b = c;

	std::cout << "Intager 1:" << a << std::endl;
	std::cout << "Intager 2:" << b << std::endl;
}
