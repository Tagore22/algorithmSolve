#include <iostream>
#include <queue>

using namespace std;

// 1113번의 더 빠르고 간단한 풀이.
// 영역을 만들기 위해서는 가장자리와 접해서는 안된다. 이것을 응용한 풀이이다.
// 기존의 좌표값을 아우르는 한줄을 더 만든다. 그리고 1 ~ 주어지는 최대값까지 순회하며
// 가장자리값을 1씩 증가시킨다. 이때 BFS순회를 이용하는데 상술한대로 가장자리값과 같거나 작은 곳은
// 절대로 영역을 만들수 없기 때문에 BFS순회에서 도달할수 있는 값들을 미리 증가시켜 후에 추가되는 부분에서 빼준다.

// 자세한 설명은 주석으로 남긴다.

int board[52][52];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
int N, M, maxnum = 0, answer = 0;

// 매번 가장자리에서 도달할수 있는 모든 곳들의 값을 갱신함.
void BFS(int h)
{
    queue<pair<int, int>> que;
    que.push(make_pair(0, 0));
    board[0][0] = h;

    while (!que.empty())
    {
        int qsize = que.size();
        for (int iter = 0; iter < qsize; ++iter)
        {
            int y = que.front().first;
            int x = que.front().second;
            que.pop();

            for (int i = 0; i < 4; ++i)
            {
                int ny = y + rot[i][0];
                int nx = x + rot[i][1];

                // 좌표값을 벗어났거나 가장자리에서 도달할수 있다면 값을 갱신하여 나중에 추가되지 않게함.
                if (ny < 0 || ny > N + 1 || nx < 0 || nx > M + 1 || board[ny][nx] >= h)
                    continue;

                board[ny][nx] = h;
                que.push(make_pair(ny, nx));
            }
        }
    }
}

void MakeAnswer()
{
    for (int iter = 1; iter <= maxnum; ++iter)
    {
        BFS(iter);

        // BFS 순회를 통해 가장자리에서 도달할수 있는 부분은 모두 iter로 변경되었기에
        // 이후에 추가값 계산에서 제외된다.
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= M; ++j)
                if (board[i][j] < iter)
                {
                    ++answer;
                    ++board[i][j];
                }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    string str;
    for (int i = 1; i <= N; ++i)
    {
        cin >> str;
        // 여기 이부분에서 실수가 있었다. str의 값에 접근해야하기에 j는 0부터 시작해야하며
        // 이후 좌표의 위치에서 + 1을 해야한다.
        for (int j = 0; j < M; ++j)
        {
            board[i][j + 1] = str[j] - 48;
            maxnum = max(maxnum, board[i][j + 1]);
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}