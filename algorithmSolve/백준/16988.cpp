#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// Ǯ��.
// �������� �׷��� Ž�� ������. �� ������ ũ�� ������ ���� 2������ ������ Ǯ��� �Ѵ�.

// 1. 2���� ����.
// 2. �� ���� ������ �ִ� ����� ���� ������ ���Ѵ�.

// ù��°�� �����ϰ� ��Ʈ��ŷ���� �����Ͽ���. �̶� ��ĭ���� ���� �Ѽ� �ֱ� ������ �ݵ��
// ���Ұ��� 0�� ��ǥ���� ���� �Ѵ�.
// �ι�°�� BFS�� �����Ͽ��µ� �Ʒ� 2������ �����ؾ��Ѵ�.

// 1. �ֺ��� 1�϶����� �׳� continue�� �̿��Ͽ� �ѱ�� ������ 0�� ���� ���信 ���Ե��� �ʰ� �����ؾ��ϸ鼭��
// �湮�� �صξ�� ����� �� ���� ���Ҽ� �ִ�. 0�̶�� �׳� �����ϰ� BFS�� Ż���ϸ� �Ŀ� �� �κп� ���Ե� ���Ұ���
// 2�� ��ǥ�� �������� BFS�� ȣ��Ǿ����� cur�� �þ ���ɼ��� �����ϱ� �����̴�.
// 2. BFS�� ���� ������ ���Ҷ� �̹� �湮�Ѱ��� ���ؾ��Ѵ�.

// ����� ������ �״�� �����ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int board[20][20], rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
bool visit[20][20] = { false, };
int N, M, answer = 0;

// y, x���� �����ϴ� ������ �ִ� ���� ������ ���ϴ� BFS �Լ�.
int BFS(int y, int x)
{
    queue<pair<int, int>> que;
    que.push(make_pair(y, x));
    visit[y][x] = true;
    int ans = 1;
    bool isfind = true;

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        // �����¿� 4�������� ��ȸ�ϸ� �̵��Ѵ�.
        for (int i = 0; i < 4; ++i)
        {
            int ny = y + rot[i][0];
            int nx = x + rot[i][1];

            // �������� ����ų� 1�� �����ִٸ� ���̻� ���ư��� ���Ѵ�.
            if (ny < 0 || ny >= N || nx < 0 || nx >= M || visit[ny][nx] ||
                board[ny][nx] == 1)
                continue;
            // 0�̶�� ���� BFS������ ������ �ִ� ���� ������ 0�̴�. ������ ���� ��湮��
            // ���� ���� �ٷ� ������ �ʰ� �湮�Ҽ� �ִ� ��� ���� �湮�Ѵ�. ���� ��� �Ʒ��� ������
            // 0 2 1
            // 1 2 1
            // 1 1 1 
            // ���� ���� ��Ȳ�϶� ���� ���� 0, 1 ��ǥ�� 2���� BFS�� ���۵ȴ�. �̶� �����¿쿡�� ������
            // ���� ���� ����Ǵµ� 0�̱� ������ �����Ѵ�. �� ���� 1, 1�� 2���� �ٽ� BFS�� ���۵ȴ�.
            // �� ��ġ�� 0, 1�� �Բ� ���������ϴ� 2����, �����δ� ����, �Ʒ�, �������� 1�� �����ְ�
            // ���� 2�� �̹� �湮�� ���̱⿡ �ƹ� ���� ���� BFS���� 1�� ��ȯ�ϰ� �Ǿ� Ʋ�� ���� 
            // �����ϰ� �ȴ�. ���� 0�� ������ ���������ϴ� 2�鵵 �ٷ� Ż������ �ʰ� isfind ������ ����
            // ������������ ���Ÿ��� ���� �Ȱ��� �湮�ؾ� �Ѵ�.
            if (board[ny][nx] == 0)
            {
                isfind = false;
                continue;
            }
            ++ans;
            que.push(make_pair(ny, nx));
            visit[ny][nx] = true;
        }
    }
    // isfind�� ���� ���� ������ ��ȯ�ȴ�.
    return isfind ? ans : 0;
}

void MakeAnswer()
{
    // N * M���� ��ǥ���� ���Ѵ�. �ٸ� �ι�° ��ǥ second�� ������ first + 1���� �����Ͽ�
    // �ߺ��� ���´�.
    for (int first = 0; first < N * M; ++first)
    {
        int fy = first / M, fx = first % M;
        if (board[fy][fx] != 0)
            continue;
        board[fy][fx] = 1;
        for (int second = first + 1; second < N * M; ++second)
        {
            int sy = second / M, sx = second % M;
            if (board[sy][sx] != 0)
                continue;
            board[sy][sx] = 1;
            memset(visit, false, sizeof(visit));
            int cur = 0;
            for (int i = 0; i < N; ++i)
            {
                for (int j = 0; j < M; ++j)
                {
                    if (board[i][j] == 2 && !visit[i][j])
                        cur += BFS(i, j);
                }
            }
            answer = max(answer, cur);
            board[sy][sx] = 0;
        }
        board[fy][fx] = 0;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

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