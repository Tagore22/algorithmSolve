#include <iostream>
#include <vector>

using namespace std;

vector<string> board;

void MakeAnswer()
{
    for (int i = 0; i < board.size(); ++i)
    {
        int answer = 1;
        for (int j = 0; j < board[i].size(); ++j)
        {
            if (board[i][j] == '1')
                answer += 2;
            else if (board[i][j] == '0')
                answer += 4;
            else
                answer += 3;
            answer += 1;
        }
        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    while (true)
    {
        string str;
        cin >> str;
        if (str == "0")
            break;
        board.push_back(str);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}