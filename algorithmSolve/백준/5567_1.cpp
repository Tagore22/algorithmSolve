#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// 5567번의 DFS풀이.
// 큰 틀은 모두 같고 구현 방식만 조금 다르다.

vector<vector<int>> board;
bool isanswer[501], visit[501];
int N, M;

// DFS 순회를 구현하는 함수.
void DFS(int here, int num)
{
    // 이동이 2초과라면 무시하고 탈출한다.
    if (num > 2)
        return;

    visit[here] = true;
    isanswer[here] = true;

    // here에서 이동할수 있는 모든 정점을 순회한다.
    for (int i = 0; i < board[here].size(); ++i)
    {
        int there = board[here][i];

        // 다음 정점 there이 이미 방문한곳이라면 무시한다.
        if (visit[there])
            continue;

        DFS(there, num + 1);
    }
    // here의 방문 여부를 갱신한다.
    visit[here] = false;
}

void MakeAnswer()
{
    memset(isanswer, false, sizeof(isanswer));
    memset(visit, false, sizeof(visit));
    DFS(1, 0);

    int answer = 0;
    // 1번은 신랑이므로 무시하고 2번부터 찾는다.
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