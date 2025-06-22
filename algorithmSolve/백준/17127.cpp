#include <iostream>

using namespace std;

const int MAX = 10;
int N, board[MAX], answer = 0;

void BackTrack(int idx, int num, int sum)
{
    if (num == 1)
    {
        int mul = 1;
        for (int i = idx; i < N; ++i)
            mul *= board[i];
        answer = max(answer, sum + mul);
        return;
    }

    int mul = 1;
    for (int i = idx; i <= N - num; ++i)
    {
        mul *= board[i];
        BackTrack(i + 1, num - 1, sum + mul);
    }
}

void Solve()
{
    BackTrack(0, 4, 0);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    Solve();
    return 0;
}