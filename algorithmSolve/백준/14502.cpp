#include <iostream>
#include <vector>

using namespace std;

// 풀이
// 조합과 DFS의 반복을 섞은 문제이다.
// 벽을 칠수 있는 빈공간중 3개를 골라서 벽을 쳤을때 안전공간의 최대값(0의 개수가 가장 많을때)를 구해야한다.
// 우선 작은것부터 하나하나 풀어보았다.

// 1. DFS의 구현
// 2. DFS로 바이러스의 확산 이후 존재하는 안전공간의 크기를 구하는 함수 구현.
// 3. K개의 빈 공간중 3개를 골라서 2번 함수를 호출하는 함수 구현.

// 1번 함수는 기본적인 DFS라 크게 어렵지 않다. 좌우상하로 움직일수 있다고 문제에 나와있기 때문에 4가지 경우에 따라
// 새로운 좌표를 만든후 이동할수 없는 경우(배열을 넘어서는 경우, 벽으로 막혀있거나, 이미 방문했던 경우)를 제외하고
// 다시 재귀형식으로 DFS를 호출하면 된다.

// 2번 함수를 위해서 다음과 같은 2가지가 필요하다.
// 1. 배열을 복사할 vector<vector<int>> temp.
// 2. 처음 입력받을시 값이 2였던 좌표값들을 모아놓은 vector<pair<int, int>> two.

// 벽을 세우는 여러번에 경우마다 DFS를 순회해야하는데, DFS를 돌다보면 바이러스가 확산되는 경우에 의해 기존 배열 board가 
// 변하게 된다. 이를 다시 바이러스 확산전으로 복구 시켜야하는데, 2로 변경시켰던 좌표값을 다시 0으로 변경시키면 안된다. 
// DFS순회중 이미 도달한 곳을 다시 방문할수도 있는데 0으로 다시 변경시켰기에 방문을 이미 했음에도 다시 방문하기 때문이다. 
// 이러한 이유로 아예 2번째 배열을 만들어서 기존 board는 벽만 세우는 경우를 담당하고, temp는 매번 board값을 복사하여
// DFS순회만을 담당하면 깔끔하게 구현할수 있다. 

// 또한 상술하였듯 DFS순회를 여러번 해야하기 때문에 매번 NXM 배열을 순회하지 않고 확산의 시작점인 바이러스의 좌표만을 따로
// 기록하여 DFS순회를 하면 조금더 빠른 성능을 기대할수 있다. 그후 DFS순회 담당 temp를 순회하며 안전공간(값이 0인 좌표)의
// 수를 반환하면 된다.

// 3번함수는 전형적인 백트래킹 함수인데 이 함수에는 벽을 세울수 있는 값이 0인 좌표값들의 배열이 필요하다.
// 값이 0인 좌표값들이 K개가 있다고 할때 순서대로 첫번째 ~ K번째 좌표값을 골라 총 3개를 만들어야하기 때문이다.
// 현재 3개의 좌표값이 골라졌다면 2번 함수를 호출하여 최종값인 answer의 값을 갱신해준다.


vector<vector<int>> board, temp;
vector<pair<int, int>> zero, two;
int trans[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
int N, M, answer = 0;


// DFS인 1번 함수.
void DFS(int y, int x)
{
    temp[y][x] = 2;

    for (int i = 0; i < 4; ++i)
    {
        int dy = y + trans[i][0];
        int dx = x + trans[i][1];

        if (dy < 0 || dy >= N || dx < 0 || dx >= M || temp[dy][dx] != 0)
            continue;

        DFS(dy, dx);
    }
}

// 2번 함수. DFS를 순회하여 현재 안전공간의 크기를 반환한다.
int CalSafe()
{
    int safe = 0;
    temp = board;
    for (int i = 0; i < two.size(); ++i)
        DFS(two[i].first, two[i].second);

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (temp[i][j] == 0)
                ++safe;

    return safe;
}

// 백트래킹인 3번 함수. 값이 0인 좌표값들을 순회하며 하나씩 값을 고르되, 총 3개를 골랐다면 그때 안전공간의 크기를 갱신해나간다.
void BackTrack(int idx, int num)
{
    if (num == 3)
    {
        answer = max(answer, CalSafe());
        return;
    }

    for (int i = idx + 1; i < zero.size(); ++i)
    {
        board[zero[i].first][zero[i].second] = 1;
        BackTrack(i, num + 1);
        board[zero[i].first][zero[i].second] = 0;
    }
}

void MakeAnswer()
{
    BackTrack(-1, 0);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    board.resize(N, vector<int>());
    int cur;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            cin >> cur;
            board[i].push_back(cur);
            if (cur == 0)
                zero.push_back(make_pair(i, j));
            else if (cur == 2)
                two.push_back(make_pair(i, j));
        }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}