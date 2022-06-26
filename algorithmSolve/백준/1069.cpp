#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int x, y, d, t;

void Calcul()
{
    double dist = sqrt(pow(x, 2) + pow(y, 2));
    double ans = dist; //최대 거리는 그냥 걷기.
    int jump = dist / d; //최대 몇번 점프 할수 있는가
    dist -= jump * d;    //점프 이후 남은 거리

    if (jump == 0) // 점프할수 없을때 방법은
    {
        ans = min(ans, d - dist + t); //첫번째 비교대상은 점프할수 있는 거리만큼 뒤로 빠진후 점프로 도착.
        ans = min(ans, t * 2.0); //두번째 비대상은 꺾어서 두번의 점프로 도착.
    }
    else //점프 할수 있을때 방법은
    {
        ans = min(ans, jump * t + dist); //수번의 점프 이후 남은 거리 걷기
        ans = min(ans, static_cast<double>(jump + 1) * t); // 수번 + 1번의 꺽은 점프로 도착.
    }

    cout << fixed;
    cout.precision(9);
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> x >> y >> d >> t;
    Calcul();
    return 0;
}