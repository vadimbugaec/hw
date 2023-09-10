#include <iostream>
#include <stdexcept>
#include "hw23.h"

using namespace std;

int main() {
    try {

        DynamicArray<int> intArray;

        intArray.push_back(10);
        intArray.push_back(20);
        intArray.push_back(30);

        cout << "Elements in intArray:" << endl;
        for (size_t i = 0; i < intArray.getSize(); ++i) 
        {
            cout << intArray[i] << " ";
        }
        cout << endl;

        DynamicArray<double> doubleArray;

        doubleArray.push_back(3.14);
        doubleArray.push_back(2.718);

        cout << "Elements in doubleArray:" << endl;
        for (size_t i = 0; i < doubleArray.getSize(); ++i) 
        {
            cout << doubleArray[i] << " ";
        }
        cout << endl;

        cout << "intArray size: " << intArray.getSize() << " Capacity: " << intArray.getCapacity() << endl;
        cout << "doubleArray size: " << doubleArray.getSize() << " Capacity: " << doubleArray.getCapacity() << endl;

        intArray.clear();
        doubleArray.clear();
    }
    catch (const out_of_range& e) 
    {
        cerr << "Out of Range Error: " << e.what() << endl;
    }
    return 0;
}