#include <iostream>

using namespace std;

int W, N;
int board[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> W >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];

    int from = 0, cur = 0, answer = 0;
    for (int i = 0; i < N; ++i)
    {
        if (cur + board[i] > W)
            break;
        cur += board[i];
        ++answer;
        if (i - from >= 3)
        {
            cur -= board[from];
            ++from;
        }
    }
    cout << answer << '\n';
    return 0;
}