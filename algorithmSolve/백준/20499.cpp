#include <iostream>

using namespace std;

// Ǯ��.
// ���� �ƴѵ� ¥���� ���� ������.

int main()
{
    string str;
    cin >> str;
    int prev = 0, idx = 0, K, D, A;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == '/')
        {
            if (idx == 0)
                K = prev;
            else
                D = prev;
            prev = 0;
            ++idx;
            continue;
        }
        prev *= 10;
        prev += str[i] - 48;
    }
    A = prev;
    if (K + A < D || D == 0)
        cout << "hasu" << '\n';
    else
        cout << "gosu" << '\n';
    return 0;
}