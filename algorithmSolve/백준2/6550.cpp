#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s, t;
    while (cin >> s >> t)
    {
        int idx = 0;
        bool isfind = false;
        for (int i = 0; i < t.size(); ++i)
        {
            if (s[idx] == t[i])
            {
                ++idx;
                if (idx == s.size())
                {
                    isfind = true;
                    break;
                }
            }
        }
        cout << (isfind ? "Yes" : "No") << '\n';
    }
    return 0;
}