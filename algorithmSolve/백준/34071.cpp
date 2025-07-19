#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    int board[100];
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];

    int first = board[0];
    sort(board, board + N);
    if (first == board[0])
        cout << "ez" << '\n';
    else if (first == board[N - 1])
        cout << "hard" << '\n';
    else
        cout << '?' << '\n';

    return 0;
}