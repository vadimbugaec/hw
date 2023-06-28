#include <iostream>

int main()
{
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;
    std::cout << "Enter third number: ";
    std::cin >> num3;

    int sum = num1 + num2 + num3;
    std::cout << "Sum: " << sum << std::endl;

    int product = num1 * num2 * num3;
    std::cout << "Product: " << product << std::endl;

    int average = sum / 3;
    std::cout << "average: " << average << std::endl;

    bool compr = num1 > num2;
    std::cout << "First num is bigger than second num: " << std::boolalpha << compr << std::endl;

    bool compr2 = num2 > num3;
    std::cout << "Second num is bigger than third num: " << std::boolalpha << compr2 << std::endl;

    return 0;
}
