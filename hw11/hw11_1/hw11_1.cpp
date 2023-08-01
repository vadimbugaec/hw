#include <iostream>

using namespace std;

	const int Rows = 3;
	const int Columns = 5;

bool find(int arr[][Columns], int toFind)
{
	const int Rows = 3;
	const int Columns = 5;

	for (unsigned int i = 0; i < Rows; i++)
	{
		for (unsigned int j = 0; j < Columns; j++)
		{
			if (arr[i][j] == toFind)
				return true;
		}
	}
	return false;
}

int main()
{
	int arr2d[Rows][Columns] = {
		{11, 12, 13, 14, 15},
		{21, 22, 23, 24, 25},
		{31, 32, 33, 34, 35}
	};

	int numbertofind = 0;
	cout << "Enter number to find: ";
	cin >> numbertofind;

	if (find(arr2d, numbertofind))
	{
		cout << "Number is found";
	}
	else
	{
		cout << "Number isn`t found";
	}
	return 0;
}
