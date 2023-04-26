#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// ���� �ƴ� ������ ���� ��̴� T^T.
// �������� �������� ���õ� ��ó�� ��ǥ�� 1, 1���� �����ϰ� �� ĭ�� 1���� ���� ������ �ߴµ�
// �׷��� ���� ��� N = 5, M = 5�϶� K = 5�϶� K�� ��ǥ�� 1, 5���� ������ N �� M�� �̿��ؼ� K����
// ����������� ��ǥ�� 1, 5�� ������ �ʾҴ�.
// ����� �� Ǯ�̴� ��ǥ�� 0, 0���� ���� ĭ�� 0���� �����ϴ� ������ ġȯ�Ͽ� Ǯ��� �ߴ�.

int rot[2][2] = { {0, 1}, {1, 0} }; // ������, �Ʒ�.
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