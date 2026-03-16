#include <iostream>

using namespace std;

// 풀이.
// 22862번의 첫번째 풀이. 투포인터의 범위 기반을 사용하여 해결하였다.
// 마지막에 최종적으로 한번의 계산을 더해야하는데 이는 3, 2, 2, 2, 2
// 같은 경우를 계산하기 위함이다.

int N, K;
int board[1000000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> board[i];

    int from = 0, to = 0, answer = 0, odd = 0;
    while (from <= to && to < N)
    {
        if (board[to] % 2 != 0)
        {
            ++odd;
            if (odd > K)
            {
                answer = max(answer, to - from - K);
                while (board[from] % 2 == 0)
                {
                    ++from;
                }
                ++from;
                --odd;
            }
        }
        ++to;
    }

    int minus = 0;
    for (int i = from; i < N; ++i)
        if (board[i] % 2 != 0)
            ++minus;
    answer = max(answer, to - from - minus);
    cout << answer << '\n';
    return 0;
}