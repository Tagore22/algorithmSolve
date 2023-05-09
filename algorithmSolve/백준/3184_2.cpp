#include <iostream>
#include <queue>

using namespace std;

// 3184번의 BFS풀이.
// 앞서 말했듯 재귀횟수가 늘어나 BFS가 오히려 더 가벼워졌다.

char board[250][250];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // 좌 상 우 하.
int R, C, total_w = 0, total_s = 0, cur_w, cur_s;

void BFS(int y, int x)
{
    queue<pair<int, int>> que;
    que.push(make_pair(y, x));
    if (board[y][x] == 'o')
        ++cur_s;
    else if (board[y][x] == 'v')
        ++cur_w;
    board[y][x] = '#';

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i)
        {
            int dy = y + rot[i][0];
            int dx = x + rot[i][1];

            if (dy < 0 || dy >= R || dx < 0 || dx >= C || board[dy][dx] == '#')
                continue;

            que.push(make_pair(dy, dx));
            if (board[dy][dx] == 'o')
                ++cur_s;
            else if (board[dy][dx] == 'v')
                ++cur_w;
            board[dy][dx] = '#';
        }
    }
}

void MakeAnswer()
{
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (board[i][j] != '#')
            {
                cur_w = cur_s = 0;
                BFS(i, j);
                if (cur_w < cur_s)
                    total_s += cur_s;
                else
                    total_w += cur_w;
            }

    cout << total_s << ' ' << total_w << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C;
    string str;
    for (int i = 0; i < R; ++i)
    {
        cin >> str;
        for (int j = 0; j < C; ++j)
            board[i][j] = str[j];
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}