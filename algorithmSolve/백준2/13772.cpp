#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int holes[26] = { 1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 };
    int N;
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; ++i)
    {
        string str;
        getline(cin, str);
        int ans = 0;
        for (int j = 0; j < str.size(); ++j)
        {
            if (str[j] == ' ')
                continue;
            ans += holes[str[j] - 'A'];
        }
        cout << ans << '\n';
    }
    return 0;
}