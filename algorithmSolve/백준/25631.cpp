#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    int board[1000];
    for (int i = 0; i < N; ++i)
        cin >> board[i];

    sort(board, board + N);
    int num = -1, cur = 0, answer = 0;
    for (int i = 0; i < N; ++i)
    {
        if (num == board[i])
        {
            ++cur;
        }
        else
        {
            answer = max(answer, cur);
            num = board[i];
            cur = 1;
        }
    }
    answer = max(answer, cur);
    cout << answer << '\n';
    return 0;
}