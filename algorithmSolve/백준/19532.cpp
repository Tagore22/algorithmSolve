#include <iostream>

using namespace std;

// Ǯ��.
// x�� y�� ������������ Ǫ�� �����̴�. �Ʒ�ó�� ��� �����ص� �ǰ�,
// x�� y�� ���� �������������� ġȯ�Ͽ� Ǯ� �ȴ�.

int a, b, c, d, e, f;

void MakeAnswer()
{
    for (int x = -999; x <= 999; ++x)
        for (int y = -999; y <= 999; ++y)
        {
            if (a * x + b * y == c && d * x + e * y == f)
            {
                cout << x << ' ' << y << '\n';
                return;
            }
        }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c >> d >> e >> f;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}