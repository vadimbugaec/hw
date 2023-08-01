#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

const char* database[] = { "WORD1", "WORD2", "WORDN" };

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


const char* getRandomWord() {
    int index = rand() % (sizeof(database) / sizeof(database[0]));
    return database[index];
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
    ofstream outputFile("word_of_day.txt");
    if (outputFile.is_open()) {
        outputFile << word;
        outputFile.close();
    }
}

string readWordOfDay() {
    ifstream inputFile("word_of_day.txt");
    std::string word;
    if (inputFile.is_open()) 
    {
        inputFile >> word;
        inputFile.close();
    }
    return word;
}

int main() 
{
    time_t t = time(nullptr);
    tm* now = localtime(&t);

    cout << "Current Date: " << getDay(now) << "-"
        << getMonth(now) << "-" << getYear(now) << endl;

    srand(static_cast<unsigned int>(time(0)));

    const int MAX_ATTEMPTS = 10;
    int attempts = 0;

    string wordOfDay = readWordOfDay();
    if (wordOfDay.empty()) 
    {
        wordOfDay = getRandomWord();
        saveWordOfDay(wordOfDay);
    }

    cout << "WORDLE OF THE DAY "<< endl;
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
            saveWordOfDay(getRandomWord());
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

    return 0;
}