#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, answer = 0;
    cin >> N >> M;
    int piv = (M % 2 == 0 ? M / 2 : M / 2 + 1);
    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;
        int num = 0;
        for (int j = 0; j < M; ++j)
        {
            if (str[j] == 'O')
                ++num;
            if (num >= piv)
            {
                ++answer;
                break;
            }
        }
    }
    cout << answer << '\n';
    return 0;
}