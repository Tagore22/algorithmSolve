#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// 2665���� DFSǮ���̴�. dp�� [50][50]���θ� ��� �;�����, � ��ǥ�� y, x�� �����Ҷ� �� ��������
// �ٲپ ���߿� �����Ѵ� ������ �������� �״�� ����� �ȴ�. �׷��� ������ dp�� [50][50][2500]����
// �ٲ� ������ dp�� ���Խ��Ѿ� �ߴ�. �׷��ٺ��� ����� ���� �������� �޸𸮵� �ӵ��� ���� ��Ƹ԰� �Ǿ���.

// �ڼ��� ������ �ּ����� �����.

bool board[50][50], visit[50][50];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // �� �� �� ��.
int dp[50][50][2500];
int N;

// ����Ͽ��� ������� ��� �����Ͽ��°� ���� ���ԵǾ���Ѵ�.
int DFS(int y, int x, int num)
{
    if (y == N - 1 && x == N - 1)
        return num;

    int& ans = dp[y][x][num];
    if (ans != -1)
        return ans;

    ans = 987654321;
    visit[y][x] = true;

    for (int i = 0; i < 4; ++i)
    {
        int dy = y + rot[i][0];
        int dx = x + rot[i][1];

        if (dy < 0 || dy >= N || dx < 0 || dx >= N || visit[dy][dx])
            continue;

        if (board[dy][dx])
            ans = min(ans, DFS(dy, dx, num));
        else
            ans = min(ans, DFS(dy, dx, num + 1));
    }
    visit[y][x] = false;
    return ans;
}

void MakeAnswer()
{
    memset(dp, -1, sizeof(dp));
    memset(visit, false, sizeof(visit));
    int answer = DFS(0, 0, 0);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        for (int j = 0; j < N; ++j)
            board[i][j] = str[j] - '0';
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}