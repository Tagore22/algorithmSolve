#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

// 풀이.
// 평범한 BFS 문제에다가 난이도도 실버1인데 정답율이 38%인걸 보면 
// 메모리 제한 때문인것같다. 기존에는 i, j번째 원소의 방문 여부를 체크하는
// bool타입 배열 visit을 생각도 했었는데 거리값 배열 answer을 -1로 초기화시켜서
// 새로 도달한 좌표값의 answer값이 -1이 아니라면 이미 방문한 곳이기 때문에
// 이렇게 무조건 존재햐야하는 거리값 answer을 이용해서 방분 여부값 visit을 대체할수 있었고
// 메모리를 아낄수 있었다.

char board[1000][1000];
int answer[1000][1000];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // 좌, 상, 우, 하.
int N, M;
pair<int, int> from;

void BFS()
{
    queue<pair<int, int>> que;
    que.push(from);
    answer[from.first][from.second] = 0;

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        for (int i = 0; i < 4; ++i)
        {
            int dy = y + rot[i][0];
            int dx = x + rot[i][1];

            // 상술하였듯 answer로 방문 여부값을 대체할수 있다. -1이 아니라면 접근 불가능한 곳이거나
            // 이미 이전에 방문하여 값이 변경된 상태이기 때문.
            if (dy < 0 || dy >= N || dx < 0 || dx >= M || answer[dy][dx] != -1)
                continue;

            answer[dy][dx] = answer[y][x] + 1;
            que.push(make_pair(dy, dx));
        }
    }
}

void MakeAnswer()
{
    BFS();

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
            cout << answer[i][j] << ' ';
        cout << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    // answer값을 -1로 초기화해야 한다. 다만 아래부분에서 answer값이 변경될수도 있기에
    // 더 이전에서 -1로 초기화해야한다.
    memset(answer, -1, sizeof(answer));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == '2')
                from = make_pair(i, j);
            // board값이 '0'인 곳은 아예 접근이 불가능하기에 여기서 answer의 값을 갱신한다.
            else if (board[i][j] == '0')
                answer[i][j] = 0;
        }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}