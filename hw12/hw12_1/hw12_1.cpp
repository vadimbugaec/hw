#include <iostream>

using namespace std;

void bubleSort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
			int temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
			}
		}
	}
}

int main()
{
	const int arrsize = 10;
	int bublearr[arrsize] = { 2, 5, 3, 1, 6, 8, 4, 7, 9, 10 };
	bubleSort(bublearr, arrsize);
	for (int i = 0; i < arrsize; i++)
	{
		cout << bublearr[i] << " ";
	}
	return 0;
}