#include <iostream>
#include <vector>
#include <string>
using namespace std;

int countNumOfWays(vector<string>& board, int rows, vector<bool>& columns, vector<bool>& d1, vector<bool>& d2)
{
    if (rows == 8)
        return 1;
    int ways = 0;
    for (int col = 0; col < 8; col++)
    {
        if (board[rows][col] == '*' || columns[col] || d1[rows - col + 7] || d2[rows + col])
            continue;
        columns[col] = true;
        d1[rows - col + 7] = true;
        d2[rows + col] = true;
        ways += countNumOfWays(board, rows + 1, columns, d1, d2);
        columns[col] = false;
        d1[rows - col + 7] = false;
        d2[rows + col] = false;
    }
    return ways;
}

int main()
{
    vector<string> board(8);
    for (int i = 0; i < 8; i++)
        cin >> board[i];
    vector<bool> columns(8, false);
    vector<bool> d1(15, false);
    vector<bool> d2(15, false);
    cout << countNumOfWays(board, 0, columns, d1, d2) << endl;
    return 0;
}
