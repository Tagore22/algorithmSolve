#include <iostream>
#include <queue>

using namespace std;

// Ǯ��.
// BFS�� �ణ ���Ƴ��� ���� ��������. ���簢���� ���� ��� ��ǥ�� �������� �Ͽ� BFS ��ȸ�� �ϵ�,
// ������ ���� �͵��� ó���ؾ��Ѵ�.

// 1. ���� ��� ��ǥ�� �迭���� ������� �̿ܿ� ���� �ϴ� ��ǥ ���� �迭������ ����� Ȯ���ؾ��Ѵ�.
// 2. �� �̵��� ���簢���� ���� ���� ���� '1'���� �����ϴ����� Ȯ���ؾ��Ѵ�. ���� ���
// ���簢���� ���� ��� ��ǥ�� �������� ��ĭ �̵��Ѵٰ� ������ ���� ��ܺ��� ���� �ϴܱ��� ��ȸ�ϸ�
// '1'���� �����ϴ����� Ȯ���ؾ��Ѵ�. �̶�, �ٸ� 3���� ó���� �ʿ䰡 ����. 

// ����� 2���� ó���� ��ٷο���. 
// �ڼ��� ������ �ּ����� �����.

char board[1001][1001];
// 4�������� �̵��� ��ǥ��, �׶� ���� ��ȸ�ϴ� �̵���ǥ.
// 0��° �̵��� ���ʰ� 2��° �̵��� �������� ���� ��ܿ��� �Ʒ�������,
// 1��° �̵��� ���ʰ� 3��° �̵��� �Ʒ����� ���� ���ʿ��� ���������� �̵��ϸ� '1'�� �����ϴ��� Ȯ���Ѵ�.
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }, dir[2][2] = { {1, 0}, {0, 1} };
// �� ���� ��ȸ�Ҷ� ���� ��� ��ǥ���� �ʱ� ��ǥ���� �̵��ؾ��ϴ� ����.
int pos[4][2] = { {0, 0}, {0, 0}, {0, 1}, {1, 0} };
int N, M, H, W;
pair<int, int> from, to;

// �� ���� ��ȸ�ϸ� '1'�� �����ϴ����� Ȯ���ϴ� �Լ�.
bool CheckBorder(int y, int x, int idx)
{
    // ���� ��ܿ��� ��ȸ�� �����ϴ� ��ġ�� �ű��.
    int ny = y + pos[idx][0] * (H - 1);
    int nx = x + pos[idx][1] * (W - 1);

    // 0��°, 2��°�� ������ �Ʒ��� �̵��ϸ� 1��°, 3��°�� ���ʿ��� ���������� �̵��Ѵ�.
    int len = idx % 2 == 0 ? H : W;
    for (int i = 0; i < len; ++i)
    {
        // '1'�� �߰��ҽ� ���� �ɷ� �̵����� ����.
        if (board[ny][nx] == '1')
            return false;
        ny += dir[idx % 2][0];
        nx += dir[idx % 2][1];
    }
    // �̵� ����.
    return true;
}

// BFS ��ȸ�� ���� �̵��Ҽ� �ִ� ��� ��츦 ������.
void BFS()
{
    queue<pair<int, int>> que;
    que.push(from);
    bool visit[1001][1001] = { false, };
    visit[from.first][from.second] = true;
    int answer = -1;

    while (!que.empty())
    {
        ++answer;
        int qsize = que.size();
        for (int iter = 0; iter < qsize; ++iter)
        {
            int y = que.front().first;
            int x = que.front().second;
            que.pop();

            if (y == to.first && x == to.second)
            {
                cout << answer << '\n';
                return;
            }

            for (int i = 0; i < 4; ++i)
            {
                int ny = y + rot[i][0];
                int nx = x + rot[i][1];

                // ���� ��ܰ� Ȥ�� ���� �ϴܰ��� �迭���� ����ų�, ��湮�� Ȥ�� �׵θ���
                // '1'�� �߰ߵɽ� �̵��Ҽ� �����Ƿ� �����Ѵ�.
                if (ny <= 0 || ny + H - 1 > N || nx <= 0 || nx + W - 1 > M || visit[ny][nx] ||
                    !CheckBorder(ny, nx, i))
                    continue;

                que.push(make_pair(ny, nx));
                visit[ny][nx] = true;
            }
        }
    }
    cout << -1 << '\n';
}

void MakeAnswer()
{
    BFS();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            cin >> board[i][j];
    cin >> H >> W >> from.first >> from.second >> to.first >> to.second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}