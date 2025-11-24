#include <iostream>

using namespace std;

int N, M;
int col[500];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    int sum = 0, maxnum = 0;
    for (int i = 0; i < N; ++i)
    {
        int cur = 0;
        for (int j = 0; j < M; ++j)
        {
            string str;
            cin >> str;
            for (int k = 0; k < str.size(); ++k)
            {
                if (str[k] == '9')
                {
                    ++cur;
                    ++col[j];
                }
            }
        }
        sum += cur;
        maxnum = max(maxnum, cur);
    }
    for (int i = 0; i < M; ++i)
        maxnum = max(maxnum, col[i]);
    cout << sum - maxnum << '\n';
    return 0;
}