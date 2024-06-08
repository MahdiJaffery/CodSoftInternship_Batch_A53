#include <iostream>
using namespace std;
char x, choice1, choice2, b[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
string Player1, Player2;
int win = 0;
void intro()
{
    cout << "==============================================================================" << endl
         << endl
         << "\t\t\t\tTic Tac Toe";
    cout << endl
         << endl
         << "==============================================================================" << endl
         << endl;
}
void rules()
{
    cout << "The Rules Are As Follows" << endl
         << endl
         << "1. The Grid Consists of 3 Rows and 3 Columns" << endl
         << endl
         << "2. Each Player Chooses a Row and Column to Place Their Symbol";
    cout << endl
         << endl
         << "3. Each Player Tries to Beat The Other One In Completing a Column, Row or Diagonal" << endl
         << endl
         << "4. First To Achieve This Wins" << endl
         << endl;
    cout << "==============================================================================" << endl
         << endl;
}
void drawBoard()
{
    cout << endl
         << endl
         << "\t\t\t   1       2       3" << endl
         << endl
         << "\t\t\t       |       |       " << endl;
    cout << "\t\t   1       " << b[0][0] << "   |   " << b[0][1] << "   |   " << b[0][2] << "   " << endl;
    cout << "\t\t\t_______|_______|_______" << endl;
    cout << "\t\t\t       |       |       " << endl;
    cout << "\t\t   2       " << b[1][0] << "   |   " << b[1][1] << "   |   " << b[1][2] << "   " << endl;
    cout << "\t\t\t_______|_______|_______" << endl;
    cout << "\t\t\t       |       |      " << endl;
    cout << "\t\t   3       " << b[2][0] << "   |   " << b[2][1] << "   |   " << b[2][2] << "   " << endl;
    cout << "\t\t\t       |       |      " << endl;
}
void name()
{
    cout << "Player 1, Enter Your Name: ";
    cin >> Player1;
    cout << "Player 2, Enter Your Name: ";
    cin >> Player2;
}
void select()
{
    cout << Player1 << ", Select Your Symbol: ";
    cin >> choice1;
    cout << endl
         << Player2 << ", Select Your Symbol: ";
    cin >> choice2;
}
int main()
{
    int i = 0, row, column;
    intro();
    rules();
    name();
    system("cls");
    intro();
    rules();
    select();
    // x = _getch();
    system("cls");
    intro();
    drawBoard();
    for (;; i++)
    {
        if ((b[0][0] == b[0][1] && b[0][0] == b[0][2] && (b[0][1] == choice1 || b[0][1] == choice2)) || (b[1][0] == b[1][1] && b[1][0] == b[1][2] && (b[1][1] == choice1 || b[1][1] == choice2)) ||
            (b[2][0] == b[2][1] && b[2][0] == b[2][2] && (b[2][1] == choice1 || b[2][1] == choice2)) || (b[0][0] == b[1][0] && b[0][0] == b[2][0] && (b[1][0] == choice1 || b[1][0] == choice2)) ||
            (b[0][1] == b[1][1] && b[0][1] == b[2][1] && (b[1][1] == choice1 || b[1][1] == choice2)) || (b[0][2] == b[1][2] && b[0][2] == b[2][2] && (b[1][2] == choice1 || b[1][2] == choice2)) ||
            (b[0][0] == b[1][1] && b[0][0] == b[2][2] && (b[1][1] == choice1 || b[1][1] == choice2)) || (b[0][2] == b[1][1] && b[0][2] == b[2][0] && (b[1][1] == choice1 || b[1][1] == choice2)))
        {
            win = 1;
            break;
        }
        if (b[0][0] != ' ' && b[0][1] != ' ' && b[0][2] != ' ' && b[1][0] != ' ' && b[1][1] != ' ' && b[1][2] != ' ' && b[2][0] != ' ' && b[2][1] != ' ' && b[2][2] != ' ')
        {
            win = 2;
            break;
        }
        if (i % 2 == 0)
        {
            cout << endl
                 << endl
                 << "\t\t\t" << Player1 << "'s Turn" << endl
                 << endl;
        }
        else
        {
            cout << endl
                 << endl
                 << "\t\t\t" << Player2 << "'s Turn" << endl
                 << endl;
        }
    turn:
        cout << "Enter Row: ";
        cin >> row;
        row--;
        cout << "Enter Column: ";
        cin >> column;
        column--;
        if (b[row][column] == choice1 || b[row][column] == choice2)
        {
            cout << endl
                 << "Slot Taken! Enter Again" << endl
                 << endl;
            goto turn;
        }
        if (row > 2 || row < 0 || column > 2 || column < 0)
        {
            cout << endl
                 << endl
                 << "Invalid Input! Enter Again" << endl
                 << endl;
            goto turn;
        }
        if (i % 2 == 0)
        {
            b[row][column] = choice1;
        }
        else
        {
            b[row][column] = choice2;
        }
        system("cls");
        intro();
        drawBoard();
    }
    if (b[0][0] == b[0][1] && b[0][0] == b[0][2] && (b[0][1] == choice1 || b[0][1] == choice2))
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i != 0)
                {
                    b[i][j] = ' ';
                }
            }
        }
    }
    else if (b[1][0] == b[1][1] && b[1][0] == b[1][2] && (b[1][1] == choice1 || b[1][1] == choice2))
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i != 1)
                {
                    b[i][j] = ' ';
                }
            }
        }
    }
    else if (b[2][0] == b[2][1] && b[2][0] == b[2][2] && (b[2][1] == choice1 || b[2][1] == choice2))
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i != 2)
                {
                    b[i][j] = ' ';
                }
            }
        }
    }
    else if (b[0][0] == b[1][0] && b[0][0] == b[2][0] && (b[1][0] == choice1 || b[1][0] == choice2))
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (j != 0)
                {
                    b[i][j] = ' ';
                }
            }
        }
    }
    else if (b[0][1] == b[1][1] && b[0][1] == b[2][1] && (b[1][1] == choice1 || b[1][1] == choice2))
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (j != 1)
                {
                    b[i][j] = ' ';
                }
            }
        }
    }
    else if (b[0][2] == b[1][2] && b[0][2] == b[2][2] && (b[1][2] == choice1 || b[1][2] == choice2))
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (j != 2)
                {
                    b[i][j] = ' ';
                }
            }
        }
    }
    else if (b[0][0] == b[1][1] && b[0][0] == b[2][2] && (b[1][1] == choice1 || b[1][1] == choice2))
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (j != i)
                {
                    b[i][j] = ' ';
                }
            }
        }
    }
    else if (b[0][2] == b[1][1] && b[0][2] == b[2][0] && (b[1][1] == choice1 || b[1][1] == choice2))
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (j != 2 - i)
                {
                    b[i][j] = ' ';
                }
            }
        }
    }
    system("cls");
    intro();
    drawBoard();
    if (win == 1)
    {
        if (i % 2 != 0)
        {
            cout << endl
                 << endl
                 << "\t\t\t" << Player1 << " has Won!" << endl
                 << endl
                 << "\t\t\tGame Over!" << endl
                 << endl;
            cout << "\t\t\tYour Trophy Score has been Increased by 1!\n\n";
        }
        else
        {
            cout << endl
                 << endl
                 << "\t\t\t" << Player2 << " has Won!" << endl
                 << endl
                 << "\t\t\tGame Over!" << endl
                 << endl;
            cout << "\t\t\tYour Trophy Score has been Increased by 1!\n\n";
        }
    }
    if (win == 2)
    {
        cout << endl
             << endl
             << "==============================================================================" << endl
             << endl;
        cout << "\t\t\tDraw" << endl
             << endl
             << "\t\t\tGame Over" << endl
             << endl;
    }
    cout << "==============================================================================" << endl
         << endl;
}