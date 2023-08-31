#include <iostream>
#include <string>
#include <set>
#include <sstream>

using namespace std;

unsigned int uniqueWordsCount(const string& line) {
    istringstream iss(line);
    string word;
    set<string> uniqueWords;

    while (iss >> word) 
    {
        uniqueWords.insert(word);
    }

    return uniqueWords.size();
}

int main() {
    string line = "Hello Hey Hello Bye Hey Hi Hey Hey Hi Hey Hi Go Go Go";
    unsigned int count = uniqueWordsCount(line);
    cout << "Count of unique words: " << count << endl;
    return 0;
}