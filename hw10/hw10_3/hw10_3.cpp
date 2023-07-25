#include <iostream>

using namespace std;

bool find(const int* arr, int size, int elem) 
{
    const int* endPtr = arr + size;
    for (const int* ptr = arr; ptr < endPtr; ptr++) 
    {
        if (*ptr == elem) 
        {
            return true;
        }
    }
    return false;
}

int main() {
    const int MAX = 5;
    int arr[MAX] = { 1, 2, 3, 4, 5 };
    int arrSize = 5;
    int numToFind;

    cout << "Enter number to find: ";
    cin >> numToFind;

    if (find(arr, arrSize, numToFind)) {
        std::cout << "Number found" << endl;
    }
    else {
        std::cout << "Number isn`t found" << endl;
    }
    return 0;
}