#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// ��Ʈ��ŷ�� ��� ȣ��� dp�� �̿��� Ǯ�̴�.
// �� ����, ����, �밢������ �̵��Ҽ� �ִ� ������ ������ �� ������ �����ϴ�
// ����� N, N�� �����Ҽ� �ִ� ����� ���� ����ϸ� �ȴ�.
// �ٸ�, �ִ밪�� int���� ����⿡ long long Ÿ���� ����Ͽ��� �Ѵ�.

// �ڼ��� ������ �ּ����� �����.

bool board[33][33];
long long dp[33][33][3];
int N;

long long BackTrack(int y, int x, int pos)
{
    if (y == N && x == N)
        return 1;

    // �� ��ġ�� ���� ���⿡ ���� dp�� �����Ѵ�.
    long long& ans = dp[y][x][pos];
    if (ans != -1)
        return ans;

    ans = 0;

    // ���� �������� �����϶�.
    if (pos == 0)
    {
        if (!board[y][x + 1] && y <= N && x + 1 <= N)
            ans += BackTrack(y, x + 1, pos);
    }

    else if (pos == 1)
    {
        if (!board[y + 1][x] && y + 1 <= N && x <= N)
            ans += BackTrack(y + 1, x, pos);
    }

    else
    {
        if (!board[y][x + 1] && y <= N && x + 1 <= N)
            ans += BackTrack(y, x + 1, 0);
        if (!board[y + 1][x] && y + 1 <= N && x <= N)
            ans += BackTrack(y + 1, x, 1);
    }
    // �밢���� ��� ��Ȳ���� �����ϼ� �ֱ⿡ ���Ǹ� �����ϸ� ������ �̵�.
    if (!board[y][x + 1] && !board[y + 1][x + 1] && !board[y + 1][x] &&
        y + 1 <= N && x + 1 <= N)
        ans += BackTrack(y + 1, x + 1, 2);

    return ans;
}

void MakeAnswer()
{
    memset(dp, -1, sizeof(dp));
    long long answer = BackTrack(1, 2, 0);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}