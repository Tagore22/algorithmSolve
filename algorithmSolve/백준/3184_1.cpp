#include <iostream>

using namespace std;

// 다시보니 외곽과 통하는 곳을 따로 처리해줄 필요가 없었다.
// 문제 마지막 부분에 모든 양과 늑대는 마당안의 영역에 존재한다고 나와있는데,
// 이것은 다른 말로 마당에서 탈출 가능한 외곽에는 존재하지 않는다는 뜻이기 때문이다.
// 또한 이 풀이는 DFS를 사용하는 풀이인데, 최대 250 * 250 = 62500 만큼의 DFS를 재귀호출할수
// 있기에 잡아먹는 메모리가 BFS풀이의 1.5배에 달한다.
// 재귀횟수가 늘어나면 DFS보다 BFS가 더 가벼워진다는 걸 잊지말자.

char board[250][250];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // 좌 상 우 하.
int R, C, total_w = 0, total_s = 0, cur_w, cur_s;

void DFS(int y, int x)
{
    if (board[y][x] == 'o')
        ++cur_s;
    else if (board[y][x] == 'v')
        ++cur_w;
    board[y][x] = '#';

    for (int i = 0; i < 4; ++i)
    {
        int dy = y + rot[i][0];
        int dx = x + rot[i][1];

        if (dy < 0 || dy >= R || dx < 0 || dx >= C || board[dy][dx] == '#')
            continue;

        DFS(dy, dx);
    }
}

void MakeAnswer()
{
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (board[i][j] != '#')
            {
                cur_w = cur_s = 0;
                DFS(i, j);
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