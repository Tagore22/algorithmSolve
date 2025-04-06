#include <iostream>
#include <algorithm>

using namespace std;

int board[10000];
int N, L;

void MakeAnswer()
{
    sort(board, board + N);
    for (int i = 0; i < N; ++i)
    {
        if (board[i] > L)
            break;
        ++L;
    }
    cout << L << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> L;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}