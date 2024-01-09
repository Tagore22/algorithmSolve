#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// Ǯ��.
// ������ �׷��� Ž�� �����̴�. BFS�� Ž�������� ��� ���� Ž���ϸ� �湮������ P�� ���� ����ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

char board[600][600];
int N, M;
pair<int, int> from;
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // ��, ��, ��, ��.

// BFS ��ȸ �Լ�.
void BFS()
{
    queue<pair<int, int>> que;
    que.push(from);
    bool visit[600][600];
    memset(visit, false, sizeof(visit));
    visit[from.first][from.second] = true;
    int answer = 0;

    while (!que.empty())
    {
        pair<int, int> here = que.front();
        que.pop();

        // ��, ��, ��, �� 4���� ��� �湮�غ���.
        for (int i = 0; i < 4; ++i)
        {
            int y = here.first + rot[i][0];
            int x = here.second + rot[i][1];

            // �迭���� ����ų�, �̹� �湮�߰ų�, ���̶�� �����Ѵ�.
            if (y < 0 || y >= N || x < 0 || x >= M || visit[y][x] || board[y][x] == 'X')
                continue;
            // ����̶�� ������ answer�� 1 ������Ų��.
            if (board[y][x] == 'P')
                ++answer;
            // �湮 ���θ� �����ϰ� ť�� �ִ´�.
            visit[y][x] = true;
            que.push(make_pair(y, x));
        }
    }
    if (answer != 0)
        cout << answer << '\n';
    else
        cout << "TT" << '\n';
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
    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        for (int j = 0; j < M; ++j)
        {
            board[i][j] = str[j];
            if (board[i][j] == 'I')
                from = make_pair(i, j);
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}