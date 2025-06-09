#include <iostream>

using namespace std;

int main()
{
    int N;
    string str;
    cin >> N >> str;

    string from = "", to = "";
    for (int i = 0; i < N - 1; ++i)
    {
        from += str[i];
        to = str[N - 1 - i] + to;
        bool isdiff = false;
        for (int j = 0; j < from.size(); ++j)
        {
            if (from[j] != to[j])
            {
                if (!isdiff)
                {
                    isdiff = true;
                }
                else
                {
                    isdiff = false;
                    break;
                }
            }
        }
        if (isdiff)
        {
            cout << "YES" << '\n';
            return 0;
        }
    }
    cout << "NO" << '\n';
    return 0;
}