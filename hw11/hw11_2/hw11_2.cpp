#include <iostream>

using namespace std;

//enum class SortingDirection {ascending, decending};
//
//bool isSorted(const int* arr)
//{
//	SortingDirection sorting;
//	if (arr[0] < arr[1])
//	{
//		sorting = SortingDirection::decending;
//	}
//	else
//	{
//		sorting = SortingDirection::ascending;
//	}
//	return bool(sorting);
//}
//
//int main()
//{
//	const int count = 10;
//	int arr[count] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//    cout << boolalpha << isSorted(arr);
//}

enum class SortingDirection { ascending, descending };

bool isSorted(const int* arr, SortingDirection direction) 
{
    if (direction == SortingDirection::ascending) 
    {
        for (int i = 1; i < 5; i++) 
        {
            if (arr[i] < arr[i - 1]) 
            {
                return false;
            }
        }
    } 
    else if (direction == SortingDirection::descending) 
    {
        for (int i = 1; i < 5; i++) 
        {
            if (arr[i] > arr[i - 1]) 
            {
                return false;
            }
        }
    }
    return true;
}

int main() 
{
    const int arrsize = 5;
    int ascendingArr[arrsize] = {1, 2, 3, 4, 5};
    int descendingArr[arrsize] = {5, 4, 3, 2, 1};

    if (isSorted(ascendingArr, SortingDirection::ascending)) 
    {
        cout << "Sorted in ascending order." << endl;
    } 
    else 
    {
        cout << "Not sorted in ascending order." << endl;
    }

    if (isSorted(descendingArr, SortingDirection::descending)) 
    {
        cout << "Sorted in descending order." << endl;
    } 
    else 
    {
        cout << "Not sorted in descending order." << endl;
    }

    return 0;
}
