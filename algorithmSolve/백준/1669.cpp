#include <iostream>

using namespace std;

// 풀이.
// 골 4 ~ 5에는 이런 문제가 많았다. 흔히 알려진 알고리즘 방식이 아닌 수학적 접근이 필요한 문제들말이다.
// 솔직히 말하자면 아직도 뭔소린지를 모르겠다. 이건 뭐 주제가 확연한것도 아니고 찾기가 애매모호하다.
// 후...

int x, y;

void MakeAnswer()
{
    if (x == y)
    {
        cout << 0 << '\n';
    }
    else
    {
        long long cost = 0;
        int dist = y - x;

        while (cost * cost < dist)
            ++cost;

        if (cost * cost - cost < dist)
            cout << cost * 2 - 1 << '\n';
        else
            cout << cost * 2 - 2 << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> x >> y;
    MakeAnswer();
    return 0;
}