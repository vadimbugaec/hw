#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#define NUMBER_OF_WORDS 10

using namespace std;


int getDay(const tm* tmObj)
{
    return tmObj->tm_mday;
}

int getMonth(const tm* tmObj)
{
    return tmObj->tm_mon + 1;
}

int getYear(const tm* tmObj)
{
    return tmObj->tm_year + 1900;
}


string compareWords(const string& guessedWord, const string& secretWord)
{
    string result;
    if (guessedWord.length() != secretWord.length())
    {
        return "Invalid word length";
    }

    for (size_t i = 0; i < guessedWord.length(); i++)
    {
        if (guessedWord[i] == secretWord[i])
        {
            result += toupper(guessedWord[i]);
        }
        else if (secretWord.find(guessedWord[i]) != string::npos)
        {
            result += tolower(guessedWord[i]);
        }
        else
        {
            result += '*';
        }
    }

    return result;
}

void saveWordOfDay(const string& word)
{
    ofstream outputFile("word_of_day.txt", ios::app);
    if (outputFile.is_open()) {
        outputFile << word << endl;
        outputFile.close();
    }
}

string readWordOfDay() {
    srand((time(NULL)));
    ifstream inputFile("word_of_day.txt");
    string words[NUMBER_OF_WORDS];
    int numberOfRow = rand() % NUMBER_OF_WORDS, i = 0;
    if (inputFile.is_open())
    {
        while (!inputFile.eof())
        {
            inputFile >> words[i];
            i++;
        }
    }
    return words[numberOfRow];
}
string readWordOfDay(int number) {
    ifstream inputFile("word_of_day.txt");
    string words[10];
    int i = 0;
    if (inputFile.is_open())
    {
        while (!inputFile.eof())
        {
            inputFile >> words[i];
            i++;
        }
    }
    return words[number];
}

bool checkGuessedWordOfDay(tm *now)
{
    ifstream inputFile("guessed_or_not_word_of_day.txt");
    string date = to_string(getDay(now)) + to_string(getMonth(now)) + to_string(getYear(now));
    string dateFromFile;
    if (inputFile.is_open())
    {
        while (!inputFile.eof())
        {
            inputFile >> dateFromFile;
        }
    }
    if (date == dateFromFile)
    {
        return true;
    }
    return false;
}

void writeGuessed(tm* now)
{
    ofstream outputFile("guessed_or_not_word_of_day.txt");
    string date = to_string(getDay(now)) + to_string(getMonth(now)) + to_string(getYear(now));
    if (outputFile.is_open()) {
        outputFile << date << endl;
        outputFile.close();
    }
}

void Game(string wordOfDay, tm *now)
{
    const int MAX_ATTEMPTS = 10;
    int attempts = 0;
    cout << "WORDLE OF THE DAY " << endl;
    cout << "TRY TO GUESS IT WITH " << MAX_ATTEMPTS << " ATEMPS." << endl;

    string guessedWord;

    while (attempts < MAX_ATTEMPTS)
    {
        cout << "Write word with " << wordOfDay.length() << " letters: ";
        cin >> guessedWord;

        if (guessedWord == wordOfDay)
        {
            cout << "Gratz, you guess the word! \"" << wordOfDay << "\"!\n";
            cout << "Atempt count: " << attempts + 1 << std::endl;
            writeGuessed(now);
            break;
        }
        else
        {
            string comparisonResult = compareWords(guessedWord, wordOfDay);
            cout << "Try № " << attempts + 1 << ": " << comparisonResult << endl;
        }

        attempts++;
    }

    if (attempts == MAX_ATTEMPTS)
    {
        std::cout << "You didnt guess, the word was: \"" << wordOfDay << "\"\n";
    }
}

void wordOfDay(tm *now)
{
    string wordOfDay;
    if (getDay(now) < NUMBER_OF_WORDS)
    {
        wordOfDay = readWordOfDay(getDay(now));
    }
    else
    {
        wordOfDay = readWordOfDay(getDay(now)% NUMBER_OF_WORDS);
    }
    if (checkGuessedWordOfDay(now))
    {
        cout << "You have already guessed the WORD OF THE DAY, come back tomorrow\n";
        return;
    }
    Game(wordOfDay,now);
    
}

void randomWord(tm *now)
{
    string wordOfDay = readWordOfDay();
    Game(wordOfDay,now);
}

void menu(tm*& now)
{
    while (true)
    {
        cout << "Current Date: " << getDay(now) << "-"
            << getMonth(now) << "-" << getYear(now) << endl;
        char choice = 0;
        cout << "1 - Word of the day" << "\n2 - Random Word" << "\n0 - Exit" << endl;
        cin >> choice;
        while (choice != 0)
        {
            switch (choice)
            {
            case '0':
            {
                return;
            }
            case '1':
            {
                wordOfDay(now);
                break;
            }
            case '2':
            {
                randomWord(now);
                break;
            }
            default:
            {
                cout << "Wrong number, try again" << endl;
                break;
            }
            }
            break;
        }
    }
}

    

int main()
{
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    menu(now);

    return 0;
}