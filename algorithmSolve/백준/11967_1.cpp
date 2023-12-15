#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 11967���� �� ���� Ǯ��.
// �������� ���� �������� �湮���� ���� ����� deque�� ��Ƽ� �Ź� �ݺ��Ͽ�����
// �̰��� ���� ������ �ݺ��ϴ� ���̾���. ���� Ű�ų� ���ο� ��ġ�� �̵��Ҷ�����
// ������ 4������ Ž���Ͽ� �湮 ���θ� �����ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

vector<pair<int, int>> board[101][101];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // ����, ����, ������, �Ʒ���.
int N, M;

int BFS()
{
    queue<pair<int, int>> que;
    que.push(make_pair(1, 1));
    vector<vector<bool>> visit(N + 1, vector<bool>(N + 1, false));
    vector<vector<bool>> isLight(N + 1, vector<bool>(N + 1, false));
    visit[1][1] = true;
    isLight[1][1] = true;
    int ans = 1;

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for (auto next : board[y][x])
        {
            // ���Ӱ� ���� ���� ���̶��
            if (!isLight[next.first][next.second])
            {
                // ���� ������ �����ϰ� ������ ans�� 1 ������Ų��.
                isLight[next.first][next.second] = true;
                ++ans;

                // ������ 4������ ���� �湮 ������ ���� ã�´�.
                for (int i = 0; i < 4; ++i)
                {
                    int dy = next.first + rot[i][0];
                    int dx = next.second + rot[i][1];

                    // �迭 �������� ����ų� �湮���� ���� ���̶�� �����Ѵ�.
                    if (dy <= 0 || dy > N || dx <= 0 || dx > N || !visit[dy][dx])
                        continue;

                    // ������ 4������ ��ġ�� �ϳ��� �湮�� ���̶�� �ٷ� ���� ���� ��ġ�� �湮�� �����ϴ�.
                    visit[next.first][next.second] = true;
                    que.push(make_pair(next.first, next.second));
                    break;
                }
            }
        }

        // ���� ��ġ���� 4������ ��ȸ�Ѵ�.
        for (int i = 0; i < 4; ++i)
        {
            int dy = y + rot[i][0];
            int dx = x + rot[i][1];

            // �迭 �������� ����ų� ���� ������ ���� ���̶�� �����Ѵ�.
            if (dy <= 0 || dy > N || dx <= 0 || dx > N || visit[dy][dx] || !isLight[dy][dx])
                continue;

            // ���Ӱ� �湮�Ҽ� �ִ� ������ �����Ѵ�.
            visit[dy][dx] = true;
            que.push(make_pair(dy, dx));
        }
    }
    return ans;
}

void MakeAnswer()
{
    int answer = BFS();
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    pair<int, int> from, to;
    for (int i = 0; i < M; ++i)
    {
        cin >> from.first >> from.second >> to.first >> to.second;
        board[from.first][from.second].push_back(to);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}