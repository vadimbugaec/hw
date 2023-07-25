#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

void toUppercase(char str[])
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 'a' + 'A';
		}
	}
}

bool isPalindrom(const char str[]) 
{
	int length = strlen(str);
	int i = 0;
	int j = length - 1;
	while (i < j) 
	{
		if ((str[i]) != (str[j])) 
		{
			return false;
		}
		i++;
		j--;
	}
	return true;
}

void parseStringLetters(const char str[], int& vowelsCount, int& consonantsCount) 
{
	vowelsCount = 0;
	consonantsCount = 0;

	for (int i = 0; str[i] != '\0'; i++) 
{
		char ch = tolower(str[i]);

		if (isalpha(ch)) 
		{
			if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') 
			{
				vowelsCount++;
			}
			else {
				consonantsCount++;
			}
		}
	}
}

bool isEqual(const char str1[], const char str2[]) 
{
	int i = 0;
	while (str1[i] != '\0' || str2[i] != '\0') 
	{
		if (str1[i] != str2[i]) 
		{
			return false;
		}
		i++;
	}
	if (str1[i] == '\0' && str2[i] == '\0') 
	{
		return true;
	}

	return false;
}

	int main()
	{
		//SecondTask
		const int word = 100;
		char input[word];

		cout << "Enter word: ";
		cin.getline (input, word);

		toUppercase(input);

		cout << "Output: " << input << endl;

		//ThirdTask
		const int wordtwo = 100;
		char inputtwo[wordtwo];

		cout << "Enter a palindrom: ";
		cin.getline(inputtwo, wordtwo);

		if (isPalindrom(inputtwo)) 
		{
			cout << "Output: true" << std::endl;
		}
		else 
		{
			cout << "Output: false" << std::endl;
		}

		//TaskFour
		const int wordthree = 100;
		char inputthree[wordthree];
		int vowelsCount = 0;
		int consonantsCount = 0;
		cout << "Enter word: ";
		cin.getline(inputthree, wordthree);

		parseStringLetters(inputthree, vowelsCount, consonantsCount);

		cout << "Vowels count: " << vowelsCount << endl;
		cout << "Consonants count: " << consonantsCount << endl;

		//TaskFive
		const int wordidk = 100;
		char inputidk1[wordidk];
		char inputidk2[wordidk];

		cout << "Enter the first word: ";
		cin.getline(inputidk1, wordidk);

		cout << "Enter the second word: ";
		cin.getline(inputidk2, wordidk);

		if (isEqual(inputidk1, inputidk2)) 
		{
			cout << "The words are equal." << endl;
		}
		else 
		{
			cout << "The words are not equal." << endl;
		}

	}