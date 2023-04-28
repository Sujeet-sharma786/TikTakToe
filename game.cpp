#include <iostream>
using namespace std;
class tikTakToe
{
public:
    int arr[3][3] = {{0, 0, 0},
                     {0, 0, 0},
                     {0, 0, 0}};
    string player1, player2;

    tikTakToe(string player1, string player2)
    {
        this->player1 = player1;
        this->player2 = player2;
        cout << "player-1 :- " << player1 << endl;
        cout << "player-2 :- " << player2 << endl;
    }
    void Game()
    {

        while (true)
        {
            int row, column, response;
            string replay;
        start1:
            cout << "Player - 1 :-\n";
            cout << "Enter row from 1-3 :-\n";
            cin >> row;
            if (!(row >= 1 && row <= 3))
            {
                cout << "Enter valid row\n";
                goto start1;
            }
            cout << "Enter column from 1-3 :-\n";
            cin >> column;
            if (!(column >= 1 && column <= 3))
            {
                cout << "Enter valid column\n";
                goto start1;
            }
        resp:
            cout << "Enter 1 as response :-\n";
            cin >> response;
            if (response != 1)
            {
                goto resp;
            }
            // set the resp of p1 in arr

            if (arr[row - 1][column - 1] == 0)
            {
                arr[row - 1][column - 1] = response;
            }
            else
            {
                cout << "Already filled, choose another box\n";
                goto start1;
            }
            if (((arr[0][0] && arr[0][1] && arr[0][2]) == 1) || ((arr[1][0] && arr[1][1] && arr[1][2]) == 1) ||
                ((arr[2][0] && arr[2][1] && arr[2][2]) == 1) || ((arr[0][0] && arr[1][0] && arr[2][0]) == 1) ||
                ((arr[0][1] && arr[1][1] && arr[2][1]) == 1) || ((arr[0][2] && arr[1][2] && arr[2][2]) == 1) ||
                ((arr[0][0] && arr[1][1] && arr[2][2]) == 1) || ((arr[0][2] && arr[1][1] && arr[2][0]) == 1))
            {
                cout << "congrates " << player1 << " you won !" << endl;
                cout << "replay ? Type Yes/No" << endl;
                cin >> replay;
                if (replay == "Yes")
                {
                    goto start1;
                }
                else
                {
                    return;
                }
            }
        start2:
            cout << "Player - 2 :-\n";
            cout << "Enter row from 1-3 :-\n";
            cin >> row;
            if (!(row >= 1 && row <= 3))
            {
                cout << "Enter valid row\n";
                goto start2;
            }
            cout << "Enter column from 1-3:-\n";
            cin >> column;
            if (!(column >= 1 && column <= 3))
            {
                cout << "Enter valid column\n";
                goto start2;
            }
        resp2:
            cout << "Enter 2 as response :-\n";
            cin >> response;
            if (response != 2)
            {
                goto resp2;
            }
            // set the resp of p2 in arr
            if (arr[row - 1][column - 1] == 1 || arr[row - 1][column - 1] == 2)
            {
                cout << "Already filled, choose another box\n";
                goto start2;
            }
            else
            {
                arr[row - 1][column - 1] = response;
            }

            if (((arr[0][0] && arr[0][1] && arr[0][2]) == 2) || ((arr[1][0] && arr[1][1] && arr[1][2]) == 2) ||
                ((arr[2][0] && arr[2][1] && arr[2][2]) == 2) || ((arr[0][0] && arr[1][0] && arr[2][0]) == 2) ||
                ((arr[0][1] && arr[1][1] && arr[2][1]) == 2) || ((arr[0][2] && arr[1][2] && arr[2][2]) == 2) ||
                ((arr[0][0] && arr[1][1] && arr[2][2]) == 2) || ((arr[0][2] && arr[1][1] && arr[2][0]) == 2))
            {
                cout << "congrates " << player2 << " you won !" << endl;
                cout << "replay ? Type Yes/No" << endl;
                cin >> replay;
                if (replay == "Yes")
                {
                    goto start1;
                }
                else
                {
                    return;
                }
            }
            if ((arr[0][0] && arr[0][1] && arr[0][2] && arr[1][0] && arr[1][1] && arr[1][2] &&
                 arr[2][0] && arr[2][1] && arr[2][2]) != 0)
            {
                cout << "Match Draw" << endl;
                return;
            }
        }
    }
};

int main()
{
    string player1, player2;
    cout << "Enter player1 name:-\n";
    cin >> player1;
    cout << "Enter player2 name:-\n";
    cin >> player2;
    tikTakToe game1(player1, player2);

    game1.Game();
}