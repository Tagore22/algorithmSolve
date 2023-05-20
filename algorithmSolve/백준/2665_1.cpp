#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// 2665번의 BFS풀이. 맨 뒤부터 구하는 DFS와는 달리 시작점부터 점차 구해나간다.
// 중복 여부는 bool이 아닌 값으로 직접하는데 이미 지나온 칸의 바꾼 수는 현재 칸의 바꾼수보다 무조건 같거나 작기 때문이다.
// 그렇게 하나씩 구해나가며 마지막 dp[N - 1][N - 1]을 구하면 된다.

// 자세한 설명은 주석으로 남긴다.

// 처음에는 무조건 DFS로 풀려고 그랬는데 너무 틀에 박혀있었다. 조금 더 넓은 시야를 갖자.

bool board[50][50];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // 좌 상 우 하.
int dp[50][50];
int N;

void BFS()
{
    queue<pair<int, int>> que;
    que.push(make_pair(0, 0));
    // 초기값은 0.
    dp[0][0] = 0;

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i)
        {
            int dy = y + rot[i][0];
            int dx = x + rot[i][1];

            if (dy < 0 || dy >= N || dx < 0 || dx >= N)
                continue;

            if (board[dy][dx])
            {
                if (dp[y][x] < dp[dy][dx])
                {
                    dp[dy][dx] = dp[y][x];
                    que.push(make_pair(dy, dx));
                }
            }
            else
            {
                if (dp[y][x] + 1 < dp[dy][dx])
                {
                    dp[dy][dx] = dp[y][x] + 1;
                    que.push(make_pair(dy, dx));
                }
            }
        }
    }
}

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            dp[i][j] = 987654321;
    BFS();

    cout << dp[N - 1][N - 1] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        for (int j = 0; j < N; ++j)
            board[i][j] = str[j] - '0';
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}