#include <iostream>

int main()
{
    int a, b;

    std::cout << "Enter first number: ";
    std::cin >> a;
    std::cout << "Second number: ";
    std::cin >> b;

    int min = (a < b) ? a : b;
    std::cout << "Min number: " << min << std::endl;

    return 0;
}