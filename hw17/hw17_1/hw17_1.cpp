#include "DynamicArray.h"

int main() 
{
    DynamicIntArray arr;

    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    std::cout << "Array size: " << arr.getSize() << std::endl;

    std::cout << "Array elements: ";
    for (std::size_t i = 0; i < arr.getSize(); i++) 
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    arr.setSize(5);

    for (std::size_t i = 0; i < arr.getSize(); i++) 
    {
        arr[i] = i * 10;
    }

    std::cout << "Upd array: ";
    for (std::size_t i = 0; i < arr.getSize(); i++) 
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Array size: " << arr.getSize() << std::endl;

    arr.clear();

    std::cout << "Size of array after clear: " << arr.getSize() << std::endl;

    return 0;
}