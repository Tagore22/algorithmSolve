#include <iostream>

using namespace std;

int N;
pair<int, int> answer = make_pair(0, -1);
int board[5];

int CalMax()
{
    int maxnum = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = i + 1; j < 4; ++j)
            for (int k = j + 1; k < 5; ++k)
                maxnum = max(maxnum, (board[i] + board[j] + board[k]) % 10);
    return maxnum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int iter = 1; iter <= N; ++iter)
    {
        for (int i = 0; i < 5; ++i)
            cin >> board[i];
        int cur = CalMax();
        answer = answer.first <= cur ? make_pair(cur, iter) : answer;
    }
    cout << answer.second << '\n';
    return 0;
}