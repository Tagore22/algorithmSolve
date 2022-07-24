#include <iostream>
#include <algorithm>

using namespace std;

string board[10];
int N;
int answer = 0;
int alpha[26];

void TransStr()
{
    for (int i = 0; i < N; ++i)
    {
        int now = 1;
        for (int j = board[i].size() - 1; j >= 0; --j)
        {
            alpha[board[i][j] - 'A'] += now;
            now *= 10;
        }
    }
}

void TransInt()
{
    sort(alpha, alpha + 26);
    int num = 9;
    for (int i = 25; i >= 0; --i)
    {
        if (alpha[i] == 0)
            break;
        answer += alpha[i] * num;
        --num;
    }
    cout << answer << '\n';
}

void MakeAnswer()
{
    TransStr();
    TransInt();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;
        board[i] = str;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}