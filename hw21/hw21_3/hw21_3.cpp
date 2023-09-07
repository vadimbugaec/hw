#include <iostream>
#include <vector>
#include <algorithm>

unsigned int countDivisibleBy(const std::vector<int>& vec, int number) 
{
    unsigned int count = std::count_if(vec.begin(), vec.end(), [number](int x) 
        {
        return x % number == 0;
        });

    return count;
}

int main() 
{
    std::vector<int> vec = { 10, 20, 30, 40, 50, 60, 70 };
    int number = 10;

    unsigned int result = countDivisibleBy(vec, number);
    std::cout << "count of elements dividible by " << number << " on purpose: " << result << std::endl;

    return 0;
}