#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 풀이.
// 문제를 간단히 요약하자면 X에서 K번 이동하였을때의 정점의 번호를 오름차순으로 출력하면 된다.
// 각 정점 사이의 거리는 1이기 때문에 굳이 다익스트라를 사용하지 않아도 되고,
// 시작점이 주어졌기에 굳이 벨만-포드를 사용하지 않아도 된다.

// 자세한 설명은 주석으로 남긴다.

vector<vector<int>> board;
int N, M, K, X;

// 모든 순회를 구현하는 BFS함수.
void BFS()
{
    queue<int> que;
    que.push(X);
    vector<bool> visit(N + 1, false);
    visit[X] = true;
    // K번 이동후의 결과를 알기 위한 변수.
    int idx = 0;

    // 큐가 비어있지 않았을때 K번의 이동까지 모두 순회한다.
    while (!que.empty() && idx < K)
    {
        int qsize = que.size();
        ++idx;
        for (int iter = 0; iter < qsize; ++iter)
        {
            int here = que.front();
            que.pop();

            for (int i = 0; i < board[here].size(); ++i)
            {
                int there = board[here][i];

                if (visit[there])
                    continue;

                que.push(there);
                visit[there] = true;
            }
        }
    }

    vector<int> answer;
    // 그 이후 현재 큐에 담긴 모든 정점들을 꺼낸다.
    while (!que.empty())
    {
        answer.push_back(que.front());
        que.pop();
    }

    // 정점들이 비었다면 -1을 출력하고 탈출한다.
    if (answer.empty())
    {
        cout << -1 << '\n';
        return;
    }

    // 그렇지 않다면 오름차순으로 정렬하여 출력한다.
    sort(answer.begin(), answer.end());
    for (int i : answer)
        cout << i << '\n';
}

void MakeAnswer()
{
    BFS();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K >> X;
    board.resize(N + 1, vector<int>());
    int from, to;
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to;
        board[from].push_back(to);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}