#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

// 풀이.
// BFS를 조금 꼬아서 낸 문제였다.
// 각 좌표를 방문할때 중복 방문 여부를 검사하기 위해 DP를 이용하여 배열로 검사하는데
// 단순히 좌표값만으로는 안되고, 현재 몇번 벽을 부쉈는지 까지 DP에 포함해야한다.
// 왜냐하면, 당연하게도 벽을 2번 부숴서 y, x로 왔을때와 벽을 부수지 않고 y, x로 왔을때에는
// 같은 경우가 될수 없기 때문이다. 이 개념만 알면 나머지는 어렵지 않은 문제다.

// 따라서 1, 1에서 BFS를 순회하되, 상술하였듯 좌표값, 벽을 부순 횟수에 대한 DP로
// 중복 여부를 확인해가며 N, M까지 도달할수 있는 최단 거리를 구하여 출력하면 된다.

struct pos
{
    int y;
    int x;
    int num;
    int dis;
};

int board[1001][1001];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // 좌 상 우 하.
int N, M, K;
bool check[1001][1001][11];

int BFS()
{
    memset(check, false, sizeof(check));
    check[1][1][K] = true;
    queue<pos> que;
    que.push(pos{ 1, 1, K, 1 });

    while (!que.empty())
    {
        int y = que.front().y;
        int x = que.front().x;
        int num = que.front().num;
        int dis = que.front().dis;
        que.pop();

        if (y == N && x == M)
            return dis;

        for (int i = 0; i < 4; ++i)
        {
            int dy = y + rot[i][0];
            int dx = x + rot[i][1];

            if (dy <= 0 || dy > N || dx <= 0 || dx > M)
                continue;

            if (board[dy][dx] == 0 && !check[dy][dx][num])
            {
                check[dy][dx][num] = true;
                que.push(pos{ dy, dx, num, dis + 1 });
            }
            else if (board[dy][dx] == 1 && num > 0 && !check[dy][dx][num - 1])
            {
                check[dy][dx][num - 1] = true;
                que.push(pos{ dy, dx, num - 1, dis + 1 });
            }
        }
    }
    return -1;
}

void MakeAnswer()
{
    int answer = BFS();

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    string str;
    for (int i = 1; i <= N; ++i)
    {
        cin >> str;
        for (int j = 1; j <= M; ++j)
            board[i][j] = str[j - 1] - '0';
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}