#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 17086번의 더 나은 풀이.
// 생각해보니 그냥 하나의 큐에 모든 상어들을 한번에 다 집어넣고 방문 여부를 하나로 동기화시키면 될일이었다.

// 자세한 설명은 주석으로 남긴다.

vector<vector<bool>> visit;
queue<pair<int, int>> que;
int rot[8][2] = { {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1} };
int N, M, answer = -1;

// BFS순회를 하는 함수.
void BFS()
{
    while (!que.empty())
    {
        // 현재 큐에 존재하는 원소들만이 한칸씩 이동하기 위해 
        // 현재 큐에 존재하는 원소들만큼만 순회한다.
        int qsize = que.size();
        for (int iter = 0; iter < qsize; ++iter)
        {
            int y = que.front().first;
            int x = que.front().second;
            que.pop();

            // 8방향으로 모두 이동해본다.
            for (int i = 0; i < 8; ++i)
            {
                int dy = y + rot[i][0];
                int dx = x + rot[i][1];

                // 이동한 위치가 배열값을 벗어났거나 이미 방문한 위치라면 무시한다.
                if (dy < 0 || dy >= N || dx < 0 || dx >= M || visit[dy][dx])
                    continue;

                // 방문 여부를 갱신하고 큐에 집어넣는다.
                visit[dy][dx] = true;
                que.push(make_pair(dy, dx));
            }
        }
        // 순회한만큼 거리가 1씩 증가한다.
        ++answer;
    }
}

void MakeAnswer()
{
    BFS();
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    visit.resize(N, vector<bool>(M, false));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            int point;
            cin >> point;
            if (point == 1)
            {
                // 배열값이 1인 상어위치는 미리 큐에 집어넣고
                // 방문 여부를 갱신한다.
                que.push(make_pair(i, j));
                visit[i][j] = true;
            }
        }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}