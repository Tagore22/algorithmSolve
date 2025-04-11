#include <iostream>

using namespace std;

int board[1000000];
int N, K;

bool IsCanMakeLevel(long long mid)
{
    long long ans = 0;
    for (int i = 0; i < N; ++i)
    {
        if (ans > K)
            return false;
        if (mid > board[i])
            ans += mid - board[i];
    }
    return ans <= K;
}

void MakeAnswer()
{
    long long from = 0, to = 2000000001;
    while (from <= to)
    {
        long long mid = (from + to) / 2;
        if (IsCanMakeLevel(mid))
            from = mid + 1;
        else
            to = mid - 1;
    }
    cout << from - 1 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}