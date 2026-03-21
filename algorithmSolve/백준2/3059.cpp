#include <iostream>
#include <cstring>

using namespace std;

int T;
string str;
bool isplus[26];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    for (int iter = 0; iter < T; ++iter)
    {
        memset(isplus, false, sizeof(isplus));
        cin >> str;
        for (int i = 0; i < str.size(); ++i)
            isplus[str[i] - 'A'] = true;
        int answer = 0;
        for (int i = 0; i < 26; ++i)
            if (!isplus[i])
                answer += (i + 65);
        cout << answer << '\n';
    }
    return 0;
}