#include "hw8rec.h"

int main()
{
	int num;
	std::cout << "Enter a number: ";
	std::cin >> num;
	int result = factorialrec(num);
	std::cout << num << "! = " << result << std::endl;


	int N3;
	std::cout << "Enter the value of N: ";
	std::cin >> N3;
	printNaturalNumbers3(N3);

	int N4;
	std::cout << std::endl << "Enter the value of N: ";
	std::cin >> N4;
	printNaturalNumbers4(N4);

	return 0;
}
