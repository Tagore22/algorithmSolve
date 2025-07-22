#include <iostream>
#include <algorithm>

using namespace std;

int N;
int board[20000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];

    sort(board, board + N);
    int idx = N % 2 == 0 ? N / 2 - 1 : N / 2;
    cout << board[idx] << '\n';
    return 0;
}