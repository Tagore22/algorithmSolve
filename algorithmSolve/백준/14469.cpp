#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> board[100];
int N;

void Solve()
{
    sort(board, board + N);
    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        answer = max(answer, board[i].first);
        answer += board[i].second;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i].first >> board[i].second;
}

int main()
{
    Input();
    Solve();
    return 0;
}