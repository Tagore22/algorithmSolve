#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// 풀면서 '조금 색다른 BFS네.'라고 느꼈는데 알고보니 다익스트라 문제였다. 뭐 어쨌든 자 풀었으니 다행이다.
// 나는 BFS를 여러번 하는 형식으로 풀었다. 왜냐하면 문제가 약간 거지같았는데, 같은 턴에 도달한 1은 단 한번만
// 사라지기 때문이다. 따라서 방문을 뜻하는 visit 배열도 기존의 bool 타입이 아닌 int 타입으로 하여
// 도달한 턴의 수를 기록하게끔 하였다. 그렇지 않고 bool 타입으로 하면 여러므로 코드가 더러워지기 때문이다.

// 자세한 설명은 주석으로 남긴다.

char board[301][301];
int visit[301][301];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
int N, M;
pair<int, int> from, to;

// num번째 턴에 도달할수 있는 모든 곳을 가보는 BFS 함수.
void BFS(int num)
{
    queue<pair<int, int>> que;
    que.push(from);
    // 상술한대로 visit 배열이 bool이 아닌 int다. 중복 방문을 그 위치에 도달한 가장 최근 값을 두어서
    // 비교하기 때문.
    visit[from.first][from.second] = num;

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();


        for (int i = 0; i < 4; ++i)
        {
            int ny = y + rot[i][0];
            int nx = x + rot[i][1];

            // 좌표값을 벗어났거나, 이번 턴에 해당 좌표에 방문했던적이 있다면 무시한다.
            if (ny <= 0 || ny > N || nx <= 0 || nx > M || visit[ny][nx] == num)
                continue;

            // 기존에 0이었다면 계속 큐에 넣고 순회한다.
            if (board[ny][nx] == '0')
            {
                que.push(make_pair(ny, nx));
                visit[ny][nx] = num;
            }
            // 1이었다면 여기까지이므로 값을 0으로 바꾸고 만다.
            else if (board[ny][nx] == '1')
            {
                board[ny][nx] = '0';
                visit[ny][nx] = num;
            }
            // 나머지는 '#'뿐이므로 답을 찾은 경우다. 출력하고 exit로 아예 반복을 무시하며
            // 프로그램을 종료한다.
            else
            {
                cout << num << '\n';
                exit(0);
            }
        }
    }
}

void MakeAnswer()
{
    int num = 1;
    while (true)
    {
        BFS(num);
        ++num;
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> from.first >> from.second >> to.first >> to.second;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}