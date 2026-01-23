#include <iostream>

using namespace std;

// 풀이.
// 문제를 한참 잘못 이해했다. 처음에는 연달아서 10초내에 같은 팀이
// 연달아 득점한 경우만 50점이 추가되는 줄 알았는데 전혀 아니었다.
// 사실 연달아는 상관없고 10초 이내에 같은 선수가 득점한다면 50점이
// 추가되는 간단한 로직이었다. 따라서 각 팀의 점수와 각 선수의 이전
// 득점 시간을 유지하기만 하면 된다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    int point[2] = { 0, 0 }, prev[8] = { -11, -11, -11, -11, -11, -11, -11, -11 };
    for (int i = 0; i < N; ++i)
    {
        int t, a, b;
        cin >> t >> a >> b;
        --a;
        --b;
        int cur = a / 4;
        point[cur] += 100;
        if (t - prev[a] <= 10)
            point[cur] += 50;
        prev[a] = t;
    }
    cout << point[0] << ' ' << point[1] << '\n';
    return 0;
}