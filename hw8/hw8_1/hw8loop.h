#pragma once
#include <iostream>

int factorial(int count);
void printNaturalNumbers1(int count);
void printNaturalNumbers2(int count);

int factorial(int count)
{
	int result = 1;
	for (int i = 1; i <= count; i++)
	{
		result *= i;
	}
	return result;
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
