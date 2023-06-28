#include <iostream>

int main()
{
    int Totalsec = 0;
    std::cout << "Enter total seconds count:";
    std::cin >> Totalsec;

    int hours = Totalsec / 3600;
    std::cout << hours << " hour ";

    int min = Totalsec % 3600 / 60;
    std::cout << min << " minutes ";

    int sec = Totalsec % 3600 % 60;
    std::cout << sec << " seconds";
    
    return 0;
}
