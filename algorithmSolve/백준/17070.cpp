#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// DP�� DFS�� ȥ�� ������. �ٸ� ��ǥ�� ������ ������, �Ʒ��� ������ ������ ������
// �Դ� ���� �ٽ� Ȯ���ϴ� �ߺ� ó���� �� �ʿ䰡 ����.
// �ٸ� 3�� �迭�� DP�� �����ؾ��ϴµ�, ��� ��ǥ�� �Ȱ��� �����߾
// �������� ��翡 ���� N, N�� �����Ҽ� �ְ� ���� ���̳��� �����̴�.
// ����, ���� Ȥ�� ���η� �����̴� �Ͱ� �밢������ �����̴� ���� 
// ������ �ٸ��� ������ �� ���� �����ؾ� �Ѵ�.

// P.S �̹����� Ǯ�� �и��� ������ �¾Ҵµ� ���� �̻��ϰ� ���Ծ���. ���� �߸��Ȱ����� ���� ����ߴµ�
// rot�迭�� ��������. ������ �������� �������� rot[3][3][2]�� �ƴ� rot[3][2][2]�� �ٿ�������.
// �׷��� ���� ������ ����� dir = 2�ε� dir = 1�� �̻��ϰ� ���׹��� ������ ���� ������ �ʾҾ���.
// DP�� �� �α׷� Ȯ���ϱⰡ �ʹ� �����. T^T

int rot[3][3][2] = { {{0, 1}, {-1, -1}, {-1, -1}}, {{0, 1}, {-1, -1}, {1, 0}}, {{-1, -1}, {-1, -1}, {1, 0}} };
int dp[16][16][3];
int board[16][16];
int N;

int DFS(int y, int x, int dir)
{
    // N, N�� �����ߴٸ� 1�� ��ȯ������ ����� ���� ������Ų��.
    if (y == N - 1 && x == N - 1)
        return 1;

    // ����Ͽ��� ��ǥ �Ӹ� �ƴ϶� �� ������� DP�� ���Խ��Ѿ߸� �Ѵ�.
    int& ans = dp[y][x][dir];
    if (ans != -1)
        return ans;

    ans = 0;

    // ���� Ȥ�� ���η� �����϶�.
    for (int i = 0; i < 3; ++i)
    {
        if (rot[dir][i][0] == -1)
            continue;

        int dy = y + rot[dir][i][0];
        int dx = x + rot[dir][i][1];

        if (dy < 0 || dy >= N || dx < 0 || dx >= N || board[dy][dx] == 1)
            continue;

        ans += DFS(dy, dx, i);
    }

    // �밢������ �����϶�. ���� �����ϼ� ���ٸ� �׳� ���� ����� ���� �ٷ� ��ȯ�Ѵ�.
    int dy = y + 1;
    int dx = x + 1;

    if (dy < 0 || dy >= N || dx < 0 || dx >= N || board[dy][dx] == 1 ||
        board[dy][x] == 1 || board[y][dx] == 1)
        return ans;

    ans += DFS(dy, dx, 1);

    return ans;
}

void MakeAnswer()
{
    memset(dp, -1, sizeof(dp));

    int answer = DFS(0, 1, 0);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}