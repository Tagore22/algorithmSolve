#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 17086���� �� ���� Ǯ��.
// �����غ��� �׳� �ϳ��� ť�� ��� ������ �ѹ��� �� ����ְ� �湮 ���θ� �ϳ��� ����ȭ��Ű�� �����̾���.

// �ڼ��� ������ �ּ����� �����.

vector<vector<bool>> visit;
queue<pair<int, int>> que;
int rot[8][2] = { {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1} };
int N, M, answer = -1;

// BFS��ȸ�� �ϴ� �Լ�.
void BFS()
{
    while (!que.empty())
    {
        // ���� ť�� �����ϴ� ���ҵ鸸�� ��ĭ�� �̵��ϱ� ���� 
        // ���� ť�� �����ϴ� ���ҵ鸸ŭ�� ��ȸ�Ѵ�.
        int qsize = que.size();
        for (int iter = 0; iter < qsize; ++iter)
        {
            int y = que.front().first;
            int x = que.front().second;
            que.pop();

            // 8�������� ��� �̵��غ���.
            for (int i = 0; i < 8; ++i)
            {
                int dy = y + rot[i][0];
                int dx = x + rot[i][1];

                // �̵��� ��ġ�� �迭���� ����ų� �̹� �湮�� ��ġ��� �����Ѵ�.
                if (dy < 0 || dy >= N || dx < 0 || dx >= M || visit[dy][dx])
                    continue;

                // �湮 ���θ� �����ϰ� ť�� ����ִ´�.
                visit[dy][dx] = true;
                que.push(make_pair(dy, dx));
            }
        }
        // ��ȸ�Ѹ�ŭ �Ÿ��� 1�� �����Ѵ�.
        ++answer;
    }
}

void MakeAnswer()
{
    BFS();
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    visit.resize(N, vector<bool>(M, false));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            int point;
            cin >> point;
            if (point == 1)
            {
                // �迭���� 1�� �����ġ�� �̸� ť�� ����ְ�
                // �湮 ���θ� �����Ѵ�.
                que.push(make_pair(i, j));
                visit[i][j] = true;
            }
        }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}