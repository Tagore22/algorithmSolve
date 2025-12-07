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
        int j;
        cin >> j;
        for (int i = 0; i < j; ++i)
        {
            if (i == 0 || i == j - 1)
            {
                for (int k = 0; k < j; ++k)
                    cout << '#';
                cout << '\n';
            }
            else
            {
                cout << '#';
                for (int k = 0; k < j - 2; ++k)
                    cout << 'J';
                cout << '#' << '\n';
            }
        }
        cout << '\n';
    }
    return 0;
}