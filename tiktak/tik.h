#include <iostream>

struct stateTT
{
    int **table;
    int rounds;
};

class TikTak
{
public:
    // Constuctor
    TikTak();
    // Destuctor
    ~TikTak();

    stateTT *getState() const;
    bool isSolved();

    void setState(int, int, int);
    void setSolved(bool);
    void print() const;

private:
    bool solved = 0;
    int winner = -1;
    stateTT *state;

    int winningStates[8][3][2] = {
        // Rows
        {{0, 0}, {0, 1}, {0, 2}},
        {{1, 0}, {1, 1}, {1, 2}},
        {{2, 0}, {2, 1}, {2, 2}},
        // Columns
        {{0, 0}, {1, 0}, {2, 0}},
        {{0, 1}, {1, 1}, {2, 1}},
        {{0, 2}, {1, 2}, {2, 2}},
        // Diagonals
        {{0, 0}, {1, 1}, {2, 2}},
        {{0, 2}, {1, 1}, {2, 0}}};
};
