#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// 그래프 탐색 및 이론 문제이다.
// 2차원 배열 board를 순회하되, 양이나 늑대가 발견될시 해당 울타리 안을 다시 모두 순회하며 늑대와 양의 수를 센다.
// 늑대가 더 크거나 같다면 늑대가 살아남기에 늑대들의 수를 증가시키고,
// 그렇지 않다면 양의 수를 증가시킨다.

// 자세한 설명은 주석으로 남긴다.

char board[250][250];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // 좌, 상, 우, 하.
int R, C, wolf = 0, sheep = 0;

void BFS(int y, int x)
{
    queue<pair<int, int>> que;
    que.push(make_pair(y, x));
    // 시작지점의 값을 이용하여 늑대와 양의 수를 초기화시킨다.
    int w = 0, s = 0;
    if (board[y][x] == 'v')
        ++w;
    else
        ++s;
    board[y][x] = 'o';

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i)
        {
            int dy = y + rot[i][0];
            int dx = x + rot[i][1];

            // 현재 좌표를 방문하였다면 배열값을 변화시켜서 중복 방문 여부를 체크하는 배열을 대체하였다.
            // 그렇기에 조건문에도 새로운 조건식이 하나 추가되었다.
            if (dy < 0 || dy >= R || dx < 0 || dx >= C || board[dy][dx] == '#' ||
                board[dy][dx] == 'o')
                continue;

            // 현재 울타리의 늑대 및 양의 수를 갱신한다.
            if (board[dy][dx] == 'v')
                ++w;
            else if (board[dy][dx] == 'k')
                ++s;
            board[dy][dx] = 'o';
            que.push(make_pair(dy, dx));
        }
    }
    if (w >= s)
        wolf += w;
    else
        sheep += s;
}

void MakeAnswer()
{
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (board[i][j] == 'v' || board[i][j] == 'k')
                BFS(i, j);

    cout << sheep << ' ' << wolf << '\n';
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