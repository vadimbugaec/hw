#include "hw8loop.h"

int main()
{
    int N;
    std::cout << "Enter the value of N: ";
    std::cin >> N;
    printNaturalNumbers1(N);

    int N2;
    std::cout << "Enter the value of N: ";
    std::cin >> N2;
    printNaturalNumbers2(N2);

    std::cout << "LOOP" << std::endl;
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;
    int result = factorial(num);
    std::cout << num << "! = " << result << std::endl;
}
