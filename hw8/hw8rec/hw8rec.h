#pragma once
#include <iostream>

int factorialrec(int count);
void printNaturalNumbers3(int count);

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
	else {
		std::cout;
	}
}

void printNaturalNumbers4(int count) {
	if (count > 0) {
		printNaturalNumbers4(count - 1);
		std::cout << count << " ";
	}
	else {
		std::cout;
	}
}



