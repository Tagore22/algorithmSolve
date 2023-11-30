#include <iostream>
#include <cstring>

using namespace std;

// 18290���� �� ���� Ǯ��.
// ���� ���Ϳ� ���� ������ �������� �ʰ� ��Ʈ��ŷ�� ������ �ش�ȭ ���Ѽ� Ǫ�� Ǯ���̴�.
// �Ź� ��ȸ�� �ϳ��� �������� ��ȸ�̹Ƿ� ���Ͱ� �ƴ� bool �迭�� �̿��Ͽ� ������ �湮�ߴ� ĭ�� �����ص� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int board[10][10];
bool visit[10][10];
int N, M, K;

// ��� ��ȸ�� �����ϴ� �Լ�.
int DFS(int y, int x, int num)
{
    // �ٷ� �̺κп��� �Ѱ��� �Ǽ��� �ߴ�. ���� Ǯ�̿����� num�� 1�϶� ������ + ���簪�� �ٷ� ��ȯ�ߴµ�
    // �� Ǯ�̿����� �׷��� �ȵȴ�. �ֳ��ϸ� ���� Ǯ�̿����� �� �̵����� ������ ĭ���� �̸� Ȯ���ϰ� �Ѿ�µ�
    // �� Ǯ�̿����� �� ��ġ�� ��� �� ��ġ���� �ٽ� �����ϱ� ������ ����ó���ϸ� �Ȱ��� ���� �ߺ��ȴ�.
    if (num == 0)
        return 0;

    int ans = -50000;
    int from = x + 1;
    for (int i = y; i < N; ++i)
    {
        for (int j = from; j < M; ++j)
        {
            // ���� ��ġ�� �̹� �湮�Ͽ��ų�, ������ ������ ĭ�鿡 �̹� �湮�Ͽ��ٸ� �����Ѵ�.
            if (!visit[i][j] && !visit[i - 1][j] && !visit[i][j - 1])
            {
                visit[i][j] = true;
                ans = max(ans, DFS(i, j, num - 1) + board[i][j]);
                visit[i][j] = false;
            }
        }
        from = 0;
    }
    return ans;
}

void MakeAnswer()
{
    memset(visit, false, sizeof(visit));
    int answer = DFS(0, -1, K);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}