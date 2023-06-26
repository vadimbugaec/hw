#include <iostream>
#include <iomanip>

int main()
{
	double p = 3.14159265358979323846;

    std::cout << "Default variable value: " << p << std::endl;

    std::cout << "Variable value with 2 numbers after dot : " << std::fixed << std::setprecision(2) << p << std::endl;

    std::cout << "Variable value with 5 numbers after dot: " << std::fixed << std::setprecision(5) << p << std::endl;

    std::cout << "Variable value with 10 numbers after dot: " << std::fixed << std::setprecision(10) << p << std::endl;

    std::cout << "Variable value in standart notation: " << std::defaultfloat << p << std::endl;

    std::cout << "Variable value in e-notation: " << std::scientific << p << std::endl;
    
    return 0;
}
