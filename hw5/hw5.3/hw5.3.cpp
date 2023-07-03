#include <iostream>

int main()
{
    int a;
    std::cout << "Enter number: ";
    std::cin >> a;

    if (a % 11 == 0 && a % 5 == 0)
    {
        std::cout << "The number is divisible by 5 and 11 at the same time" << std::endl;
    }
    else
    {
        std::cout << "The number isn`t divisible by 5 and 11 at the same time" << std::endl;
    }
    return 0;
}