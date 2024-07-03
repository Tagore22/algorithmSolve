#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// 풀이가 거의 역대급으로 길었다. 그말은 매우 세심함을 필요로 한다는 점이다. 그래서 꽤나 오래 걸렸다.
// 노가다에 가까운 문제다. 요령도 없이 그저 문제에서 주어지는 것을 그대로 구현해야 한다. 간략하게 설명하자면 다음과 같다.

// 1. M에서 시작하므로 M의 위치를 찾는다. 
// 2. M에서 연결된 파이프의 위치 from를 찾는다. 무조건 M에서 Z로 이어지기 때문에 M에서 시작되는 파이프는 무조건 1개이다.
// 3. from에서 길이 끊긴 즉, board[i][j]가 '.'인 위치 to의 위치를 찾는다. 이때 주어진 파이프의 모양대로 움직여야 한다.
// 4. to에서 4방향을 순회하며 to와 연결된 파이프들의 수를 찾는다. 한군데라면 그 위치에 따른 모양을 찾아야하고,
// 여러군데라면(무조건 3군데) 무조건 +이다.

// 위 설명도 매우 간단하게 압축한것이다. 자세한 설명은 주석으로 남긴다.

char board[25][25];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
pair<int, int> M, Z, from, to;
bool check[25][25] = { false, };
int R, C;

// 1. 시작점(Z에서 출발하는)을 찾는다.
// 2. BFS로 쭉 돈다. 이때 Z에 도달하면 continue를 통해서 무시하며
// 결과적으로 길이 끊긴 곳을 찾으면 BFS를 빠져나온다.
// 3. 8방향을 돌아가며 연결될수 있는곳을 찾는다.


