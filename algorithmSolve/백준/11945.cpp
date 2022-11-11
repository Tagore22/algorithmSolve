#include <iostream>

using namespace std;

const int MAX_NUM = 10;
string board[MAX_NUM];
int N, M;

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = board[i].size() - 1; j >= 0; --j)
            cout << board[i][j];
        cout << '\n';
    }
}

void Input()
{
    cin >> N >> M;
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