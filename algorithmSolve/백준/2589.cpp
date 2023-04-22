#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

// Ǯ��.
// BFS�� �̿��� �ִܰŸ� �����̴�.
// �������� �������� �𸣴� �����ε�, ���״�� �������� �������� ������� ���� �� �ִܰŸ��� ���ϸ� �ȴ�.
// ��, ��� �������� �����Ͽ� �����Ҽ� �ִ� ���� �� �ִܰŸ����� ��� ���Ͽ� ���� ū ���� ����ϸ� �ȴ�.

int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // �� �� �� ��.
bool board[50][50], check[50][50];
int N, M, answer = 0;

void BFS(int y, int x)
{
    queue<pair<int, int>> que;
    que.push(make_pair(y, x));
    memset(check, false, sizeof(check));
    check[y][x] = true;
    int ans = -1;

    while (!que.empty())
    {
        ++ans;
        int qsize = que.size();
        for (int iter = 0; iter < qsize; ++iter)
        {
            int now_y = que.front().first;
            int now_x = que.front().second;
            que.pop();

            for (int i = 0; i < 4; ++i)
            {
                int dy = now_y + rot[i][0];
                int dx = now_x + rot[i][1];

                if (dy < 0 || dy >= N || dx < 0 || dx >= M || check[dy][dx] || !board[dy][dx])
                    continue;

                check[dy][dx] = true;
                que.push(make_pair(dy, dx));
            }
        }
    }
    answer = max(answer, ans);
}

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (board[i][j])
                BFS(i, j);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        for (int j = 0; j < M; ++j)
            board[i][j] = str[j] == 'L' ? true : false;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}