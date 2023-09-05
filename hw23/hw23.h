#pragma once
#include <cstdlib>
#include <cstring>
#include <stdexcept>

template <typename T>
class DynamicArray
{
public:
    DynamicArray();
    DynamicArray(size_t size);
    DynamicArray(const DynamicArray<T>& other);
    ~DynamicArray();

    DynamicArray<T>& operator=(const DynamicArray<T>& other);
    T& operator[](size_t index);

    void setSize(size_t newSize);

    size_t getSize() const;

    void clear();

    void reserve(size_t reservedSpace);

    size_t getCapacity() const;

    void shrinkToFit();

    void push_back(const T& element);

    void pop_back();

    T back() const;

    bool operator==(const DynamicArray<T>& other) const;

private:
    T* arr;
    size_t size;
    size_t capacity;
};

template <typename T>
DynamicArray<T>::DynamicArray()
    : arr(nullptr), size(0), capacity(0) {}

template <typename T>
DynamicArray<T>::DynamicArray(size_t size)
    : arr(new T[size]), size(size), capacity(size) {}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other)
    : arr(new T[other.size]), size(other.size), capacity(other.size)
{
    memcpy(arr, other.arr, size * sizeof(T));
}

template <typename T>
DynamicArray<T>::~DynamicArray()
{
    delete[] arr;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other)
{
    if (this != &other)
    {
        delete[] arr;
        size = other.size;
        capacity = other.size;
        arr = new T[size];
        memcpy(arr, other.arr, size * sizeof(T));
    }
    return *this;
}

template <typename T>
T& DynamicArray<T>::operator[](size_t index)
{
    if (index >= size)
    {
        throw out_of_range("Index out of range");
    }
    return arr[index];
}

template <typename T>
void DynamicArray<T>::setSize(size_t newSize)
{
    reserve(newSize);
    size = newSize;
}

template <typename T>
size_t DynamicArray<T>::getSize() const
{
    return size;
}

template <typename T>
void DynamicArray<T>::clear()
{
    delete[] arr;
    arr = nullptr;
    size = 0;
    capacity = 0;
}

template <typename T>
void DynamicArray<T>::reserve(size_t reservedSpace)
{
    if (reservedSpace > capacity)
    {
        T* newArr = new T[reservedSpace];
        memcpy(newArr, arr, size * sizeof(T));
        delete[] arr;
        arr = newArr;
        capacity = reservedSpace;
    }
}

template <typename T>
size_t DynamicArray<T>::getCapacity() const
{
    return capacity;
}

template <typename T>
void DynamicArray<T>::shrinkToFit()
{
    if (size < capacity)
    {
        T* newArr = new T[size];
        memcpy(newArr, arr, size * sizeof(T));
        delete[] arr;
        arr = newArr;
        capacity = size;
    }
}

template <typename T>
void DynamicArray<T>::push_back(const T& element)
{
    if (size >= capacity)
    {
        reserve(capacity == 0 ? 1 : capacity * 2);
    }
    arr[size++] = element;
}

template <typename T>
void DynamicArray<T>::pop_back()
{
    if (size > 0)
    {
        --size;
    }
}

template <typename T>
T DynamicArray<T>::back() const
{
    if (size > 0)
    {
        return arr[size - 1];
    }
    throw out_of_range("Array is empty");
}

template <typename T>
bool DynamicArray<T>::operator==(const DynamicArray<T>& other) const
{
    if (size != other.size)
    {
        return false;
    }
    for (size_t i = 0; i < size; ++i)
    {
        if (arr[i] != other.arr[i])
        {
            return false;
        }
    }
    return true;
}