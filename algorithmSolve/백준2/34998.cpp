#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int iter = 0; iter < T; ++iter)
    {
        int N, cur = 0;
        cin >> N;
        for (int i = 0; i < N; ++i)
        {
            char num, c;
            cin >> num >> c;
            if (num == '!')
                cur += 10;
            else
                cur += num - '0';
        }
        char num;
        cin >> num;
        if (num == '!')
            cur += 10;
        else
            cur += num - '0';
        if (cur > 9)
            cout << '!' << '\n';
        else
            cout << cur << '\n';
    }
    return 0;
}