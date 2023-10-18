#include <iostream>
#include <queue>

using namespace std;

// Ǯ��.
// �������� ���� �˰����� �ϳ� ������� ������.
// C���� C�� �̵��ϴ� �ִܰŸ��� ������ �ٲ�� �ּ� Ƚ���� ����ϴ� ������.
// �ܼ��� BFS�� �����ϸ� �湮 ������ ���� ���� �޶����� �Ǿ� ����� Ǯ���� ����.
// ���� ���ͽ�Ʈ�� �̿��ؼ� ���� Ƚ���� �������� ť�� ��ȸ�ؾ� �Ѵ�.
// ���� � ���� i, j�� �Ȱ��� �湮�ص� � ���⿡�� �湮�ߴ����� ���� �� Ƚ���� �޶����Ƿ�
// �̰� ���� DP�� �̿��ؾ� �ߴ�. ����� ���������� �ᱹ Ǯ� �����̴�.

// �ڼ��� ������ �ּ����� �����.

char board[100][100];
int rot[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; // ��, ��, ��, ��
pair<int, int> point[2];
int W, H;

void BFS()
{
    // ���ͽ�Ʈ�� �˰����� ���� �켱���� ť. ������ �ؾ��ؼ� ����ü�� ���� ���� �ʾұ⿡
    // Ÿ�Ը��� ���ڻ쳵��.
    priority_queue<pair<int, pair<pair<int, int>, int>>> que;
    // �������� ������ �ٲ� �ſ��� ���� �ʱ⿡ ������ -1�� ó���Ѵ�.
    que.push(make_pair(0, make_pair(make_pair(point[0].first, point[0].second), -1)));
    // �� ���� �� ���⿡ ���� DPó��.
    int dist[100][100][4];
    // ��� ���� �ִ밪���� �ʱ�ȭ�����ش�.
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            for (int k = 0; k < 4; ++k)
            {
                dist[i][j][k] = 987654321;
            }
        }
    }
    // ��� �������� 0���� �ٲ۴�.
    for (int i = 0; i < 4; ++i)
        dist[point[0].first][point[0].second][i] = 0;

    while (!que.empty())
    {
        int cost = -que.top().first;
        int y = que.top().second.first.first;
        int x = que.top().second.first.second;
        int dir = que.top().second.second;
        que.pop();

        // ���ʷ� ���������� ���� ���� Ƚ���� ���� �����̹Ƿ� �����信 �ش��Ѵ�.
        // ����� Ż���Ѵ�.
        if (y == point[1].first && x == point[1].second)
        {
            cout << cost << '\n';
            return;
        }

        // 4���� ��� �̵��Ҽ� �ִ��� Ȯ���Ѵ�.
        for (int i = 0; i < 4; ++i)
        {
            int dy = y + rot[i][0];
            int dx = x + rot[i][1];

            // �������� ����ų� ������ �������̶�� �����Ѵ�.
            if (dy < 0 || dy >= H || dx < 0 || dx >= W || board[dy][dx] == '*')
                continue;

            int next_cost = cost;
            // ������ -1(������)�� �ƴϰ�, ���� ����� ���� ������ �ٸ��ٸ� Ƚ���� 1 ������Ų��.
            if (dir != -1 && dir != i)
                next_cost = cost + 1;

            // Ƚ���� ���� Ƚ������ ���ų� ũ�ٸ� �����Ѵ�.
            if (dist[dy][dx][i] <= next_cost)
                continue;

            // ���� Ƚ���� �����ϰ� ť�� �ִ´�.
            dist[dy][dx][i] = next_cost;
            que.push(make_pair(-next_cost, make_pair(make_pair(dy, dx), i)));
        }
    }
}

void MakeAnswer()
{
    BFS();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> W >> H;
    int p = 0;
    string str;
    for (int i = 0; i < H; ++i)
    {
        cin >> str;
        for (int j = 0; j < W; ++j)
        {
            board[i][j] = str[j];
            if (board[i][j] == 'C')
            {
                point[p] = make_pair(i, j);
                ++p;
            }
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}