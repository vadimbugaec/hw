#include <iostream>

using namespace std;

bool calculateSum(double* arr, int arrSize, double& sum) 
{
    if (arrSize <= 0) 
    {
        return false;
    }
    sum = 0.0;
    for (int i = 0; i < arrSize; i++) 
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
        sum += arr[i];
    }
    return true;
}

int main() {
    const int MAX = 5;
    double arr[MAX];
    int arrSize = 5;
    double sum = 0.0;

    if (calculateSum(arr, arrSize, sum)) 
    {
        cout << "Sum of elements: " << sum << endl;
    }
    else
    {
        cout << "Array size is not positive." << endl;
    }

    return 0;
}