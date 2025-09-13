#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int board[100];
    for (int i = 0; i < N; ++i)
        cin >> board[i];
    cout << board[1] - board[0] + board[N - 1] << '\n';
    return 0;
}