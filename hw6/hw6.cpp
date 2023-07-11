#include <iostream>
#include <cstring>

void FirstTask()
{
    int d, firstElement, numberOfLastElement;
    std::cout << "Enter first element of progression: ";
    std::cin >> firstElement;
    std::cout << "Enter number of last element of progression: ";
    std::cin >> numberOfLastElement;
    std::cout << "Enter step of progression: ";
    std::cin >> d;

    while (firstElement < d * numberOfLastElement)
    {
        std::cout << std::endl << "\t" << firstElement;
        firstElement += d;
    }
}

void SecondTask()
{
    int fib1 = 1, fib2 = 1, number, fib_sum = 0;
    std::cout << std::endl << "Enter Fibonacci number: ";
    std::cin >> number;

    if (number == 1 || number == 2)
    {
        std::cout << "Fibonacci number equal = 1" << std::endl;
        return;
    }
    for (int i = 0; i < number - 2; i++)
    {
        fib_sum = fib1 + fib2;
        fib1 = fib2;
        fib2 = fib_sum;
    }
    std::cout << "Fibonacci number equal = " << fib_sum << std::endl;

}

void ThirdTask()
{
    int number, sum = 1;
    std::cout << "Enter number: ";
    std::cin >> number;
    for (int i = 1; i <= number; i++)
    {
        sum *= i;
    }
    std::cout << "The result is: " << sum << std::endl;
}

void FourthTask()
{
    int height, length;
    std::cout << "Enter height of triangle: ";
    std::cin >> height;
    std::cout << "Enter length of triangle: ";
    std::cin >> length;
    int temp = length;
    for (int i = 0; i < height; i++)
    {

        for (int k = temp; k > 0; k--)
        {
            std::cout << "*";
        }
        temp--;
        std::cout << std::endl;
    }
    temp = 1;
    std::cout << std::endl;
    for (int i = 0; i < height; i++)
    {

        for (int k = 0; k < temp; k++)
        {
            std::cout << "*";
        }
        temp++;
        std::cout << std::endl;
    }
    std::cout << std::endl;
    for (int i = 0; i < height; i++)
    {

        for (int k = 0; k < length; k++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    temp = 1;
    std::cout << std::endl;
    for (int i = 0; i < height; i++)
    {

        for (int k = 1; k <= temp; k++)
        {
            if (k % 2 == 1)
            {
                std::cout << "1";
            }
            else
            {
                std::cout << "0";
            }
        }
        temp++;
        std::cout << std::endl;
    }
}

void FifthTask()
{
    char symbol;
    int sum = 0;
    while (true)
    {
        std::cout << "Enter any symbol: ";
        std::cin >> symbol;
        if (symbol >= 'a' && symbol <= 'z')
        {
            putchar(toupper(symbol));
            std::cout << std::endl;
        }
        else if (symbol == '.')
        {
            break;
        }
        else if (symbol >= '0' && symbol <= '9')
        {
            sum += (symbol - '0');
            std::cout << sum << std::endl;
        }
        else
        {
            std::cout << "Cant operate with this symbol" << std::endl;
        }
    }
}

int main()
{
    FirstTask();
    SecondTask();
    ThirdTask();
    FourthTask();
    FifthTask();
}