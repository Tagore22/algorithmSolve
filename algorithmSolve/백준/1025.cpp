#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

// 풀이.
// 언젠가 풀이가 생각나지 않아 넘겼던 문제인데 정형된 틀이 없는 브루트포스 알고리즘 같았다. 
// 어떤 좌표 (y, x)에서 등차수열로 y, x값을 움직여 최대 9자리의 수를 만들때 가장 큰 완전 제곱수를 구해야 하는데
// BFS를 이용하여 풀었다. 처음에는 8방향으로 나아가는 구현을 짰는데 다시 살펴보니 세로로 한칸 가로로 2칸도 
// 움직이는 경우도 있었기에 제대로 된 풀이가 아니었다. 결과적으로 (-N, -M) ~ (N, M)까지 모든 경우를 직접 2중 for문으로 
// 큐에 넣어 순회를 하였다. 이 부분도 처음에는 순회수를 아낀다고 -N ~ N - 1까지 범위를 지정했는데 
// 1, 1, 4의 경우 int i = 0; i < 0이기 때문에 아예 큐에 아무것도 들어가지 않아 제대로 된 정답이
// 나오지 않았다. 후술한대로 범위값을 늘려 정답을 맞췄다. N, M값이 매우 작아서 BFS로 풀수 있었다.

// 자세한 설명은 주석으로 남긴다.

// 큐에 들어갈 사용자 정의 타입.
// 각각 현재 y좌표, x좌표, 증가하는 y값, 증가하는 x값, 현재 수이다.
struct pos
{
    int y; 
    int x;
    int plus_y;
    int plus_x;
    int num;
};

int board[9][9];
int N, M, answer = -1;

void BFS(int y, int x)
{
    queue<pos> que;
    for (int i = -N; i <= N; ++i)
        for (int j = -M; j <= M; ++j)
        {
            // 세로와 가로 모두 0만큼 증가한다면 무한루프가 일어나기에 주의해야한다.
            if (i == 0 && j == 0)
                continue;
            que.push(pos{ y, x, i, j, board[y][x] });
        }

    while (!que.empty())
    {
        int y = que.front().y;
        int x = que.front().x;
        int plus_y = que.front().plus_y;
        int plus_x = que.front().plus_x;
        int num = que.front().num;
        que.pop();
        int sqrt_num = sqrt(num);

        // 현재 수가 완전 제곱수라면 최종값 answer와 비교한다.
        if (sqrt_num * sqrt_num == num)
            answer = max(answer, num);

        int ny = y + plus_y;
        int nx = x + plus_x;

        // 범위값을 벗어났다면 무시하고 그렇지 않다면 큐에 넣는다.
        if (ny < 0 || ny >= N || nx < 0 || nx >= M)
            continue;
        que.push(pos{ ny, nx, plus_y, plus_x, num * 10 + board[ny][nx] });
    }
}

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            BFS(i, j);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        for (int j = 0; j < M; ++j)
            board[i][j] = str[j] - '0';
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}