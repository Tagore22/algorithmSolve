#include <iostream>
#include <queue>

using namespace std;

// Ǯ��.
// 2665���� BFSǮ��. �� �ں��� ���ϴ� DFS�ʹ� �޸� ���������� ���� ���س�����.
// �ߺ� ���δ� bool�� �ƴ� ������ �����ϴµ� �̹� ������ ĭ�� �ٲ� ���� ���� ĭ�� �ٲۼ����� ������ ���ų� �۱� �����̴�.
// �׷��� �ϳ��� ���س����� ������ dp[N - 1][N - 1]�� ���ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

// ó������ ������ DFS�� Ǯ���� �׷��µ� �ʹ� Ʋ�� �����־���. ���� �� ���� �þ߸� ����.

bool board[50][50];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // �� �� �� ��.
int dp[50][50];
int N;

void BFS()
{
    queue<pair<int, int>> que;
    que.push(make_pair(0, 0));
    // �ʱⰪ�� 0.
    dp[0][0] = 0;

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i)
        {
            int dy = y + rot[i][0];
            int dx = x + rot[i][1];

            if (dy < 0 || dy >= N || dx < 0 || dx >= N)
                continue;

            if (board[dy][dx])
            {
                if (dp[y][x] < dp[dy][dx])
                {
                    dp[dy][dx] = dp[y][x];
                    que.push(make_pair(dy, dx));
                }
            }
            else
            {
                if (dp[y][x] + 1 < dp[dy][dx])
                {
                    dp[dy][dx] = dp[y][x] + 1;
                    que.push(make_pair(dy, dx));
                }
            }
        }
    }
}

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            dp[i][j] = 987654321;
    BFS();

    cout << dp[N - 1][N - 1] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        for (int j = 0; j < N; ++j)
            board[i][j] = str[j] - '0';
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}