#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 4179번의 더 나은 풀이.
// 메모리도 더 적게 차지하고 더 빠르다.
// 기존에는 사람의 중복 방문을 막기 위해 방문 여부를 체크하는 bool형 배열이 있었으나,
// 생각해보면 굳이 필요가 없었다.

// 사람이 방문했던 곳은 'J'가 된다면 사람이든 불이든 방문한 곳은 무조건 'F' 혹은 'J'가 된다.
// 또한, 사람이 움직이는 이동 조건중 하나는 움직이려는 칸의 값이 'J' 혹은 'F'가 아니여야 하므로
// bool 배열을 완벽하게 대체할수 있으며, 생성시 드는 시간 및 차지하는 메모리를 아예 없앨수 있다.

char board[1000][1000];
int R, C;
pair<int, int> start;
vector<pair<int, int>> f;
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // 좌 상 우 하.

int BFS()
{
    int answer = 0;
    queue<pair<int, int>> man, fire;
    man.push(start);
    for (int i = 0; i < f.size(); ++i)
        fire.push(f[i]);

    while (!man.empty())
    {
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

        int msize = man.size();
        for (int i = 0; i < msize; ++i)
        {
            int y = man.front().first;
            int x = man.front().second;
            man.pop();

            if (y == 0 || y == R - 1 || x == 0 || x == C - 1)
                return answer;

            for (int j = 0; j < 4; ++j)
            {
                int dy = y + rot[j][0];
                int dx = x + rot[j][1];

                if (dy < 0 || dy >= R || dx < 0 || dx >= C || board[dy][dx] != '.')
                    continue;

                board[dy][dx] = 'J';
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