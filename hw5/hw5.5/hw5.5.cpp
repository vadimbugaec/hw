#include <iostream>

enum class Month {
    January,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

int main() {
    int monthNumber;

    std::cout << "Enter month number: ";
    std::cin >> monthNumber;

    Month month;

    switch (monthNumber) {
    case 1:
        month = Month::January;
        std::cout << "January" << std::endl;
        break;
    case 2:
        month = Month::February;
        std::cout << "February" << std::endl;
        break;
    case 3:
        month = Month::March;
        std::cout << "March" << std::endl;
        break;
    case 4:
        month = Month::April;
        std::cout << "April" << std::endl;
        break;
    case 5:
        month = Month::May;
        std::cout << "May" << std::endl;
        break;
    case 6:
        month = Month::June;
        std::cout << "June" << std::endl;
        break;
    case 7:
        month = Month::July;
        std::cout << "July" << std::endl;
        break;
    case 8:
        month = Month::August;
        std::cout << "August" << std::endl;
        break;
    case 9:
        month = Month::September;
        std::cout << "September" << std::endl;
        break;
    case 10:
        month = Month::October;
        std::cout << "October" << std::endl;
        break;
    case 11:
        month = Month::November;
        std::cout << "November" << std::endl;
        break;
    case 12:
        month = Month::December;
        std::cout << "December" << std::endl;
        break;
    default:
        std::cout << "Wrong mouth number" << std::endl;
        return 0;
    }

    /*switch (month) {
    case Month::January:
        std::cout << "January" << std::endl;
        break;
    case Month::February:
        std::cout << "February" << std::endl;
        break;
    case Month::March:
        std::cout << "March" << std::endl;
        break;
    case Month::April:
        std::cout << "April" << std::endl;
        break;
    case Month::May:
        std::cout << "May" << std::endl;
        break;
    case Month::June:
        std::cout << "June" << std::endl;
        break;
    case Month::July:
        std::cout << "July" << std::endl;
        break;
    case Month::August:
        std::cout << "August" << std::endl;
        break;
    case Month::September:
        std::cout << "September" << std::endl;
        break;
    case Month::October:
        std::cout << "October" << std::endl;
        break;
    case Month::November:
        std::cout << "November" << std::endl;
        break;
    case Month::December:
        std::cout << "December" << std::endl;
        break;
    }*/
}