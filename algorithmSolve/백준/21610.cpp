#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 낯익은 문제였다. 아니 반은 맞은 말인가. 상어 어쩌구 하는 문제는 다 삼성 SW 문제였다.
// 그말은 어렵지 않은 개념이 덕지덕지 살덩이 골렘마냥 기워졌다는 것이었다.
// 실제로 문제가 어렵진 않았으나 여러가지 단계가 존재했으며, 여러가지 제약이 존재했다.
// 다른 삼성 SW문제와 마찬가지로 한번에 설명을 하기는 어려우니 주석으로 설명을 대체한다.

// 자세한 설명은 주석으로 남긴다.

int board[50][50], rot[9][2] = { {0, 0}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1} };
int bug[4][2] = { {-1, -1}, {-1, 1}, {1, 1}, {1, -1} }; // 좌상향부터 시계방향.
vector<pair<int, int>> cloud;
pair<int, int> mov[100];
bool check[50][50];
int N, M;

// 1. 구름이 움직일때 배열값을 벗어나도 반대로 이동된다.
// 2. 구름은 특정 방향(좌우상하 + 대각선)으로 특정값만큼 이동한다.
// 3. 구름이 이동후 각 칸에 물이 1만큼 증가한다.
// 4. 구름이 사라지며 각 칸에 물복사버그가 시행된다. 대각선으로 거리가 1만큼인 바구니중
// 물이 있는 바구니의 수만큼 다시 물이 증가한다. 이때 구름의 이동과는 다르게 배열값을 벗어나는
// 칸들은 무시한다.
// 5. 바구니에 저장된 물의 양이 2이상인 모든 곳에서 그 다음 구름이 발생하며 물의 양이 2씩 줄어든다.
// 다만 이전 구름이 위치했던 곳은 무시한다.

// 물복사버그는 반드시 모든 구름이 이동후 각 칸의 물이 1씩 증가후에 해야한다. 그렇지 않고
// 구름의 한부분이 이동후 물복사버그를 진행하면 제대로 된 답이 나오지 않을것이다.

// 각 구름들의 위치를 이동하는 함수.
void MoveCloud(int idx)
{
    // 기존 구름의 위치는 지우던가 해야하는데 vector를 썼으므로 구현하기 복잡하다.
    // 따라서 대체되는 vector를 하나 더 만들어서 기존의 cloud를 덮어쓴다.
    vector<pair<int, int>> next;
    for (auto a : cloud)
    {
        // 이 부분에 꽤나 중요한 부분이 몇가지 있다.
        // 1. 기존에 좌표 옮기기는 그냥 y + rot[i][0]등으로 하였다. 하지만 이번에는
        // 이동하는 칸의 크기가 단순히 1이 아니기 때문에 그 크기만큼 곱해주어야 한다.
        // 2. 또한 곱할때 N만큼 나누어야 한다. N을 넘어서는 이동은 N으로 나눈 나머지만큼의 이동과 일치하기에
        // 시간을 더 절약할수 있다.
        int ny = a.first + rot[mov[idx].first][0] * (mov[idx].second % N);
        // 이동값이 0보다 작다면 N - 1과 연결되어 있다.
        if (ny < 0)
            ny = N + ny;
        // 이동값이 N보다 크거나 같다면 0과 연결되어 있다.
        else if (ny >= N)
            ny = ny - N;
        int nx = a.second + rot[mov[idx].first][1] * (mov[idx].second % N);
        if (nx < 0)
            nx = N + nx;
        else if (nx >= N)
            nx = nx - N;
        // 새로운 구름값에 저장하고 이곳에서의 구름 생성을 막기 위해 기존 구름의 위치였는가에 대해 체크한다.
        next.push_back(make_pair(ny, nx));
        check[ny][nx] = true;
    }
    cloud = next;
}

// 물복사버그를 구현하는 함수.
int WaterBug(int y, int x)
{
    int ans = 0;
    for (int i = 0; i < 4; ++i)
    {
        // 이곳에서 int ny = bug[i][0]; 이러고 있었다.
        // 복잡해서 실수할뻔했다.
        // 각 대각선의 위치를 구해본다.
        int ny = y + bug[i][0];
        int nx = x + bug[i][1];

        // 구름의 이동과는 달리 이곳에서는 배열값을 벗어나면 무시한다. 또한 도달한 칸의 물의 양이 0이라면
        // 마찬가지로 무시한다.
        if (ny < 0 || ny >= N || nx < 0 || nx >= N || board[ny][nx] == 0)
            continue;
        ++ans;
    }
    return ans;
}

void MakeAnswer()
{
    // 초기 구름의 위치값들.
    cloud.push_back(make_pair(N - 1, 0));
    cloud.push_back(make_pair(N - 1, 1));
    cloud.push_back(make_pair(N - 2, 0));
    cloud.push_back(make_pair(N - 2, 1));
    for (int iter = 0; iter < M; ++iter)
    {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                check[i][j] = false;
        MoveCloud(iter);
        for (auto a : cloud)
            ++board[a.first][a.second];
        for (auto a : cloud)
            board[a.first][a.second] += WaterBug(a.first, a.second);
        cloud.clear();
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (board[i][j] >= 2 && !check[i][j])
                {
                    cloud.push_back(make_pair(i, j));
                    board[i][j] -= 2;
                }
    }
    int answer = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            answer += board[i][j];
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
    for (int i = 0; i < M; ++i)
        cin >> mov[i].first >> mov[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}