#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 풀이.
// 삼성 문제답게 어렵지는 않으나 복잡하게 덕지덕지 여러 방식을 엮어놨다.
// 간략하게 말하자면 백트래킹으로 바이러스의 시작좌표 M개를 구한후 각 상황에서 배열의 빈칸을 바이러스로 덮는 최소한의 시간을
// 구하는 문제이다. 즉, 백트래킹으로 좌표값들을 구한후 그 모든 상황에서 BFS의 최소값을 구하면 된다.
// 다만 조심해야할 부분이 있는데, 현재 비활성화 바이러스의 위치는 빈칸이 아니기 때문에 이곳이 마지막 위치라면 덮지 않고
// 그 이전에 끝나야 된다는 것이다. 이 점이 꽤나 애매한 부분인데 BFS를 한단계 진행할때마다 현재 빈칸이 있는지 확인을 해야한다는 것이다.
// 덕분에 풀긴했으나, 시간이 200ms를 넘어섰다. 다른 풀이를 참조했는데 그 풀이에는 아예 빈칸의 수를 구해놓고, BFS진행시 빈칸을 덮는 경우
// 에 그 빈칸의 수를 하나씩 줄여갔다. while문의 조건문에도 빈칸의 수가 0보다 작을 경우는 무시하게 하여 매번 빈칸의 수를 구해야하는
// 시간을 아낄수 있었다.

vector<vector<int>> board, temp;
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // 좌 상 우 하.
vector<pair<int, int>> virus, virus_from;
const int MAX_NUM = 987654321;
int N, M, answer = MAX_NUM, total_zero = 0; // 빈칸의 수. 이번 문제풀이의 속도를 올리는데 핵심 부분이었다.

bool FuncRound()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (board[i][j] == 0)
                return false;
    return true;
}

int BFS()
{
    board = temp;
    queue<pair<int, int>> que;
    for (int i = 0; i < virus_from.size(); ++i)
    {
        que.push(virus_from[i]);
        board[virus_from[i].first][virus_from[i].second] = 3;
    }

    int dy, dx, y, x, ans = 0, Qsize, zero = total_zero;
    while (!que.empty() && zero > 0)
    {
        if (ans >= answer)
            break;
        ++ans;

        Qsize = que.size();
        for (int iter = 0; iter < Qsize; ++iter)
        {
            y = que.front().first;
            x = que.front().second;
            que.pop();

            for (int i = 0; i < 4; ++i)
            {
                dy = y + rot[i][0];
                dx = x + rot[i][1];

                if (dy < 0 || dy >= N || dx < 0 || dx >= N || board[dy][dx] == 1
                    || board[dy][dx] == 3 || board[dy][dx] == 4)
                    continue;

                if (board[dy][dx] == 0)
                    --zero;

                board[dy][dx] = 4;
                que.push(make_pair(dy, dx));
            }
        }
    }
    if (FuncRound())
        return ans;
    else
        return MAX_NUM;
}

void BackTrack(int idx, int num)
{
    if (num == M)
    {
        answer = min(answer, BFS());
        return;
    }

    for (int i = idx + 1; i < virus.size(); ++i)
    {
        virus_from.push_back(virus[i]);
        BackTrack(i, num + 1);
        virus_from.pop_back();
    }
}

void MakeAnswer()
{
    BackTrack(-1, 0);

    cout << (answer == MAX_NUM ? -1 : answer) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    board.resize(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 2)
                virus.push_back(make_pair(i, j));
            else if (board[i][j] == 0)
                ++total_zero;
        }
    temp = board;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}