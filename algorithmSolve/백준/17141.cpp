#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// 어렵진 않지만 여러가지 제약이 덕지덕지 묶여있어 사소한 실수에도 주의를 요하는 문제다.
// 하나하나 설명하자면 불필요하게 길어지니 따로 주석을 이용해야겠다.
// 늦게 일어나서 그냥 실버나 -브-를 풀까도 했지만 그래도 이겨냈다.

// 자세한 설명은 주석으로 남긴다.

int board[50][50], rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
// 바이러스를 풀수 있는 위치들.
pair<int, int> pos[10];
// 현재 골라진 위치들.
deque<int> cur;
bool check[50][50];
int N, M, answer = 987654321, idx = 0;

// 모든 칸에 바이러스가 닿았는지 확인하는 함수.
bool CheckVirus()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (!check[i][j])
                return false;
    return true;
}

// 바이러스들의 위치가 정해졌을때 모든 칸에 도달하는 시간을 구하는 함수.
void BFS()
{
    queue<pair<int, int>> que;
    // 벽으로 되어있는 칸은 방문할수가 없기에 순회전 미리 방문했다고 처리해야한다.
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            check[i][j] = board[i][j] == 1 ? true : false;
    // 미리 정해진 바이러스의 위치들을 큐에 넣고 방문여부를 체크한다.
    for (int i = 0; i < M; ++i)
    {
        que.push(make_pair(pos[cur[i]].first, pos[cur[i]].second));
        check[pos[cur[i]].first][pos[cur[i]].second] = true;
    }
    int ans = -1;

    while (!que.empty())
    {
        ++ans;
        // 바이러스는 매 시간마다 동시에 움직인다. 따라서 이곳에서 확인해도 상관없고
        // 아래 for문 아래에서 확인해도 상관은 없으나, 여기에서 확인하는것이 더 빈도수를
        // 줄여서 속도를 상향시킬수 있다.
        if (CheckVirus())
        {
            answer = min(answer, ans);
            return;
        }
        // 상술하였듯 바이러스는 매 시간마다 동시에 움직이기에 현재 que에 담겨있는 원소들만
        // 이동시켜야 한다.
        int qsize = que.size();
        for (int iter = 0; iter < qsize; ++iter)
        {
            int y = que.front().first;
            int x = que.front().second;
            que.pop();

            // 4방향으로 모두 이동시킨다.
            for (int i = 0; i < 4; ++i)
            {
                int ny = y + rot[i][0];
                int nx = x + rot[i][1];

                // 배열값을 벗어났거나 이미 방문한 위치라면 무시한다.
                // 다른 문제라면 이동할 위치가 벽인가에 대한 조건도 넣어야했겠으나
                // 상술하였듯 벽은 아예 바이러스가 도달할수 없어 미리 방문체크를 해놓았다.
                // 그렇기 때문에 방문여부만 확인해도 벽까지 함께 걸러낼수 있다.
                if (ny < 0 || ny >= N || nx < 0 || nx >= N || check[ny][nx])
                    continue;

                que.push(make_pair(ny, nx));
                check[ny][nx] = true;
            }
        }
    }
}

// 모든 바이러스들의 위치를 골라보는 함수.
void BackTrack(int prev, int num)
{
    // M개를 모두 골랐다면 BFS 순회를 시작하여 시간을 계산해본다.
    if (num == M)
    {
        BFS();
        return;
    }

    // 중복을 걸러내기 위해 이전값 + 1의 위치부터 시작한다.
    for (int i = prev + 1; i < idx; ++i)
    {
        // 이곳에서 deque에 고른 바이러스의 인덱스값을 넘긴다.
        cur.push_back(i);
        BackTrack(i, num + 1);
        cur.pop_back();
    }
}

void MakeAnswer()
{
    BackTrack(-1, 0);
    // 만약 answer의 값이 변하지 않았다면 모든 경우를 선택해도 바이러스로 채울수 없었기에
    // -1로 값을 수정한다.
    answer = answer == 987654321 ? -1 : answer;
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 2)
                // 현재 위치값이 2라면 바이러스를 놓을수 있는 위치이므로 pos에 추가한다.
                pos[idx++] = make_pair(i, j);
        }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}