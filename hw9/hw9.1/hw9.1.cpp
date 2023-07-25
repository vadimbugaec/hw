#include <iostream>

using namespace std;

void translateArray(int numbers[], int size)
{
	for (int i = 0; i < 10; i++)
	{
		if (numbers[i] > 0)
		{
			numbers[i] *= 2;
		}
		else
		{
			numbers[i] = 0;
		}
	}
}

int main()
{
	int numbers[10];
	cout << "Enter 10 numbers: " << endl;
	for (int i = 0; i < 10; i++)
	{
		cin >> numbers[i];
	}
	translateArray(numbers, 10);
	cout << "\nProcessed numbers: ";
	for (int i = 0; i < 10; i++)
	{
		cout << numbers[i] << " ";
	}
	cout << endl;
}