// from에서 시작하여 to를 찾는 함수.
void BFS()
{
    queue<pair<int, int>> que;
    que.push(from);
    check[from.first][from.second] = true;
    check[M.first][M.second] = true;
    check[Z.first][Z.second] = true;

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        // from의 파이프에 따라 이동해야할 방향이 바뀐다. 이것을 배열화하기도 힘드므로 상술하였듯 노가다에 가까운
        // 수작업들을 해야만 했다.
        if (board[y][x] == '|')
        {
            pair<int, int> cur[2] = { {y - 1, x}, {y + 1, x} };
            for (int i = 0; i < 2; ++i)
            {
                int ny = cur[i].first;
                int nx = cur[i].second;
                // 배열값을 벗어나거나 이미 방문한 곳이라면 무시한다.
                if (ny < 0 || ny >= R || check[ny][nx])
                    continue;
                // 길이 끊긴 곳이라면 이곳이 텅 빈 위치이므로 이전값과 현재값을 저장후 탈출한다.
                if (board[ny][nx] == '.')
                {
                    from = make_pair(y, x);
                    to = make_pair(ny, nx);
                    return;
                }
                // 그렇지 않다면 큐에 저장하고 다시 순회한다.
                else
                {
                    que.push(make_pair(ny, nx));
                    check[ny][nx] = true;
                }
            }
        }
        // 다른 모양들도 위와 다를바 없다. 다만 방향이 모두 다르다.
        else if (board[y][x] == '-')
        {
            pair<int, int> cur[2] = { {y, x - 1}, {y, x + 1} };
            for (int i = 0; i < 2; ++i)
            {
                int ny = cur[i].first;
                int nx = cur[i].second;
                if (nx < 0 || nx >= C || check[ny][nx])
                    continue;
                if (board[ny][nx] == '.')
                {
                    from = make_pair(y, x);
                    to = make_pair(ny, nx);
                    return;
                }
                else
                {
                    que.push(make_pair(ny, nx));
                    check[ny][nx] = true;
                }
            }
        }
        else if (board[y][x] == '+')
        {
            pair<int, int> cur[4] = { {y, x - 1}, {y, x + 1}, {y - 1, x}, {y + 1, x} };
            for (int i = 0; i < 4; ++i)
            {
                int ny = cur[i].first;
                int nx = cur[i].second;
                if (ny < 0 || ny >= R || nx < 0 || nx >= C || check[ny][nx])
                    continue;
                if (board[ny][nx] == '.')
                {
                    from = make_pair(y, x);
                    to = make_pair(ny, nx);
                    return;
                }
                else
                {
                    que.push(make_pair(ny, nx));
                    check[ny][nx] = true;
                }
            }
        }
        else if (board[y][x] == '1')
        {
            pair<int, int> cur[2] = { {y, x + 1}, {y + 1, x} };
            for (int i = 0; i < 2; ++i)
            {
                int ny = cur[i].first;
                int nx = cur[i].second;
                if (ny < 0 || ny >= R || nx < 0 || nx >= C || check[ny][nx])
                    continue;
                if (board[ny][nx] == '.')
                {
                    from = make_pair(y, x);
                    to = make_pair(ny, nx);
                    return;
                }
                else
                {
                    que.push(make_pair(ny, nx));
                    check[ny][nx] = true;
                }
            }
        }
        else if (board[y][x] == '2')
        {
            pair<int, int> cur[2] = { {y - 1, x}, {y, x + 1} };
            for (int i = 0; i < 2; ++i)
            {
                int ny = cur[i].first;
                int nx = cur[i].second;
                if (ny < 0 || ny >= R || nx < 0 || nx >= C || check[ny][nx])
                    continue;
                if (board[ny][nx] == '.')
                {
                    from = make_pair(y, x);
                    to = make_pair(ny, nx);
                    return;
                }
                else
                {
                    que.push(make_pair(ny, nx));
                    check[ny][nx] = true;
                }
            }
        }
        else if (board[y][x] == '3')
        {
            pair<int, int> cur[2] = { {y - 1, x}, {y, x - 1} };
            for (int i = 0; i < 2; ++i)
            {
                int ny = cur[i].first;
                int nx = cur[i].second;
                if (ny < 0 || ny >= R || nx < 0 || nx >= C || check[ny][nx])
                    continue;
                if (board[ny][nx] == '.')
                {
                    from = make_pair(y, x);
                    to = make_pair(ny, nx);
                    return;
                }
                else
                {
                    que.push(make_pair(ny, nx));
                    check[ny][nx] = true;
                }
            }
        }
        else if (board[y][x] == '4')
        {
            pair<int, int> cur[2] = { {y + 1, x}, {y, x - 1} };
            for (int i = 0; i < 2; ++i)
            {
                int ny = cur[i].first;
                int nx = cur[i].second;
                if (ny < 0 || ny >= R || nx < 0 || nx >= C || check[ny][nx])
                    continue;
                if (board[ny][nx] == '.')
                {
                    from = make_pair(y, x);
                    to = make_pair(ny, nx);
                    return;
                }
                else
                {
                    que.push(make_pair(ny, nx));
                    check[ny][nx] = true;
                }
            }
        }
    }
}

