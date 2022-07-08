#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> cost, cashe;
int N, FirstNum;
const int MAXNUM = 987654321;

int PlusTail(int EndNum)
{
    int tail = MAXNUM;
    for (int i = 0; i < 3; ++i)
        if (i != FirstNum && i != EndNum)
            tail = min(tail, cost[N - 1][i]);
    return tail;
}

int DP(int prev, int num)
{
    if (num == N - 1)
        return PlusTail(prev);
    int& ans = cashe[prev][num];
    if (ans != -1)
        return ans;
    ans = MAXNUM;
    for (int i = 0; i < 3; ++i)
        if (i != prev)
            ans = min(ans, DP(i, num + 1) + cost[num][i]);
    return ans;
}

void MakeAnswer()
{
    int answer = MAXNUM;
    for (int i = 0; i < 3; ++i)
    {
        cashe.assign(3, vector<int>(N - 1, -1)); //매번 초기화하지 않으면 안된다. 주의할것.
        FirstNum = i;
        answer = min(answer, DP(i, 1) + cost[0][i]);
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cost.assign(N, vector<int>(3, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> cost[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}