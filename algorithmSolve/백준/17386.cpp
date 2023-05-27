#include <iostream>

using namespace std;

// 풀이.
// 언젠가 풀었던 선분 교차 판정의 하위 문제였다.
// 그 때 잘 몰라서 한참 헤맸는데 복습하는겸 다시 풀어서 좋았다.
// 다만 문제에 좌표값이 최대 100만 인걸 못봐서 한번 틀렸다.
// 최대 100만이기에 계산값이 int값을 벗어날수 있어 long long을 써야했다.
// 문제를 잘 보자.

// 자세한 설명은 주석으로 남긴다.

pair<long long, long long> pos[4];

// 왼쪽, 오른쪽, 중앙(현재 선분과 일직선)에 있는지를 확인하는 CCW함수.
// 다만 상술하였듯 좌표값이 최대 절대값 100만을 넘기에 int가 아닌 long long타입으로 해야한다.
int CCW(const pair<long long, long long>& a, pair<long long, long long>& b, pair<long long, long long>& c)
{
    long long ans = ((b.first - a.first) * (c.second - b.second)) - ((c.first - b.first) * (b.second - a.second));
    if (ans < 0)
        return -1;
    else if (ans == 0)
        return 0;
    else
        return 1;
}

void MakeAnswer()
{
    int first = CCW(pos[0], pos[1], pos[2]) * CCW(pos[0], pos[1], pos[3]);
    int second = CCW(pos[2], pos[3], pos[0]) * CCW(pos[2], pos[3], pos[1]);

    // 두 선분이 일직선에 존재할때.
    if (first == 0 && second == 0)
    {
        if (pos[0] > pos[1])
            swap(pos[0], pos[1]);
        if (pos[2] > pos[3])
            swap(pos[2], pos[3]);
        // 두 선분이 일직선에 존재하나 포개져있지는 않을때.
        if (pos[1] < pos[2] || pos[3] < pos[0])
            cout << 0 << '\n';
        // 포개져있을때.
        else
            cout << 1 << '\n';
    }
    else
    {
        // 두 값 first와 second가 둘중 하나라도 1이면 교차하지 않는다.
        // 1 이라는 것은 어떤 선분에서 다른 선분의 두 점이 한쪽에 몰려있다는 것을 뜻하기 때문이다.
        if (first <= 0 && second <= 0)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 4; ++i)
        cin >> pos[i].first >> pos[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}