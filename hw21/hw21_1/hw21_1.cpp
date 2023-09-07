#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

//val виходила за область видимості.

unsigned int countDivisibleBy(const vector<int>& vec, int number)
{
    unsigned int count = 0;
    for (int value : vec)
    {
        if (value % number == 0)
        {
            count++;
        }
    }
    return count;
}

function<string()> makeLambda()
{
    const string val = "string";
    return [val] { return val; };
}

int main()
{
    auto bad = makeLambda();
    cout << bad() << endl;

    vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int divisor = 3;
    unsigned int result = countDivisibleBy(numbers, divisor);
    cout << "Count of number divisible by " << divisor << ": " << result << endl;

    return 0;
}