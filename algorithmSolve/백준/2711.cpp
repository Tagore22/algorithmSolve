#include <iostream>

using namespace std;

// Ǯ��.
// �־����� ��Ÿ�� ��ġ�� ������ ������ ���ڵ��� ����Ѵ�.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T, num;
    cin >> T;
    string str;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> num >> str;
        for (int i = 0; i < str.size(); ++i)
        {
            if (i == num - 1)
                continue;
            cout << str[i];
        }
        cout << '\n';
    }
    return 0;
}