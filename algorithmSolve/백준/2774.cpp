#include <iostream>

using namespace std;

int main()
{
    bool visit[10] = { false, };
    int T, answer;
    cin >> T;
    string str;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> str;
        for (int i = 0; i < 10; ++i)
            visit[i] = false;
        answer = 0;
        for (int i = 0; i < str.size(); ++i)
        {
            int now = str[i] - 48;
            if (!visit[now])
            {
                ++answer;
                visit[now] = true;
            }
        }
        cout << answer << '\n';
    }
    return 0;
}