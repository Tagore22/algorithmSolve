#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> board;
string str1;
string str2;
string answer = "";

void Calcul()
{
    board.assign(str2.size() + 1, vector<int>(str1.size() + 1, 0));
    for (int i = 1; i < str2.size() + 1; ++i)
        for (int j = 1; j < str1.size() + 1; ++j)
        {
            if (str2[i - 1] == str1[j - 1])
                board[i][j] = board[i - 1][j - 1] + 1;
            else
                board[i][j] = max(board[i - 1][j], board[i][j - 1]);
        }
    int first = str2.size();
    int second = str1.size();

    while (board[first][second])
    {
        if (board[first][second] == board[first - 1][second])
            --first;
        else if (board[first][second] == board[first][second - 1])
            --second;
        else
        {
            answer += str2[first - 1];
            --first;
            --second;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str1 >> str2;
    Calcul();
    cout << answer.size() << '\n';
    if (answer.size() != 0)
    {
        for (int i = answer.size() - 1; i >= 0; --i)
            cout << answer[i];
    }
    cout << '\n';
    return 0;
}