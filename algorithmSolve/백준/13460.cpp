#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

//���������� �Ķ� ������ �� �Ʒ� �� ��� �̵���ų�� �ִ� �ִ��� ���������鼭 ���� ������ ���ۿ� �����ϴ� �ּҰ��� ���Ѵ� �����ε�
//������ �߸����� �ִ��� �����̴°� �ƴ� 1ĭ�� �����ϼ� �ִ°����� �����Ͽ� ������ ��ž���.
//�������� ������ ��������.
//����Ͽ����� 2���� ������ �� ���⺰�� �ִ��� �������� �ϴµ�, �����ؾ��Ұ��� �� ������ ��ġ�� ������ ���̴�.
//�����δ� ��ĥ���� ���⿡ �� ������ �̵��Ÿ��� ���� ����Ͽ� �Ÿ��� ������ ��ġ�� �Ѵܰ� ������ ȸ�ͽ�Ų��.
//����, ���� ������ ���ۿ� �����Ͽ��� �Ķ� ���� ���� �����Ͽ��ٸ� �� �̵���ü�� ���ܽ��Ѿ� �Ѵ�.

constexpr int MAX_BOARD = 10;
char board[MAX_BOARD][MAX_BOARD];
bool visit[10][10][10][10];
int N, M;
pair<int, int> red, blue, goal;
int dy[4] = { 0,-1,0,1 };
int dx[4] = { -1,0,1,0 };

void move(int& y, int& x, int& dis, int idx)
{
    while (board[y + dy[idx]][x + dx[idx]] != '#' && board[y][x] != 'O')
    {
        y += dy[idx];
        x += dx[idx];
        ++dis;
    }
}

void BFS()
{
    queue<pair<pair<int, int>, pair<int, int>>> que;
    que.push(make_pair(red, blue));
    visit[red.first][red.second][blue.first][blue.second] = true;
    int num = 0;
    while (!que.empty())
    {
        int iter = que.size();
        for (int i = 0; i < iter; ++i)
        {

            pair<int, int> r = make_pair(que.front().first.first, que.front().first.second);
            pair<int, int> b = make_pair(que.front().second.first, que.front().second.second);
            que.pop();

            if (num >= 10)
                break;

            for (int i = 0; i < 4; ++i)
            {
                pair<int, int> next_r = r;
                pair<int, int> next_b = b;
                int r_count = 0;
                int b_count = 0;

                move(next_r.first, next_r.second, r_count, i);
                move(next_b.first, next_b.second, b_count, i);

                if (board[next_b.first][next_b.second] == 'O')
                    continue;
                if (board[next_r.first][next_r.second] == 'O')
                {
                    cout << num + 1 << '\n';
                    return;
                }
                if (next_b == next_r)
                {
                    if (r_count > b_count)
                    {
                        next_r.first -= dy[i];
                        next_r.second -= dx[i];
                    }
                    else
                    {
                        next_b.first -= dy[i];
                        next_b.second -= dx[i];
                    }
                }
                if (!visit[next_r.first][next_r.second][next_b.first][next_b.second])
                {
                    visit[next_r.first][next_r.second][next_b.first][next_b.second] = true;
                    que.push(make_pair(next_r, next_b));
                }
            }
        }
        ++num;
    }
    cout << -1 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(visit, false, sizeof(visit));

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 'R')
            {
                red = make_pair(i, j);
                board[i][j] == '.';
            }
            else if (board[i][j] == 'B')
            {
                blue = make_pair(i, j);
                board[i][j] = '.';
            }
        }
}

int main()
{
    Input();
    BFS();
    return 0;
}