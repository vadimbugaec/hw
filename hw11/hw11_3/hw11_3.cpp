#include <iostream>

using namespace std;

int main()
{
	const int rows = 4;
	const int col = 4;
	int arr[col] = { 1, 2, 3, 4 };

	int arr2d[rows][col] =
	{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};
	
	for (int j = col - 1; j >= 0; j--)
	{
		for (int i = 0; i < rows; i++)
		{
			cout << arr2d[i][j] << " ";
		}
		//cout << endl;
	}
	cout << endl;

	for (int i = rows - 1; i >= 0; i--) //13 14 15 16 12 11 10 9 5 6 7 8 4 3 2 1
	{
	//	for (int j = col - 1; j >= 0; j--)
	//	{
	//	}
		int j;
		if (i % 2 == 1)
		{
			j = 0;			
		}
		else
		{
			j = col - 1;
		}
		while (j < col && j >= 0)
		{
			cout << arr2d[i][j] << " ";
			if (i % 2 == 1)
			{
				j++;
			}
			else
			{
				j--;
			}
		}
	}
}
