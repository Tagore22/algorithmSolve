#include <iostream>

using namespace std;

void MakeAnswer()
{
    int board[1000];
    int N, answer;
    while (true)
    {
        cin >> N;
        if (N == 0)
            break;
        for (int i = 0; i < N; ++i)
            cin >> board[i];
        int cur = board[0] + board[1] + board[2];
        answer = cur;
        for (int i = 3; i < N; ++i)
        {
            cur -= board[i - 3];
            cur += board[i];
            answer = max(answer, cur);
        }
        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}