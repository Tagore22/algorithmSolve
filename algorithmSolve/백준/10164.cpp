#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 별거 아닌 곳에서 한참 헤맸다 T^T.
// 기존에는 문제에서 제시된 것처럼 좌표도 1, 1에서 시작하고 각 칸을 1부터 세는 것으로 했는데
// 그러면 예를 들어 N = 5, M = 5일때 K = 5일때 K의 좌표는 1, 5여야 하지만 N 과 M을 이용해서 K값을
// 계산했을때의 좌표가 1, 5가 나오질 않았다.
// 제대로 된 풀이는 좌표가 0, 0부터 시작 칸이 0부터 시작하는 것으로 치환하여 풀어야 했다.

int rot[2][2] = { {0, 1}, {1, 0} }; // 오른쪽, 아래.
int dp[15][15];
int N, M, K;
pair<int, int> goal;

int DFS(int y, int x)
{
    if (y == goal.first && x == goal.second)
        return 1;

    int& ans = dp[y][x];
    if (ans != -1)
        return ans;

    ans = 0;
    for (int i = 0; i < 2; ++i)
    {
        int dy = y + rot[i][0];
        int dx = x + rot[i][1];

        if (dy > goal.first || dx > goal.second)
            continue;

        ans += DFS(dy, dx);
    }
    return ans;
}

void MakeAnswer()
{
    memset(dp, -1, sizeof(dp));
    if (K == 0)
    {
        goal = make_pair(N - 1, M - 1);

        cout << DFS(0, 0) << '\n';
    }
    else
    {
        K -= 1;
        int answer = 1;
        goal = make_pair(K / M, K % M);
        answer *= DFS(0, 0);

        pair<int, int> prev = goal;
        goal = make_pair(N - 1, M - 1);
        answer *= DFS(prev.first, prev.second);

        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}