#include <iostream>

using namespace std;

// 풀이.
// 어렵진 않은데 아침에 늘 그렇듯이 머리가 안돌아가 버벅인 문제다.
// 처음에는 BFS로 구현을 할 생각이었다. 하지만 한가지 문제가 있는데 이미 방문한 정점에 다른 궤도로 접근하였을때를
// 처리하기가 곤란했다. 따라서 DFS로 다시 구현하게 되었다. 그래도 한가지 곤란한게 있었는데 어떻게 다시 원점으로 돌아왔는가를
// 구현하는 점이었다. 정답은 이미 문제에서 주어져있었다. 바로 2가지를 이용하는것이다.

// 1. 어떠한 위치 y, x에서 시작해서 무조건 y, x로 돌아왔을때만 처리함.
// 2. 이동한 거리(재귀호출된 횟수)가 4 이상이여야 한다.

// 처음에는 방문 여부를 false로 초기화하지 않고 구했는데 이 부분이 매우 처리곤란했다. 따라서 DFS 순회 이후
// 방문 여부를 다시 false로 초기화해 매번 각 위치를 다시 방문해야만 했다. 그래서 예제에 N과 M의 크기가 최대 50밖에
// 안되는것 같기도 하다.

// 자세한 설명은 주석으로 남긴다.

char board[50][50];
bool visit[50][50] = { false, };
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
int N, M, cost;
pair<int, int> from; // DFS 순회를 시작했던 최초의 위치.

// DFS 구현 함수.
void DFS(int y, int x)
{
    for (int i = 0; i < 4; ++i)
    {
        // 인접한 위치이며 각 변을 공유하는건 상하좌우 4방향뿐이다.
        int ny = y + rot[i][0];
        int nx = x + rot[i][1];

        // 이 부분에서 cost >= 3이 매우 중요하다. 그렇지 않으면 시작 위치와 그 다음 위치가 같을때
        // 답이 틀리게 된다. 즉 최소 사이클의 자격을 따져야 한다.
        // A A
        // A A
        // 처음에는 cost의 값이 잘못되서 한번 틀렸다. 0에서 시작하므로 최소 3이 되어야한다.
        if (cost >= 3 && from.first == ny && from.second == nx)
        {
            cout << "Yes" << '\n';
            exit(0);
        }

        // 범위값을 벗어났거나 이미 방문했거나 칸의 색이 다르다면 무시한다.
        if (ny < 0 || ny >= N || nx < 0 || nx >= M || visit[ny][nx] || board[y][x] != board[ny][nx])
            continue;
        // 방문 여부와 cost의 갱신 및 재귀 호출.
        visit[ny][nx] = true;
        ++cost;
        DFS(ny, nx);
        visit[ny][nx] = false;
        --cost;
    }
}

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            // 원래는 이 분에서 방문하지 않은 정점들만 DFS 순회를 하려고 했으나
            // 상술한대로 구현이 바뀌어야 했다.
            cost = 0;
            from = make_pair(i, j);
            visit[i][j] = true;
            DFS(i, j);
            visit[i][j] = false;
        }

    cout << "No" << '\n';
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
            board[i][j] = str[j];
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}