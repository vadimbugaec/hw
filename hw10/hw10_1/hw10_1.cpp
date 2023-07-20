#include <iostream>

using namespace std;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap2(int& a, int& b) 
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int num1 = 0;
    int num2 = 0;

    cout << "Enter first number: "; 
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    cout << "Num1 = " << num1 << " and Num2 = " << num2 << endl;
    swap(&num1, &num2);
    cout << "After swap: " << "Num1 = " << num1 << " and Num2 = " << num2 << endl;
    cout << "\nTHE END OF THE FIRST PART\n" << endl;

    int x = 0;
    int y = 0;
    cout << "Enter first number: ";
    cin >> x;
    cout << "Enter second number: ";
    cin >> y;

    std::cout << "X = " << x << " and Y = " << y << endl;
    swap2(x, y);
    std::cout << "After swap: X = " << x << " and Y = " << y << endl;
}
