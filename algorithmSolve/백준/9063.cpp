#include <iostream>

using namespace std;

// Ǯ��.
// ���� ũ�� ���� x���� ���̿� ���� ũ�� ���� y���� ���̸� ���Ͽ� ����ϸ� �ȴ�.

int N, min_X = 10001, max_X = -10001, min_Y = 10001, max_Y = -10001;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    int x, y;
    for (int i = 0; i < N; ++i)
    {
        cin >> x >> y;
        min_X = min(min_X, x);
        max_X = max(max_X, x);
        min_Y = min(min_Y, y);
        max_Y = max(max_Y, y);
    }
    cout << (max_X - min_X) * (max_Y - min_Y) << '\n';
    return 0;
}