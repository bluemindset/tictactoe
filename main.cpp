#include <iostream>
#include "tiktak/tik.h"
#include "utils/utils.h"

void dialog(int row, int col, TikTak *tt, int user)
{
    bool flag = true;
    while (flag)
    {
        row = sanitize(user, "row");
        col = sanitize(user, "col");
        if (tt->getState()->table[row][col] == -1 && tt->getState()->table[row][col] == -1)
        {
            tt->setState(row, col, user);
            flag = false;
        }
        else
        {
            std::cout << "Cannot insert row col, as it is occupied" << endl;
        }
    }
};

int main()
{
    TikTak tiktak;

    int row = 0;
    int col = 0;

    while (!tiktak.isSolved())
    {
        dialog(row, col, &tiktak, 0);
        tiktak.print();
        dialog(row, col, &tiktak, 1);
        tiktak.print();
    }

    std::cout << "Finalizing program";
    return 0;
}
