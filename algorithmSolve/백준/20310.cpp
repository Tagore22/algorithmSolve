#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;

    int one = 0, zero = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == '0')
            ++zero;
        else
            ++one;
    }
    one /= 2;
    zero /= 2;

    bool erased[500] = { false, };
    for (int i = 0; i < str.size(); ++i)
    {
        if (one == 0)
            break;
        if (str[i] == '1')
        {
            erased[i] = true;
            --one;
        }
    }
    for (int i = str.size() - 1; i >= 0; --i)
    {
        if (zero == 0)
            break;
        if (str[i] == '0')
        {
            erased[i] = true;
            --zero;
        }
    }
    for (int i = 0; i < str.size(); ++i)
        if (!erased[i])
            cout << str[i];
    cout << '\n';

    return 0;
}