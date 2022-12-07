#include <iostream>
#include <algorithm>

using namespace std;

int board[1000];
int N, L;

void MakeAnswer()
{
    sort(board, board + N);
    int cur = board[0] - 1 + L;
    int answer = 1;
    for (int i = 1; i < N; ++i)
        if (board[i] > cur)
        {
            cur = board[i] - 1 + L;
            ++answer;
        }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

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