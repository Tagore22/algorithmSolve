#include <iostream>
#include <algorithm>

using namespace std;

int K, s, t;
int board[51];
pair<int, int> ans[50];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> K;
    for (int iter = 1; iter <= K; ++iter)
    {
        cin >> s >> t;
        for (int i = 1; i <= s; ++i)
            board[i] = 0;
        for (int i = 0; i < t; ++i)
        {
            int idx, num;
            cin >> idx >> num;
            board[idx] += num;
        }
        for (int i = 1; i <= s; ++i)
            ans[i - 1] = make_pair(board[i], i);
        sort(ans, ans + s, greater<>());
        pair<int, int> answer = ans[0];
        for (int i = 1; i < s; ++i)
        {
            if (answer.first <= ans[i].first * 2)
            {
                answer.first = -1;
                break;
            }
        }
        cout << "Data Set " << iter << ':' << '\n';
        if (answer.first != -1)
            cout << answer.second << '\n';
        else
            cout << "No suspect." << '\n';
        cout << '\n';
    }
    return 0;
}