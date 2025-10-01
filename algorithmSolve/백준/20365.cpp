#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    string str;
    cin >> N >> str;

    char prev = ' ';
    int bnum = 0, rnum = 0;
    for (int i = 0; i < N; ++i)
    {
        if (prev != str[i])
        {
            prev = str[i];
            if (str[i] == 'B')
                ++bnum;
            else
                ++rnum;
        }
    }

    int answer = bnum + rnum;
    answer = min(answer, bnum + 1);
    answer = min(answer, rnum + 1);
    cout << answer << '\n';
    return 0;
}