#include <iostream>

using namespace std;

// 풀이.
// 0 ~ N까지의 길이중 이분 탐색을 이용하여 가장 최소값을 찾는 문제다.
// 사실 이 다음 풀이를 보면 알 수 있듯이 이분 탐색을 사용할 필요도 없으나
// 로직만 따지자면 다음과 같다

// 1. 0 ~ N 까지의 값들중 이분 탐색을 순회하며 빛의 세기를 구하여 빛의 세기 * 2가
// 각 가로등 사이의 모든 거리르 비추는 최소값을 구하는 것.

// 다만 0 ~ 첫번째 가로등까지의 거리와 맨 마지막 가로등 ~ N까지의 거리는 둘이 아닌
// 하나의 가로등으로 비추어야했기에 이 부분을 조금 어렵게 생각했고, 최소 거리를
// 이 두가지중 더 큰값으로 하였다.

int N, M, from, cur, gap = 0;

void Solve()
{
    int to = N + 1;
    while (from <= to)
    {
        int mid = (from + to) / 2;
        if (mid * 2 >= gap)
            to = mid - 1;
        else
            from = mid + 1;
    }
    cout << to + 1 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    int prev = cur = 0;
    for (int i = 0; i < M; ++i)
    {
        cin >> cur;
        if (i == 0)
            from = cur;
        if (i == M - 1)
            from = max(from, N - cur);

        gap = max(gap, cur - prev);
        prev = cur;

    }
    gap = max(gap, N - prev);
}

int main()
{
    Input();
    Solve();
    return 0;
}