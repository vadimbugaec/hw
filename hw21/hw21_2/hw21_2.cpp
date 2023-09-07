#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compareByLength(const string& a, const string& b) 
{
    return a.length() < b.length();
}

struct LengthComparator {
    bool operator()(const string& a, const string& b) 
    {
        return a.length() < b.length();
    }
};

int main() {
    vector<string> stringContainer = { "bmw", "mersedes", "audi", "mazda", "nissan" };

    sort(stringContainer.begin(), stringContainer.end(), compareByLength);

    cout << "Sorted by function:" << endl;
    for (const string& str : stringContainer) 
    {
        cout << str << endl;
    }

    LengthComparator lengthComparator;
    sort(stringContainer.begin(), stringContainer.end(), lengthComparator);

    cout << "\nSorted by functor:" << endl;
    for (const string& str : stringContainer) 
    {
        cout << str << endl;
    }

    sort(stringContainer.begin(), stringContainer.end(), [](const string& a, const string& b) 
        {
        return a.length() < b.length();
        });

    cout << "\nSorted by lambda:" << endl;
    for (const string& str : stringContainer) 
    {
        cout << str << endl;
    }

    return 0;
}