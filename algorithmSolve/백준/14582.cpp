#include <iostream>

using namespace std;

// 원래는 골4를 풀어야하지만 도무지 생각이 나질 않았다. 2번이나 이런적은 처음이라 짜증이 나지만
// 이런날도 있겠지. 이 문제의 함정은 초나 말이 끝났을때가 아닌 진행 도중이라도 울림이 이기고 있는
// 경우를 파악해야 한다는 것이다. 후술하겠으나 총합을 더하는 순서가 틀렸었다.

// 자세한 설명은 주석으로 남긴다.

int j[9], s[9];

int main()
{
    for (int i = 0; i < 9; ++i)
        cin >> j[i];
    for (int i = 0; i < 9; ++i)
        cin >> s[i];
    int sum_j = 0, sum_s = 0;
    for (int i = 0; i < 9; ++i)
    {
        sum_j += j[i];
        // 원래는 이곳에서 스타트링크의 총합을 구했었다. 하지만 상술한대로 초가 진행중일때
        // 울림이 이기고 있는 경우도 포함시켜야 하기에 각 초와 말이 아닌 초와 이전 말의 값을 비교해야한다.
        //sum_s += s[i];
        if (sum_j > sum_s)
        {
            cout << "Yes" << '\n';
            return 0;
        }
        sum_s += s[i];
    }
    cout << "No" << '\n';
    return 0;
}