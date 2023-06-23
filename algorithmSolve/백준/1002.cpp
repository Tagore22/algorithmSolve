#include <iostream>

using namespace std;

// 풀이.
// 거의 1년전에 풀었던 문제인데 주인장이 조건을 이상하게 바꾸어서 정답율이 확떨어진 문제이다.
// 거진 절반으로 떨어졌다. 다른점은 각 사거리인 r1, r2이 0일때가 생겼다는 것이다.
// 그 때만 따로 조건문을 추가해주면 되었다. 막상 예전의 main문에 몰아쳐서 코딩하는 스타일을 보니
// 엄청 답답해보인다. 앞으로도 좀더 나아가야지.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int testNum;
    cin >> testNum;
    for (int i = 0; i < testNum; ++i)
    {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        int dis = ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        int case1 = (r1 - r2) * (r1 - r2);
        int case2 = (r1 + r2) * (r1 + r2);

        if (r1 == 0 && r2 == 0)
            cout << 1 << '\n';
        else if (dis == 0)
        {
            if (r1 == r2)
                cout << -1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (dis == case1 || dis == case2)
            cout << 1 << '\n';
        else if (dis > case1 && dis < case2)
            cout << 2 << '\n';
        else
            cout << 0 << '\n';
    }
    return 0;
}