void MakeAnswer()
{
    int y = M.first;
    int x = M.second;
    // M과 연결된 파이프의 위치 from를 찾는다. 4방향을 순회한다. 무조건 한군데만 연결되어 있다.
    // Z까지 무조건 연결되어 있다고 문제에 제시되어있기 때문이다.
    if (x - 1 >= 0 && (board[y][x - 1] == '-' || board[y][x - 1] == '+' ||
        board[y][x - 1] == '1' || board[y][x - 1] == '2'))
        from = make_pair(y, x - 1);
    else if (y - 1 >= 0 && (board[y - 1][x] == '|' || board[y - 1][x] == '+' ||
        board[y - 1][x] == '1' || board[y - 1][x] == '4'))
        from = make_pair(y - 1, x);
    else if (x + 1 < C && (board[y][x + 1] == '-' || board[y][x + 1] == '+' ||
        board[y][x + 1] == '3' || board[y][x + 1] == '4'))
        from = make_pair(y, x + 1);
    else if (y + 1 < R && (board[y + 1][x] == '|' || board[y + 1][x] == '+' ||
        board[y + 1][x] == '2' || board[y + 1][x] == '3'))
        from = make_pair(y + 1, x);

    // from에서 텅 빈 위치 to를 찾는 순회를 시작한다.
    BFS();

    // to에서 4방향을 순회하며 to의 위치와 연결된 파이프의 수를 찾는다. 무조건 1 아니면 3이다.
    pair<char, int> answer = make_pair(0, 0);
    // 좌측에서 올때.
    if (from.first == to.first && from.second + 1 == to.second)
    {
        int y = to.first;
        int x = to.second;
        // 위쪽
        if (y - 1 >= 0 && (board[y - 1][x] == '|' || board[y - 1][x] == '+' ||
            board[y - 1][x] == '1' || board[y - 1][x] == '4'))
            answer = make_pair('3', answer.second + 1);
        // 아래쪽
        if (y + 1 < R && (board[y + 1][x] == '|' || board[y + 1][x] == '+' ||
            board[y + 1][x] == '2' || board[y + 1][x] == '3'))
            answer = make_pair('4', answer.second + 1);
        // 오른쪽
        if (x + 1 < C && (board[y][x + 1] == '-' || board[y][x + 1] == '+' ||
            board[y][x + 1] == '3' || board[y][x + 1] == '4'))
            answer = make_pair('-', answer.second + 1);
    }
    // 우측에서 올때.
    else if (from.first == to.first && from.second - 1 == to.second)
    {
        int y = to.first;
        int x = to.second;
        // 위쪽
        if (y - 1 >= 0 && (board[y - 1][x] == '|' || board[y - 1][x] == '+' ||
            board[y - 1][x] == '1' || board[y - 1][x] == '4'))
            answer = make_pair('2', answer.second + 1);
        // 아래쪽
        if (y + 1 < R && (board[y + 1][x] == '|' || board[y + 1][x] == '+' ||
            board[y + 1][x] == '2' || board[y + 1][x] == '3'))
            answer = make_pair('1', answer.second + 1);
        // 왼쪽
        if (x - 1 >= 0 && (board[y][x - 1] == '-' || board[y][x - 1] == '+' ||
            board[y][x - 1] == '1' || board[y][x - 1] == '2'))
            answer = make_pair('-', answer.second + 1);
    }
    // 위쪽에서 올때
    else if (from.first + 1 == to.first && from.second == to.second)
    {
        int y = to.first;
        int x = to.second;
        // 왼쪽
        if (x - 1 >= 0 && (board[y][x - 1] == '-' || board[y][x - 1] == '+' ||
            board[y][x - 1] == '1' || board[y][x - 1] == '2'))
            answer = make_pair('3', answer.second + 1);
        // 아래쪽
        if (y + 1 < R && (board[y + 1][x] == '|' || board[y + 1][x] == '+' ||
            board[y + 1][x] == '2' || board[y + 1][x] == '3'))
            answer = make_pair('|', answer.second + 1);
        // 오른쪽
        if (x + 1 < C && (board[y][x + 1] == '-' || board[y][x + 1] == '+' ||
            board[y][x + 1] == '3' || board[y][x + 1] == '4'))
            answer = make_pair('2', answer.second + 1);
    }
    // 아래에서 올때
    else if (from.first - 1 == to.first && from.second == to.second)
    {
        int y = to.first;
        int x = to.second;
        // 왼쪽
        if (x - 1 >= 0 && (board[y][x - 1] == '-' || board[y][x - 1] == '+' ||
            board[y][x - 1] == '1' || board[y][x - 1] == '2'))
            answer = make_pair('4', answer.second + 1);
        // 위쪽
        if (y - 1 >= 0 && (board[y - 1][x] == '|' || board[y - 1][x] == '+' ||
            board[y - 1][x] == '1' || board[y - 1][x] == '4'))
            answer = make_pair('|', answer.second + 1);
        // 오른쪽
        if (x + 1 < C && (board[y][x + 1] == '-' || board[y][x + 1] == '+' ||
            board[y][x + 1] == '3' || board[y][x + 1] == '4'))
            answer = make_pair('1', answer.second + 1);
    }
    answer.first = answer.second == 3 ? '+' : answer.first;
    cout << to.first + 1 << ' ' << to.second + 1 << ' ' << answer.first << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C;
    string str;
    for (int i = 0; i < R; ++i)
    {
        cin >> str;
        for (int j = 0; j < C; ++j)
        {
            board[i][j] = str[j];
            if (board[i][j] == 'M')
                M = make_pair(i, j);
            else if (board[i][j] == 'Z')
                Z = make_pair(i, j);
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}