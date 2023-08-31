#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <unordered_map>
#include <sstream>

using namespace std;

string mostOccuredWord(const string& line) 
{
    unordered_map<string, int> wordCount;
    istringstream iss(line);
    string word;

    while (iss >> word) 
    {
        string cleanedWord;
        for (char c : word) {
            if (isalpha(c) || isdigit(c)) 
            {
                cleanedWord += c;
            }
        }
        if (!cleanedWord.empty()) {
            wordCount[cleanedWord]++;
        }
    }

    string mostCommonWord;
    int maxCount = 0;
    for (const auto& pair : wordCount) 
    {
        if (pair.second > maxCount) 
        {
            maxCount = pair.second;
            mostCommonWord = pair.first;
        }
    }
    return mostCommonWord;
}

int main() 
{
    
    string line = "Hi, Hi, hi, I dont know what sentence to write so i`ll just leave this nonsense here)";
    transform(line .begin(), line.end(), line.begin(), ::tolower);
    string mostCommon = mostOccuredWord(line);
    cout << "Most used word: " << mostCommon << endl;

    return 0;
}