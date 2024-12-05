
#include <iostream>
#include <limits>
#include "utils.h"

bool checkNum(int val)
{
    if (val != 0 && val != 1 && val != 2)
    {
        std::cout << "Invalid input. Please enter numbers 1,2,3 only! \n";
        return false;
    }

    return true;
}

int sanitize(int user, char *rc)
{
    int val;
    while (true)
    {
        std::cout << "User " << user << ", please insert " << rc << " position X: ";
        std::cin >> val;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again.\n";
        }
        else
        {
            if (checkNum(val))
            {
                return val;
            }
        }
    }
}