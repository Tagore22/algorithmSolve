#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

// 풀이.
// 그래프 탐색 문제였다. 1번 정점부터 시작해서 거리가 2까지의 정점을 찾아 그 정점들의 수를 출력하면 된다.
// DFS 혹은 BFS로 모두 풀수 있다. 이번 풀이는 BFS다.

// 자세한 설명은 주석으로 남긴다.

vector<vector<int>> board;
bool isanswer[501], visit[501];
int N, M;

// BFS순회를 구현하는 함수.
void BFS()
{
    queue<int> que;
    que.push(1);
    memset(isanswer, false, sizeof(isanswer));
    memset(visit, false, sizeof(visit));
    visit[1] = true;
    int len = 0;

    // 큐가 비었거나 이동이 3번 이상일 경우 반복문을 탈출한다.
    while (!que.empty() && len < 2)
    {
        // 이번 이동은 이번 큐에 담긴 원소들만이 실행될수 있다.
        int qsize = que.size();
        for (int iter = 0; iter < qsize; ++iter)
        {
            int here = que.front();
            que.pop();

            // here에서 이동할수 있는 모든 이동을 실행한다.
            for (int i = 0; i < board[here].size(); ++i)
            {
                int there = board[here][i];

                // 다음 정점 there이 이미 방문한곳이라면 무시한다.
                if (visit[there])
                    continue;

                visit[there] = true;
                isanswer[there] = true;
                que.push(there);
            }
        }
        // len은 시작지점이 아닌 맨 마지막에서 증가해야 구도가 맞는다.
        ++len;
    }
}

void MakeAnswer()
{
    BFS();

    int answer = 0;
    // 1번은 신랑이므로 무시하고 2번부터 답을 찾는다.
    for (int i = 2; i <= N; ++i)
    {
        if (isanswer[i])
            ++answer;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    board.resize(N + 1, vector<int>());
    int from, to;
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to;
        board[from].push_back(to);
        board[to].push_back(from);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}