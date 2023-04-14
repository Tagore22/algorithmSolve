#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

// Ǯ��.
// BFS�� ���� ���Ƽ� �� ��������.
// �� ��ǥ�� �湮�Ҷ� �ߺ� �湮 ���θ� �˻��ϱ� ���� DP�� �̿��Ͽ� �迭�� �˻��ϴµ�
// �ܼ��� ��ǥ�������δ� �ȵǰ�, ���� ��� ���� �ν����� ���� DP�� �����ؾ��Ѵ�.
// �ֳ��ϸ�, �翬�ϰԵ� ���� 2�� �ν��� y, x�� �������� ���� �μ��� �ʰ� y, x�� ����������
// ���� ��찡 �ɼ� ���� �����̴�. �� ���丸 �˸� �������� ����� ���� ������.

// ���� 1, 1���� BFS�� ��ȸ�ϵ�, ����Ͽ��� ��ǥ��, ���� �μ� Ƚ���� ���� DP��
// �ߺ� ���θ� Ȯ���ذ��� N, M���� �����Ҽ� �ִ� �ִ� �Ÿ��� ���Ͽ� ����ϸ� �ȴ�.

struct pos
{
    int y;
    int x;
    int num;
    int dis;
};

int board[1001][1001];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // �� �� �� ��.
int N, M, K;
bool check[1001][1001][11];

int BFS()
{
    memset(check, false, sizeof(check));
    check[1][1][K] = true;
    queue<pos> que;
    que.push(pos{ 1, 1, K, 1 });

    while (!que.empty())
    {
        int y = que.front().y;
        int x = que.front().x;
        int num = que.front().num;
        int dis = que.front().dis;
        que.pop();

        if (y == N && x == M)
            return dis;

        for (int i = 0; i < 4; ++i)
        {
            int dy = y + rot[i][0];
            int dx = x + rot[i][1];

            if (dy <= 0 || dy > N || dx <= 0 || dx > M)
                continue;

            if (board[dy][dx] == 0 && !check[dy][dx][num])
            {
                check[dy][dx][num] = true;
                que.push(pos{ dy, dx, num, dis + 1 });
            }
            else if (board[dy][dx] == 1 && num > 0 && !check[dy][dx][num - 1])
            {
                check[dy][dx][num - 1] = true;
                que.push(pos{ dy, dx, num - 1, dis + 1 });
            }
        }
    }
    return -1;
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
    cout.tie(0);

    cin >> N >> M >> K;
    string str;
    for (int i = 1; i <= N; ++i)
    {
        cin >> str;
        for (int j = 1; j <= M; ++j)
            board[i][j] = str[j - 1] - '0';
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}