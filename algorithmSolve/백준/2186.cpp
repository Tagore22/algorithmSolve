#include <iostream>

using namespace std;

// Ǯ��.
// ����� ������ �ƴϾ����� ũ��ū �Ǽ� �ϳ� ������ �� 1�ð����� ��� ������.
// ��... �׷��� �������� ������ �� Ǯ������ �Ѿ��.
// ������ ���� Ǯ��ô� ����� ������. �����ϱⰡ ��ٷο�� �ּ����� �����.

// �ڼ��� ������ �ּ����� �����.

// P.S �������� �޸� 2�� for������ str[0]�� ���Ͽ� ����ġ�⸦ �ϴ� �ӵ��� �� ��������.

int N, M, K;
char board[105][105];
int dp[105][105][85];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
string str;
int answer = 0;

// 1. ��� ĭ�� ��ȸ�ϸ� ���� �ܾ ��Ÿ���� DFS ����.
// 2. �� ĭ�� DFS ��ȸ���� �Ҷ� ���� �ܾ ��Ÿ���� ��ȸ ����.

// y, x���� idx��° ���ڸ� ã�� ��ȸ �Լ�.
int DFS(int y, int x, int idx)
{
    // ���� ���� ��ġ�� idx��°�� �̹� ���Ǿ��ִٸ� �� ��갪�� ��ȯ�ϰ� Ż���Ѵ�.
    int& ans = dp[y][x][idx];
    if (ans != -1)
        return ans;

    // ���������� �����Ͽ��ٸ� 1���� ����� ã������ 1�� ��ȯ�Ͽ� ���Ѵ�.
    if (idx == str.size() - 1)
        return 1;

    ans = 0;

    // ���⼭ ���� �Ǽ��ߴ�. �ƴ� ���ôٰ� �ؾ��ϳ�. ���ظ� �߸��ߴٰ� �ؾ��ϳ�.
    // �ѹ��� ������ K��ŭ �̵��ؾ��ϴ� ���� �ƴ� �ִ� 1 ~ K��ŭ�� �̵��� ������ ���̾���.
    for (int i = 0; i < 4; ++i)
        // �̵� ������ 1 ~ K�� �ø���.
        for (int j = 1; j <= K; ++j)
        {
            // �׸��� ���⼭ �� �Ǽ��� �ߴ�. ������ ���� j�� ���ؾ������� K�� ���߾���... �Ф�
            int ny = y + rot[i][0] * j;
            int nx = x + rot[i][1] * j;

            // �迭���� ����ų� �����Ѱ��� idx + 1��° ���ڰ� �ƴ϶�� �����Ѵ�.
            if (ny < 0 || ny >= N || nx < 0 || nx >= M || board[ny][nx] != str[idx + 1])
                continue;

            ans += DFS(ny, nx, idx + 1);
        }
    return ans;
}

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            for (int z = 0; z < str.size(); ++z)
                dp[i][j][z] = -1;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            // i, j��° ���� str[0]�� ���ٸ� DFS��ȸ�� �Ѵ�.
            if (board[i][j] == str[0])
                answer += DFS(i, j, 0);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i)
    {
        string cur;
        cin >> cur;
        for (int j = 0; j < M; ++j)
            board[i][j] = cur[j];
    }
    cin >> str;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}