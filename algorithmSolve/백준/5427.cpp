#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

// 풀이.
// 처음에 DFS로 풀고 싶어서 시간만 한참 날린 문제다.
// 최단거리이기에 결과적으로 BFS로 푸는게 맞는데 괜한 억지를 부렸다.

// 이 문제는 시뮬레이션 문제와 비슷한데 큰틀을 보자면 다음과 같다.

// 1. 불이 먼저 4방향을 기준으로 움직일수 있는 곳으로 움직인다.
// 2. 사람도 마찬가지로 4방향을 기준으로 움직일수 있는 곳으로 움직인다.
// 3. 사람의 위치가 배열값을 벗어나는 경우 그 값을 출력하고 아예 벗어나지 못한다면 문자열을 출력한다.

// 불이 먼저 움직여야 하는 이유는 다음과 같다.

// 1. 불은 사람이 있는 곳도 움직일수 있다. 즉, 다음 좌표가 불이거나 벽이 아니라면 아무곳이나 움직일 수 있다.
// 2. 사람은 불이 다음번에 움직일 좌표로는 갈수 없다. 그렇기에 불이 먼저 움직이고 사람이 움직인다면 이 원리에 알맞다.

// 이 원리에 따라 구현하여 최종값을 출력하면 된다.
// 자세한 설명은 주석으로 남긴다.

// P.S 주석으로 가려진 부분은 기존에 불의 이동을 구현했던 함수다.
// 이 함수를 사용하여 불을 이동시키면 시간 초과가 뜬다. 불의 이동은 최대 100만번 일어나기에
// 매번 최대 100만번(배열의 최대 크기)의 이동을 다시 최대 100만번(최대 불의 이동횟수)하기 때문이다.
// 따라서 불의 이동 역시 BFS에 포함시킨다면 매번 최대 100만번(배열의 최대 크기)를 순회할 필요없이
// 최대 100만번(최대 불의 이동횟수)만 불을 이동시키면 된다.

char board[1000][1000];
bool visit[1000][1000];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // 좌 상 우 하.
int T, W, H;
pair<int, int> cur_pos;

/*void MoveFire()
{
    vector<pair<int, int>> next_fire;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            if (board[i][j] == '*')
                next_fire.push_back(make_pair(i, j));

    for (int i = 0; i < next_fire.size(); ++i)
    {
        int y = next_fire[i].first;
        int x = next_fire[i].second;

        for (int iter = 0; iter < 4; ++iter)
        {
            int dy = y + rot[iter][0];
            int dx = x + rot[iter][1];

            if (dy < 0 || dy >= H || dx < 0 || dx >= W || board[dy][dx] == '#' || board[dy][dx] == '*')
                continue;

            board[dy][dx] = '*';
        }
    }
}*/

int BFS(const vector<pair<int, int>>& fires)
{
    queue<pair<int, int>> que, fire;
    que.push(cur_pos);
    for (int i = 0; i < fires.size(); ++i)
        fire.push(make_pair(fires[i].first, fires[i].second));
    memset(visit, false, sizeof(visit));
    visit[cur_pos.first][cur_pos.second] = true;
    int answer = -1;

    while (!que.empty())
    {
        // 상술하였듯 불이 먼저 이동한다. 불은 최대 100만번 이동하기에
        // 아래 for문은 최대 100만번 실행된다.
        int fsize = fire.size();
        for (int iter = 0; iter < fsize; ++iter)
        {
            int y = fire.front().first;
            int x = fire.front().second;
            fire.pop();

            for (int i = 0; i < 4; ++i)
            {
                int dy = y + rot[i][0];
                int dx = x + rot[i][1];

                if (dy < 0 || dy >= H || dx < 0 || dx >= W || board[dy][dx] == '#' || board[dy][dx] == '*')
                    continue;

                board[dy][dx] = '*';
                fire.push(make_pair(dy, dx));
            }
        }

        // 그 다음 사람의 이동이다. 사람의 이동은 중복이 없기에
        // 최대 100만번 일어난다. 따라서 BFS는 최대 200만번의 연산량을 차지한다.
        int qsize = que.size();
        ++answer;
        for (int iter = 0; iter < qsize; ++iter)
        {
            int y = que.front().first;
            int x = que.front().second;
            que.pop();

            if (y < 0 || y >= H || x < 0 || x >= W)
                return answer;

            for (int i = 0; i < 4; ++i)
            {
                int dy = y + rot[i][0];
                int dx = x + rot[i][1];

                if ((dy >= 0 && dy < H && dx >= 0 && dx < W) && (board[dy][dx] == '#' || board[dy][dx] == '*' ||
                    visit[dy][dx]))
                    continue;

                que.push(make_pair(dy, dx));
                visit[dy][dx] = true;
            }
        }
    }
    return 987654321;
}

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> W >> H;
        vector<pair<int, int>> fires;
        string str;
        for (int i = 0; i < H; ++i)
        {
            cin >> str;
            for (int j = 0; j < W; ++j)
            {
                board[i][j] = str[j];
                if (board[i][j] == '@')
                    cur_pos = make_pair(i, j);
                else if (board[i][j] == '*')
                    fires.push_back(make_pair(i, j));
            }
        }

        int answer = BFS(fires);

        if (answer != 987654321)
            cout << answer << '\n';
        else
            cout << "IMPOSSIBLE" << '\n';
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