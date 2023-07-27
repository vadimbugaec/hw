#include <iostream>

using namespace std;

const int COLUMN = 4;

enum class SortingDirection {ByRows, ByColumn};
//Я ненавижду енум клас))

void quickSort(int arr[], int low, int high, SortingDirection direction) 
{
    if (low < high) 
    {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) 
        {
            if (direction == SortingDirection::ByRows ? (arr[j] <= pivot) : (arr[j] >= pivot))
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[high]);
        quickSort(arr, low, i, direction);
        quickSort(arr, i + 2, high, direction);
    }
}

void sort(int arr[][COLUMN], int rows, SortingDirection direction)
{
    if (direction == SortingDirection::ByRows) 
    {
        for (int i = 0; i < rows; i++) 
        {
            quickSort(arr[i], 0, COLUMN - 1, SortingDirection::ByRows);
        }
    }
    else if (direction == SortingDirection::ByColumn) 
    {
        for (int j = 0; j < COLUMN; j++) 
        {
            int* columnArr = new int[rows];
            for (int i = 0; i < rows; i++) 
            {
                columnArr[i] = arr[i][j];
            }
            quickSort(columnArr, 0, rows - 1, SortingDirection::ByColumn);
            for (int i = 0; i < rows; i++) 
            {
                arr[i][j] = columnArr[i];
            }
        }
    }
}

void printArray(int arr[][COLUMN], int rows) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < COLUMN; j++) 
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int arr2d[3][COLUMN] = 
    {
        {3, 1, 4, 2},
        {8, 6, 7, 5},
        {12, 11, 10, 9}
    };

    cout << "Default array:" << endl;
    printArray(arr2d, 3);
    cout << endl;

    sort(arr2d, 3, SortingDirection::ByRows);
    cout << "Array sorted by rows:" << endl;
    printArray(arr2d, 3);
    cout << endl;

    sort(arr2d, 3, SortingDirection::ByColumn);
    cout << "Array sorted by columns:" << endl;
    printArray(arr2d, 3);

    return 0;
}
