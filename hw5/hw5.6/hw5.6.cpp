#include <iostream>

int main() {
    int monthNumber;
    std::cout << "Enter month number: ";
    std::cin >> monthNumber;

    switch (monthNumber) {
    case 1:
        std::cout << "Winter" << std::endl;
        break;
    case 2:
        std::cout << "Winter" << std::endl;
        break;
    case 3:
        std::cout << "Spring" << std::endl;
        break;
    case 4:
        std::cout << "Spring" << std::endl;
        break;
    case 5:
        std::cout << "Spring" << std::endl;
        break;
    case 6:
        std::cout << "Summer" << std::endl;
        break;
    case 7:
        std::cout << "Summer" << std::endl;
        break;
    case 8:
        std::cout << "Summer" << std::endl;
        break;
    case 9:
        std::cout << "Fall" << std::endl;
        break;
    case 10:
        std::cout << "Fall" << std::endl;
        break;
    case 11:
        std::cout << "Fall" << std::endl;
        break;
    case 12:
        std::cout << "Winter" << std::endl;
        break;
    default:
        std::cout << "Wrong mouth number" << std::endl;
        return 0;
    }
}
