#include <iostream>

using namespace std;

// Ǯ��.
// �־��� �� num�� 2�� ������ �������� ����� ���� 1�� ����� ���° �������� ����ϸ� �ȴ�.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T, num;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        cin >> num;
        int idx = 0;
        while (num > 0)
        {
            if (num % 2 == 1)
                cout << idx << ' ';
            num /= 2;
            ++idx;
        }
        cout << '\n';
    }
    return 0;
}