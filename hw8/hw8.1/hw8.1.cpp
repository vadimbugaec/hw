#include <iostream>

void TaskOne(int count)
{
	int positive = 0;
	int negative = 0;
	int zero = 0;

	for (int i = 0; i < count; i++)
	{
		int num;
		std::cout << "Enter number " << i + 1 << " :";
		std::cin >> num;

		if (num > 0)
		{
			positive++;
		}
		else if (num < 0)
		{
			negative++;
		}
		else
		{
			zero++;
		}
	}
	std::cout << "Positive: " << positive << " Negative: " << negative << " Zeroes: " << zero << std::endl;
}

int main()
{
	int count;
	std::cout << "Enter number of numbers to inp: ";
	std::cin >> count;

	TaskOne (count);
	return 0;
}