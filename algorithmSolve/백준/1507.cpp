#include <iostream>
#include <cstring>

using namespace std;

const int MAXNUM = 20;
int board[MAXNUM][MAXNUM];
bool check[MAXNUM][MAXNUM];
int N;
bool CanCal = true;

void Floyd()
{
    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
            {
                if (i == j || j == k || k == i)
                {
                    continue;
                }
                else if (board[i][j] > board[i][k] + board[k][j])
                {
                    CanCal = false;
                    return;
                }
                else if (board[i][j] == board[i][k] + board[k][j])
                {
                    check[i][j] = false;
                }
            }
}

void MakeAnswer()
{
    Floyd();
    int answer = -1;
    if (CanCal)
    {
        answer = 0;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (check[i][j])
                    answer += board[i][j];
        answer /= 2;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(check, 1, sizeof(check));

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}