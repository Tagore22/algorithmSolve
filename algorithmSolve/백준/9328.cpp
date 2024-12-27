#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// 엄청 어려운 문제였다. 달이 차오른다 문제와 비슷한 느낌이었는데 한가지 다른점은 키가 너무 많아서 비트마스크로 처리할수
// 없었다. 그래서 string을 이용하여 중복 탐색을 막으려고 노력했으나 시간초과로 실패했다. 제대로 된 풀이는 BFS의 BFS였다.
// 한번의 BFS에서 현재 키로 도달할수 있는 모든 곳을 순회하여 열쇠를 가지고 있지 않아 나아갈수 없는 지점을 저장해두고,
// 새로 얻은 키를 수정해놓는다. 그 이후 키를 순회하여 새롭게 도달할수 있는 문부터 다시 BFS를 호출한다. 이렇게 하면
// 기존에 도달할수 없었던 지점만 새롭게 순회를 하게 되어 결국 한번의 BFS와 같은 수의 연산만을 하게 된다.

// 자세한 설명은 주석으로 남긴다.

int T, H, W;
char board[102][102];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
bool visit[102][102] = { false, };
string key;
// 각 순회에서 도달할수 없는 문의 위치를 저장하는 queue. 도달할수 있게 되면 삭제해주어야 하기 때문에
// queue로 구현하였다.
queue<pair<int, int>> door;
int answer = 0;

// 현재 가진 키들로 해당 문을 방문할수 있는지 확인하는 함수.
bool CheckKey(string key, char c)
{
    for (int i = 0; i < key.size(); ++i)
        if (key[i] == c + 32)
            return true;
    return false;
}

void BFS(int y, int x)
{
    queue<pair<int, int>> que;
    que.push(make_pair(y, x));
    visit[y][x] = true;

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + rot[i][0];
            int nx = x + rot[i][1];

            // 범위값을 벗어났거나, 벽이거나, 중복방문이라면 무시한다.
            if (ny < 0 || ny >= H + 2 || nx < 0 || nx >= W + 2 || board[ny][nx] == '*' ||
                visit[ny][nx])
                continue;

            // 새로운 지점이 열쇠일때.
            if ('a' <= board[ny][nx] && board[ny][nx] <= 'z')
            {
                // 이미 가진 열쇠인지 확인하여 가지고 있지 않은 경우에만 추가한다.
                bool isfind = false;
                for (int f = 0; f < key.size(); ++f)
                    if (key[f] == board[ny][nx])
                    {
                        isfind = true;
                        break;
                    }
                key = isfind ? key : key + board[ny][nx];
            }
            // 문일때.
            else if ('A' <= board[ny][nx] && board[ny][nx] <= 'Z')
            {
                // 키가 없어 방문하지 못한다면 door에 추가하고 무시한다.
                if (!CheckKey(key, board[ny][nx]))
                {
                    door.push(make_pair(ny, nx));
                    continue;
                }
            }
            // $이라면 값을 1늘려준다.
            answer = board[ny][nx] == '$' ? answer + 1 : answer;
            que.push(make_pair(ny, nx));
            visit[ny][nx] = true;
        }
    }
}

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        // 값들의 초기화. 테스트 케이스가 존재하기에 필수이다.
        answer = 0;
        while (!door.empty())
            door.pop();
        for (int i = 0; i < 102; ++i)
            for (int j = 0; j < 102; ++j)
                visit[i][j] = false;
        cin >> H >> W;
        // 건물밖으로 나가서 다른 입구로 도달하는 방법도 존재하기 때문에
        // 배열값을 좌우상하 1씩 늘려 지나갈수 있는 통로를 만들어야한다.
        for (int i = 0; i < H + 2; ++i)
        {
            board[i][0] = '.';
            board[i][W + 1] = '.';
        }
        for (int i = 0; i < W + 2; ++i)
        {
            board[0][i] = '.';
            board[H + 1][i] = '.';
        }
        string str;
        for (int i = 1; i <= H; ++i)
        {
            cin >> str;
            for (int j = 0; j < W; ++j)
                board[i][j + 1] = str[j];
        }
        cin >> key;
        key = key == "0" ? "" : key;

        queue<pair<int, int>> que;
        que.push(make_pair(0, 0));

        while (!que.empty())
        {
            int y = que.front().first;
            int x = que.front().second;
            que.pop();
            BFS(y, x);

            // 도달하지 못했던 문들중 새롭게 얻은 키로 갈수 있다면 que에 추가하고
            // door에서 제외시킨다.
            int dsize = door.size();
            for (int d = 0; d < dsize; ++d)
            {
                pair<int, int> here = door.front();
                door.pop();
                char pos = board[here.first][here.second];

                bool isfind = false;
                for (int u = 0; u < key.size(); ++u)
                {
                    if (key[u] == pos + 32)
                    {
                        isfind = true;
                        break;
                    }
                }
                if (isfind)
                    que.push(here);
                else
                    door.push(here);
            }
        }
        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}