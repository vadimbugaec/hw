#include <iostream>

//Recursion
int factorialrec(int count)
{
	int result = 1;
	if (count == 1)
	{
		return 1;
	}
	else
	{
		result = count * factorialrec(count - 1);
	}
	return result;
}

void printNaturalNumbers3(int count)
{
	if (count > 0) {
		std::cout << count << " ";
		printNaturalNumbers3(count - 1);
	}
}

void printNaturalNumbers4(int count) {
	if (count > 0) {
		printNaturalNumbers4(count - 1);
		std::cout << count << " ";
	}
}

//Loop
int factorial(int count)
{
	int resultx = 1;
	for (int i = 1; i <= count; i++)
	{
		resultx *= i;
	}
	return resultx;
}

void printNaturalNumbers1(int count)
{
	for (int i = count; i >= 1; i--) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

void printNaturalNumbers2(int count)
{
	for (int i = 1; i <= count; i++) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

int main()
{
	//Recursion
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
	

	//Loop
	int N;
	std::cout << "\n\nLoop" << std::endl;
	std::cout << "Enter the value of N: ";
	std::cin >> N;
	printNaturalNumbers1(N);

	int N2;
	std::cout << "Enter the value of N: ";
	std::cin >> N2;
	printNaturalNumbers2(N2);

	int numx;
	std::cout << "Enter a number: ";
	std::cin >> numx;
	int resultx = factorial(numx);
	std::cout << numx << "! = " << resultx << std::endl;
}
