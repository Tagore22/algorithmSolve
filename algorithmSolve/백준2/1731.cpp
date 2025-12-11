#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    int board[50];
    for (int i = 0; i < N; ++i)
        cin >> board[i];
    if (board[2] - board[1] == board[1] - board[0])
        cout << board[N - 1] + (board[2] - board[1]) << '\n';
    else
        cout << board[N - 1] * (board[2] / board[1]) << '\n';
    return 0;
}