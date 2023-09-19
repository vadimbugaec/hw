#pragma once
#include <cstdlib>
#include <iostream>

class DynamicIntArray
{
public:
    DynamicIntArray() : data(nullptr), size(0) {}
    DynamicIntArray(std::size_t size) : data(new int[size]), size(size) {}
    DynamicIntArray(const DynamicIntArray& other) : size(other.size), data(new int[other.size]) 
    {
        for (std::size_t i = 0; i < size; i++) 
        {
            data[i] = other.data[i];
        }
    }
    ~DynamicIntArray() 
    {
        delete[] data;
    }

    DynamicIntArray& operator=(const DynamicIntArray& other) 
    {
        if (this != &other) 
        {
            delete[] data;
            size = other.size;
            data = new int[size];
            for (std::size_t i = 0; i < size; i++) 
            {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    int& operator[](std::size_t index) 
    {
        if (index >= size) 
        {
            throw std::out_of_range("Out of range");
        }
        return data[index];
    }

    void setSize(std::size_t newSize) 
    {
        delete[] data;
        data = new int[newSize];
        size = newSize;
    }

    std::size_t getSize() const 
    {
        return size;
    }

    void clear() 
    {
        delete[] data;
        data = nullptr;
        size = 0;
    }

    void push_back(int element) 
    {
        int* newData = new int[size + 1];
        for (std::size_t i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        newData[size] = element;
        delete[] data;
        data = newData;
        size++;
    }

private:
    int* data;
    std::size_t size;
};
