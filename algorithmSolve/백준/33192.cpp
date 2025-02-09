#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 별거 아닌 문제인데 복잡하게 꼬아놨다. 뭐 그건 상관없었으나 이상하게 12퍼에서
// 계속 틀렸다. 로직이나 int 범위를 벗어난다거나 이런건 전혀 문제가 없어보였다.
// 결과적으로는 K, H가 모두 0일때가 문제였다. while문은 answer가 0보다 클때만
// 호출되기 때문에 answer가 0이라면 출력자체가 되지 않았었다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, X, K, H;
    cin >> N;
    for (int iter = 0; iter < N; ++iter)
    {
        cin >> X >> K >> H;
        int answer = H * 2 * X;
        K -= H;
        int over = max(0, K - 140);
        answer += over * 1.5 * X;
        K -= over;
        answer += K * X;

        string ans = "";
        int idx = 0;
        while (answer > 0)
        {
            if (idx != 0 && idx % 3 == 0)
                ans += ',';
            ans += (answer % 10) + '0';
            answer /= 10;
            ++idx;
        }
        reverse(ans.begin(), ans.end());
        if (ans == "")
            cout << 0 << '\n';
        else
            cout << ans << '\n';
    }
    return 0;
}