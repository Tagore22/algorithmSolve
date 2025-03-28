#include <iostream>

using namespace std;

int board[1000000];
int N, K;

void MakeAnswer()
{
    int from = 0, to = 0, num = 0, answer = 987654321;

    while (to < N)
    {
        if (board[to] == 1)
        {
            ++num;
            if (num == K)
            {
                answer = min(answer, to - from + 1);
                --num;
                ++from;
                while (board[from] != 1)
                    ++from;
            }
            ++to;
        }
        else
        {
            from = num == 0 ? from + 1 : from;
            ++to;
        }
    }
    answer = answer == 987654321 ? -1 : answer;
    cout << answer << '\n';
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