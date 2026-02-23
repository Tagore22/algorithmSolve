#include <iostream>

using namespace std;

// 풀이.
// 너무 어렵게 생각했는데 기존에는 현재 행의 원소와 열의 원소를 한번에
// 구하려고 했었다. 굳이 그럴 필요 없이 현재 열의 원소값만을 구하면 되는데
// 주어지는 격자값이 두 원소의 겹치는 값이니 적어도 이 값은 무조건
// 가지고 있어야 하기에 격자값을 |= 값으로 추가해주고 출력하면 된다.

int N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int ans = 0;
        for (int j = 0; j < N; ++j)
        {
            int cur;
            cin >> cur;
            ans |= cur;
        }
        cout << ans << ' ';
    }
    cout << '\n';
    return 0;
}