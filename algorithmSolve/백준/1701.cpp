#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string str;
vector<int> board;

//단순한 KMP문제. 다만 시작점이 0에서 최대 str.size()-2까지 점차 늘어남에 주의할것.

void KMP(const string& str)
{
    int begin = 1;
    int match = 0;
    int Ssize = str.size();
    board.clear();
    board.resize(Ssize, 0);
    while (begin + match < Ssize)
    {
        if (str[begin + match] == str[match])
        {
            ++match;
            board[begin + match - 1] = match;
        }
        else
        {
            if (match == 0)
            {
                ++begin;
            }
            else
            {
                begin += match - board[match - 1];
                match = board[match - 1];
            }
        }
    }
}

void MakeAnswer()
{
    int answer = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        string sub = str.substr(i, str.size());
        KMP(sub);
        sort(board.begin(), board.end(), greater<int>());
        answer = max(answer, board[0]);
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}