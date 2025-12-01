#include <iostream>
#include <algorithm>

using namespace std;

int board[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, L, K;
    cin >> N >> L >> K;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
    sort(board, board + N);
    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        if (board[i] > L)
            break;
        ++answer;
        L += K;
    }
    cout << answer << '\n';
    return 0;
}