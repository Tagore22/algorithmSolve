#include <iostream>

using namespace std;

int N, M;
pair<int, int> board[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        board[i] = { -1, -1 };
    for (int i = 0; i < M; ++i)
    {
        int a, c;
        char b;
        cin >> a >> b >> c;
        if (b == 'P')
            board[a].first = c;
        else
            board[a].second = c;
    }
    pair<int, int> answer = { 0, 0 };
    for (int i = 1; i <= N; ++i)
    {
        if (board[i].first == 0 || board[i].second == 1)
        {
            continue;
        }
        else if (board[i].first == -1 || board[i].second == -1)
        {
            ++answer.second;
        }
        else
        {
            ++answer.first;
            ++answer.second;
        }
    }
    cout << answer.first << ' ' << answer.second << '\n';
    return 0;
}