#include <iostream>

using namespace std;

// Ǯ��. 
// for���� �̿��Ͽ� N - 1ĭ��ŭ ������ ����ϰ� i * 2 - 1��ŭ *�� ����Ѵ�.
// ���� �Ųٷ� ������ �ݺ��Ѵ�.

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);

    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N - i; ++j)
            cout << ' ';
        for (int j = 1; j <= i * 2 - 1; ++j)
            cout << '*';
        cout << '\n';
    }
    for (int i = N - 1; i > 0; --i)
    {
        for (int j = 1; j <= N - i; ++j)
            cout << ' ';
        for (int j = 1; j <= i * 2 - 1; ++j)
            cout << '*';
        cout << '\n';
    }
    return 0;
}