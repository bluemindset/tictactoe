

#include <iostream>
#include "tik.h"

stateTT *TikTak::getState() const
{
    return state;
};

bool TikTak::isSolved()
{

    for (int i = 0; i < 3; ++i)
    {
        if (state->table[i][0] == 0 || state->table[i][0] == 1)
        {
            if (state->table[i][0] == state->table[i][1] && state->table[i][1] == state->table[i][2])
            {
                winner = state->table[i][0];
                setSolved(true);
                break;
            }
        }
    }

    if (winner == -1)
    {

        for (int i = 0; i < 3; ++i)
        {
            if (state->table[i][0] == 0 || state->table[i][0] == 1)

                if (state->table[0][i] == state->table[1][i] && state->table[1][i] == state->table[2][i])
                {
                    winner = state->table[0][i];
                    setSolved(true);

                    break;
                }
        }
    }

    // Check diagonals for a winner
    if (winner == -1)
    { // Only check if no winner yet
        if (state->table[0][0] == 0 || state->table[0][0] == 1 || state->table[2][0] == 0 || state->table[2][0] == 1)
        {

            if (state->table[0][0] == state->table[1][1] && state->table[1][1] == state->table[2][2])
            {
                winner = state->table[0][0];
                setSolved(true);
            }
            // Anti-diagonal
            else if (state->table[0][2] == state->table[1][1] && state->table[1][1] == state->table[2][0])
            {
                winner = state->table[0][2];
                setSolved(true);
            }
        }
    }

    return solved;
};

void TikTak ::setSolved(bool s)
{
    solved = s;
};

void TikTak::setState(int col, int row, int user)
{
    state->table[row][col] = user;
};

void TikTak::print() const
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << state->table[i][j] << " ";
        }
        std::cout << "\n";
    }
};

TikTak::TikTak()
{
    state = (stateTT *)malloc(sizeof(stateTT));
    state->table = (int **)malloc(sizeof(int *) * 3);
    std::cout << "Constructor TitTak" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        state->table[i] = (int *)malloc(sizeof(int) * 3);
        for (int j = 0; j < 3; j++)
        {
            state->table[i][j] = -1;
        }
    }
    solved = false;
};

TikTak::~TikTak()
{
    std::cout << "Destructor TitTak" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        free(state->table[i]);
    }
    free(state->table);
    free(state);
};