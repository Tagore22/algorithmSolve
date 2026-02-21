#include <iostream>

using namespace std;

int N;
int board[10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int idx;
        cin >> idx;
        ++board[idx];
    }
    pair<int, int> answer = make_pair(-1, -1);
    for (int i = 1; i <= 10000; ++i)
        if (board[i] > answer.second)
            answer = make_pair(i, board[i]);

    cout << answer.first << '\n';
    return 0;
}