#include <iostream>

int main()
{
    int a, b, c;
    std::cout << "Enter first angle:";
    std::cin >> a;
    std::cout << "Enter second angle:";
    std::cin >> b;
    std::cout << "Enter third angle:";
    std::cin >> c;

    if (a + b + c == 180)
    {
        std::cout << "Its a triangle" << std::endl;
    }
    else
    {
        std::cout << "Its not a triangle" << std::endl;
    }
    return 0;
}
