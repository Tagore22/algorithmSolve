#include <iostream>
#include <vector>

using namespace std;

vector<vector<vector<int>>> board;
string str1, str2, str3;

void MakeAnswer()
{
    board.resize(str3.size() + 1, vector<vector<int>>(str2.size() + 1, vector<int>(str1.size() + 1, 0)));
    for (int i = 1; i < str3.size() + 1; ++i)
        for (int j = 1; j < str2.size() + 1; ++j)
            for (int k = 1; k < str1.size() + 1; ++k)
            {
                if (str3[i - 1] == str2[j - 1] && str2[j - 1] == str1[k - 1])
                    board[i][j][k] = board[i - 1][j - 1][k - 1] + 1;
                else
                    board[i][j][k] = max(board[i - 1][j][k], max(board[i][j - 1][k], board[i][j][k - 1]));
            }
    cout << board[str3.size()][str2.size()][str1.size()] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str1 >> str2 >> str3;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}