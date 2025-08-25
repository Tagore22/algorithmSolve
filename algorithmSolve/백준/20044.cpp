#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    int idx = N * 2;

    int board[10000];
    for (int i = 0; i < idx; ++i)
        cin >> board[i];
    sort(board, board + idx);

    int answer = 200001;
    for (int i = 0; i < N; ++i)
        answer = min(answer, board[i] + board[idx - i - 1]);
    cout << answer << '\n';
    return 0;
}