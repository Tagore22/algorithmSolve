#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Ǯ��.
// ���� �ǳʴ� ��츦 �����ϰ� �� ���� ���������� �����Ҽ� �ִ� ��� ��ǥ���� �湮�Ѵ�.
// �� ���� �ٸ� ���� ��ġ�� ��ȸ�ϸ� �����ߴ��� Ȯ���ϸ� �ȴ�. ó������ ���귮�� ���̱� ����
// ���� ���� ��ȸ���� �湮�� ������ BFS ��ȸ�� �����ϴ� ������� �����ߴµ� �ٽ� �����غ���
// 1��° ���� ��ȸ���� �湮�� ������ 2��° ���� ��ȸ���� �湮�� ������ ���� �������� �ִ�.
// �̷� ��Ȳ���� �� �ҵ��� ��ȸ�ϸ� �湮�� ���� ��ġ�� 2��° ���� ��ȸ�ϼ��� �ְ�
// 1��° ���� ��ȸ�ϼ��� �ִµ� 2��° �ҿ� ������ �ִٴ°� �߸��� ����̱� �����̴�.

// �ڼ��� ������ �ּ����� �����.

// �� ��ǥ���� �̵��Ҽ� ����, �ǳʾ߸� �ϴ� ��ǥ�� �����ϴ� ���� �迭.
vector<pair<int, int>> board[101][101];
pair<int, int> cow[100];
int N, K, R;
bool visit[101][101] = { false, };
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };

void BFS(int y, int x)
{
    queue<pair<int, int>> que;
    que.push(make_pair(y, x));
    // �� �湮 ���θ� �ʱ�ȭ�Ѵ�.
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            visit[i][j] = false;
    visit[y][x] = true;

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + rot[i][0];
            int nx = x + rot[i][1];

            // ���� ��ǥ���� �̵��Ϸ��� ��ǥ�� ���� �ǳʾ��ϴ� ���̶��
            // �����Ѵ�.
            bool bCango = true;
            for (auto& c : board[y][x])
            {
                if (c.first == ny && c.second == nx)
                {
                    bCango = false;
                    break;
                }
            }
            if (ny <= 0 || ny > N || nx <= 0 || nx > N || visit[ny][nx] || !bCango)
                continue;

            que.push(make_pair(ny, nx));
            visit[ny][nx] = true;
        }
    }
}

void MakeAnswer()
{
    int answer = 0;
    for (int i = 0; i < K - 1; ++i)
    {
        // i��° ���� ��ġ���� BFS ��ȸ�� �湮�Ҽ� �ִ� ��� ���� �湮�ϰ�
        // i + 1������ �湮���� ���� �ҵ��� ��ġ�� ����Ѵ�.
        // (i, j), (j, i) ���� �ߺ��� ���� ���� �ݵ�� i + 1��°���� ��ȸ�ؾ��Ѵ�.
        BFS(cow[i].first, cow[i].second);

        for (int j = i + 1; j < K; ++j)
            if (!visit[cow[j].first][cow[j].second])
                ++answer;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K >> R;
    int r1, c1, r2, c2;
    for (int i = 0; i < R; ++i)
    {
        cin >> r1 >> c1 >> r2 >> c2;
        board[r1][c1].push_back(make_pair(r2, c2));
        board[r2][c2].push_back(make_pair(r1, c1));
    }
    for (int i = 0; i < K; ++i)
        cin >> cow[i].first >> cow[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}