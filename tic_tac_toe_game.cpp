#include <iostream>

using namespace std;

bool checkBoard(char mark);
void markBoard_1(char a);
void markBoard_2(char a);
void showBoard();
void checkWin(char mark);

char board[3][3] = {{'a', 'b', 'c'},
                    {'d', 'e', 'f'},
                    {'g', 'h', 'i'}};

int w, count_p1 = 0, count_p2 = 0;

int main()
{

    char ch1, ch2;

    showBoard();

    while (1)
    {
        //w = 0;
        cout << "Enter Player one location (X) : ";
        cin >> ch1;
        ++count_p1;

        while (ch1 == ch2)
        {
            cout << "Location is already reserved" << endl;
            cout << "Enter the Player one location (X) : ";
            cin >> ch1;
        }

        if (checkBoard(ch1) == true)
        {
            markBoard_1(ch1);
            checkWin('X');
            system("cls");
            showBoard();
            if (w == 1)
            {
                cout << "Player one Wins Congratulations!" << endl;
                exit(0);
            }
            else if (w == 0 && count_p1 == 5)
            {
                cout << "Game draw !" << endl;
                exit(0);
            }
        }

        else
        {
            while (checkBoard(ch1) != true)
            {

                cout << "Invalid location!" << endl;
                cout << "Enter Player one location (X) : ";
                cin >> ch1;
            }

            markBoard_1(ch1);
            checkWin('X');

            system("cls");
            showBoard();
            if (w == 1)
            {
                cout << "Player one Wins Congratulations!" << endl;
                exit(0);
            }
            else if (w == 0 && count_p1 == 5)
            {
                cout << "Game draw !" << endl;
                exit(0);
            }
        }

        cout << "Enter Player two location (O) : ";
        cin >> ch2;
        ++count_p2;

        while (ch2 == ch1)
        {
            cout << "Location is already reserved" << endl;
            cout << "Enter the Player two location (O) : ";
            cin >> ch2;
        }

        if (checkBoard(ch2))
        {
            markBoard_2(ch2);
            checkWin('O');
            system("cls");
            showBoard();
            if (w == 1)
            {
                cout << "Player two Wins Congratulations!" << endl;
                exit(0);
            }
            else if (w == 0 && count_p2 == 4)
            {
                cout << "Game draw !" << endl;
                exit(0);
            }
        }

        else
        {
            while (checkBoard(ch2) != true)
            {

                cout << "Invalid location!" << endl;
                cout << "Enter Player two location (O) : ";
                cin >> ch2;
            }

            markBoard_2(ch2);
            checkWin('O');
            system("cls");
            showBoard();
            if (w == 1)
            {
                cout << "Player two Wins Congratulations!" << endl;
                exit(0);
            }
            else if (w == 0 && count_p2 == 4)
            {
                cout << "Game draw !" << endl;
                exit(0);
            }
        }

        //label:cout <<"Player ";
    }
    return 0;
}

bool checkBoard(char mark)
{
    if ((mark == 'a') || (mark == 'b') || (mark == 'c') || (mark == 'd') || (mark == 'e') || (mark == 'f') || (mark == 'g') || (mark == 'h') || (mark == 'i'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void markBoard_1(char a)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == a)
            {
                board[i][j] = 'X';
            }
        }
    }
}

void markBoard_2(char a)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == a)
            {
                board[i][j] = 'O';
            }
        }
    }
}

void showBoard()
{
    cout << "\t\t\t\t\t\t-------Tic Tac Toe Game-------\n\n\n";
    cout << "\t\t\t\t\t\t| " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " |" << endl;
    //cout << "\t\t\t\t\t\t_____________"<<endl;
    cout << "\t\t\t\t\t\t| " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " |" << endl;
    //cout << "\t\t\t\t\t\t_____________"<<endl;
    cout << "\t\t\t\t\t\t| " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " |" << endl;
}

void checkWin(char mark)
{
    if (board[0][0] == mark && board[0][1] == mark && board[0][2] == mark)
    {
        w = 1;
    }
    else if (board[1][0] == mark && board[1][1] == mark && board[1][2] == mark)
    {
        w = 1;
    }
    else if (board[2][0] == mark && board[2][1] == mark && board[2][2] == mark)
    {
        w = 1;
    }
    else if (board[0][0] == mark && board[1][0] == mark && board[2][0] == mark)
    {
        w = 1;
    }
    else if (board[0][1] == mark && board[1][1] == mark && board[2][1] == mark)
    {
        w = 1;
    }
    else if (board[0][2] == mark && board[1][2] == mark && board[2][2] == mark)
    {
        w = 1;
    }
    else if (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark)
    {
        w = 1;
    }
    else if (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)
    {
        w = 1;
    }
    else
    {
        w = 0;
    }
}
