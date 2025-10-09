#include <iostream>

using namespace std;

// 풀이.
// 너무 어렵게 접근했었다. 팀을 추가할 때 조별 경기부터 추가하는 방식으로 로직을 짰더니
// 말도 안되게 복잡해졌다. 문제를 다시 읽고 생각해보니 조별 경기 이후 토너먼트부터 팀을
// 추가하는 것이었다. 아래 풀이의 로직은 다음과 같다.

// 1. 조별 경기의 경기수를 구한다. 각 조마다 속해 있는 팀의 수 * (팀의 수 - 1) / 2로 알 수 있다.
// 2. 추가해야하는 팀의 수를 구한다. G * T + D로 현재 토너먼트에 진출하는 팀의 수를 알 수 있는데
// 이것이 2의 제곱수인지 확인하고 만약 그렇지 않다면 더 크면서 가장 작은 2의 제곱수를 구하여
// 추가해야하는 팀의 수를 구한다.
// 3. 총 경기수를 구한다. 토너먼트에 진출한 팀의 수를 2로 나누어가며 그 수들을 모두 더하고
// 1번에서 구한 조별 경기수를 추가하여 최종 경기수를 구한다.

// 또한, 입력값이 최대 2의 16제곱이기에 long long 타입을 사용하여야만 한다.

// 자세한 설명은 주석으로 남긴다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long G, A, T, D;
    while (true)
    {
        cin >> G >> A >> T >> D;

        if (A == -1)
            break;

        // 조별 경기 경기수
        long long match = A * (A - 1) / 2;
        match *= G;

        // 토너먼트 진출 팀 확인
        long long team = G * T + D;
        long long check = team;
        while (check > 1 && check % 2 == 0)
        {
            check /= 2;
        }
        long long plus = 0;
        if (check != 1)
        {
            long long newteam = 1;
            while (newteam <= team)
            {
                newteam *= 2;
            }
            plus = newteam - team;
            team = newteam;
        }

        // 토너먼트 경기수
        long long answer = 0;
        while (team > 0)
        {
            answer += team / 2;
            team /= 2;
        }
        answer += match;
        cout << G << '*' << T << '/' << A << '+' << D << '=' << answer << '+' << plus << '\n';
    }
    return 0;
}