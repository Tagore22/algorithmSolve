#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 풀이.
// 언젠가 풀어봤던 문제의 진화형이다. 다만 그 문제에는 불과 사람의 이동에 관한 조건이 있었는데
// 이번엔 그런게 없어서 헤맬뻔했다. 저번처럼 불이 먼저 움직여야하는데
// 예를 들어 불이 먼저 이동한 곳엔 사람이 도달할수 없지만 사람이 먼저 도달한 곳에
// 불이 도달하는건 가능한데 이건 답이 될수 없기 때문이다.

// 또한 주의해야 할점은 불은 이동 조건에 불 혹은 벽인 곳은 갈수 없기에 불인 곳을 또다시 갈수 없으나,
// 사람은 따로 방문 여부를 체크해야 갔던곳을 또다시 가지 않는다.

// 자세한 설명은 주석으로 남긴다.

char board[1000][1000];
int R, C;
pair<int, int> start;
vector<pair<int, int>> f;
vector<vector<bool>> visit;
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // 좌 상 우 하.

// 불과 사람이 이동하며 탈출여부 혹은 탈출시간을 반환하는 함수.
int BFS()
{
    visit.resize(R, vector<bool>(C, false));
    int answer = 0;
    queue<pair<int, int>> man, fire;
    man.push(start);
    visit[start.first][start.second] = true;
    for (int i = 0; i < f.size(); ++i)
        fire.push(f[i]);

    while (!man.empty())
    {
        // 상술하였듯 불이 먼저 움직여야한다.
        ++answer;
        int fsize = fire.size();
        for (int i = 0; i < fsize; ++i)
        {
            int y = fire.front().first;
            int x = fire.front().second;
            fire.pop();

            for (int j = 0; j < 4; ++j)
            {
                int dy = y + rot[j][0];
                int dx = x + rot[j][1];

                if (dy < 0 || dy >= R || dx < 0 || dx >= C || board[dy][dx] == '#' ||
                    board[dy][dx] == 'F')
                    continue;

                board[dy][dx] = 'F';
                fire.push(make_pair(dy, dx));
            }
        }

        // 사람의 이동.
        int msize = man.size();
        for (int i = 0; i < msize; ++i)
        {
            int y = man.front().first;
            int x = man.front().second;
            man.pop();
            
            // 가장자리에 도달하였다면 탈출.
            if (y == 0 || y == R - 1 || x == 0 || x == C - 1)
                return answer;

            for (int j = 0; j < 4; ++j)
            {
                int dy = y + rot[j][0];
                int dx = x + rot[j][1];

                if (dy < 0 || dy >= R || dx < 0 || dx >= C || board[dy][dx] == '#' ||
                    board[dy][dx] == 'F' || visit[dy][dx])
                    continue;

                visit[dy][dx] = true;
                man.push(make_pair(dy, dx));
            }
        }
    }
    return 987654321;
}

void MakeAnswer()
{
    int answer = BFS();

    if (answer == 987654321)
        cout << "IMPOSSIBLE" << '\n';
    else
        cout << answer << '\n';
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
        {
            board[i][j] = str[j];
            if (board[i][j] == 'J')
                start = make_pair(i, j);
            else if (board[i][j] == 'F')
                f.push_back(make_pair(i, j));
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}