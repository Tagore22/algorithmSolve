#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// ���� �ƴ� �����ε� �����ϰ� ���Ƴ���. �� �װ� ����������� �̻��ϰ� 12�ۿ���
// ��� Ʋ�ȴ�. �����̳� int ������ ����ٰų� �̷��� ���� ������ �������.
// ��������δ� K, H�� ��� 0�϶��� ��������. while���� answer�� 0���� Ŭ����
// ȣ��Ǳ� ������ answer�� 0�̶�� �����ü�� ���� �ʾҾ���.

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