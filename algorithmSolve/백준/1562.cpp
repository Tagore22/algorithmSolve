#include <iostream>
#include <cstring>

//앞자리와 1차이나는 2개의 수를 추가해가며 만들수 있는 N자리 수의 값을 구하는 문제이다.
//완전탐색으로 풀기엔 대략 9 * 2의 99제곱까지도 늘수 있기에 DP를 사용해야하는데
//처음엔 길이와 현 위치의 수만 캐싱했었는데, 그러면 더 앞자리의 영향을 무시한채 캐싱이 되어
//예제조차 통과하지 못했다. 그래서 비트마스크를 사용해야 했으며 최대 0~9까지 10개만 비트마스킹 하면 되니,
//문제가 없었다.
//P.S 어떠한 수는 앞자리수가 자신보다 1이 크거나 작아야함으로 비트가 같다는건 반드시 여태까지 만든 수가 동일할수밖에 없다.
//예를 들어 비트마스크를 사용하지 않는다면 똑같이 3번째 자리에 7을 넣는다면
//5 6 7 과 9 8 7 을 구분할수가 없다. 하지만 비트마스크를 사용한다면 3개의 캐싱값으로 무조건 구분이 가능하다.

using namespace std;

const int DIVNUM = 1000000000;
long long cashe[100][10][1 << 10];
int N;

int Cal(int idx, int now, int bit) //각각 위치값, 이전값, 비트마스크
{
    if (idx == N - 1)
        return bit == (1 << 10) - 1 ? 1 : 0;

    long long& ans = cashe[idx][now][bit];
    if (ans != -1)
        return ans;
    ans = 0;

    int next = now + 1;
    if (next < 10)
        ans += Cal(idx + 1, next, bit | (1 << next));

    next = now - 1;
    if (next > -1)
        ans += Cal(idx + 1, next, bit | (1 << next));

    return ans %= DIVNUM;
}

void MakeAnswer()
{
    if (N < 10)
    {
        cout << 0 << '\n';
        return;
    }
    long long answer = 0;
    for (int i = 1; i < 10; ++i) //0으로 시작되는 수는 존재할수 없다. 그러므로 시작점은 1.
    {
        answer += Cal(0, i, 1 << i);
        answer %= DIVNUM;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(cashe, -1, sizeof(cashe));

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}