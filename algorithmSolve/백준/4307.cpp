#include <iostream>
#include <cmath>

using namespace std;

// 풀이.
// 개미가 모두 떨어지는 최소 시간과 최대 시간을 구하는 문제다.
// 최소시간은 그대로 끝쪽으로 모두 떨어지는 것인데 최대 시간은 생각이 나지 않았다.
// 문제의 종류를 보니 애드혹이었고, 생각하는 것을 멈추었다.

// 최대 시간은 양 끝쪽의 개미가 서로 반대쪽으로 떨어지는 시간의 최대값이었다.

int T, N, L, cur;

void MakeAnswer()
{
    int from, to, mid;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> N >> L;
        from = N;
        to = 0;
        mid = 0;
        int pivot = N / 2;
        for (int i = 0; i < L; ++i)
        {
            cin >> cur;
            from = min(from, cur);
            to = max(to, cur);
            mid = abs(mid - pivot) > abs(cur - pivot) ? cur : mid;
        }
        mid = mid - 0 > N - mid ? N - mid : mid;
        cout << mid << ' ';
        int answer = N - from < to ? to : N - from;
        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}