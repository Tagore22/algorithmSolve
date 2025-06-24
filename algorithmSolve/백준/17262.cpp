#include <iostream>

using namespace std;

// 풀이.
// 범위의 문제다. 가장 빨리 퇴교하는 친구가 퇴교할 때 만나서 가장 늦게 등교하는 친구가 등교할 때
// 만나면 된다. 처음엔 입력받은 값들을 정렬하여 구현하였으나, 굳이 그럴 필요 없이 입력 단계에서
// 가장 빠른 퇴교 시간과 가장 느린 등교 시간을 구하면 된다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, s = 0, e = 100001;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int from, to;
        cin >> from >> to;
        s = max(s, from);
        e = min(e, to);
    }
    int answer = s - e <= 0 ? 0 : s - e;
    cout << answer << '\n';
    return 0;
}