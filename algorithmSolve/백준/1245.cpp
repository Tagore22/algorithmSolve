#include <iostream>
#include <queue>

using namespace std;

// Ǯ��.
// BFS�� ���ڵ��� ��ȸ�Ͽ� ����츮���� ������ ã�� ������. BFS��ȸ�� ������ ������ ����.

// 1. ��ǥ���� ����ų�, ���� ���� ��ǥ�� ��湮�Ҷ�, ������ ��ǥ���� ���� ��ǥ������ ���������� �����Ѵ�.
// 2. ������ ��ǥ���� ���� ��ǥ������ Ŭ������ ����츮�� �ɼ� �����Ƿ� bool ���� isFind�� false�� ������
// �����Ѵ�.

// ��� ��ǥ���� ��ȸ�ϸ� �湮���� ���� ��ǥ�� �������� BFS ��ȸ�� ���ָ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int board[100][70];
int rot[8][2] = { {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1} };
int N, M, answer = 0;
bool visit[100][70] = { false, };
bool isFind = true;

void BFS(int y, int x)
{
    queue<pair<int, int>> que;
    que.push(make_pair(y, x));
    visit[y][x] = true;

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for (int i = 0; i < 8; ++i)
        {
            int ny = y + rot[i][0];
            int nx = x + rot[i][1];

            // ��ǥ���� ����ų�, ������ ��ǥ���� ���� ��ǥ������ �۰ų�, ���� ���� ���� ��湮�Ҷ�����
            // �����Ѵ�.
            if (ny < 0 || ny >= N || nx < 0 || nx >= M || board[ny][nx] < board[y][x]
                || (visit[ny][nx] && board[ny][nx] == board[y][x]))
                continue;
            // ������ ��ǥ���� Ŭ�� ���� ��ǥ�� ����츮�� �ɼ� �����Ƿ� isFind�� false�� ������
            // �����Ѵ�.
            if (board[ny][nx] > board[y][x])
            {
                isFind = false;
                continue;
            }
            que.push(make_pair(ny, nx));
            visit[ny][nx] = true;
        }
    }
}

void MakeAnswer()
{
    // ��� ��ǥ���� ��ȸ�ϸ� ���� �湮���� ���� ������ BFS��ȸ�� �Ͽ�
    // ����츮���� ������ ã�´�.
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (!visit[i][j])
            {
                isFind = true;
                BFS(i, j);
                if (isFind)
                    ++answer;
            }
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
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