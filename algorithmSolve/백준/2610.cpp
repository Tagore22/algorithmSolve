#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이.
// 정답율이 30프로가 안되는 어려운 문제였다. 이것에는 문제가 조금 아리송하게 나온 탓도 있는데
// 어떠한 정점에서 다른 모든 정점까지의 이동횟수가 가장 짧은 정점이 아닌
// 가장 먼 정점까지의 이동횟수가 가장 짧은 정점이 대표가 되어야 하기 때문이다.
// 질문 게시판을 보면 나처럼 이 부분에서 많이들 막힌것 같다.
// 그 이후로는 같은 위원회에서 대표를 뽑은후 오름차순으로 정렬하여 출력하면 된다.
// 같은 위원회의 인원은 DFS로 찾았다. 다른 방법도 있겠으나 이게 가장 먼저 떠오르고 간단한 방법이었다.
// 이렇게 같은 위원회의 인원들을 찾아놓으면 그 이전의 미리 플로이드 와샬 알고리즘으로 계산해놓았던
// 각 정점들까지의 거리들을 최대한을 구하고 각 위원회의 인원들의 최대값중 최소값을 지닌 인원을 찾아서
// 최종답 answer의 집어넣는다. 모든 순회가 끝나면 answer를 정렬하여 출력하면 된다.

// 자세한 설명은 주석으로 남긴다.

int board[101][101] = { 0, };
vector<int> cur;
vector<bool> visit(101, false);
int N, M;

// 두 정점간의 최소 거리를 구하는 함수.
void Floyd()
{
    // i에서 i는 0으로, 도달하지 못하는 정점까지의 거리는 아예 큰 105로 초기화한다.
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            if (i != j && board[i][j] == 0)
                board[i][j] = 105;
    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
            {
                // i에서 k 혹은 k에서 j가 도달불가능하다면 무시한다.
                if (board[i][k] == 0 || board[k][j] == 0)
                    continue;
                // i에서 j는 기존거리와 k를 경유하여 도달하는 거리들중 최소값으로 한다.
                board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
            }
}

// 같은 위원회의 인원을 찾기 위한 DFS 순회.
void DFS(int here)
{
    visit[here] = true;
    cur.push_back(here);

    for (int there = 1; there <= N; ++there)
        if (!visit[there] && board[here][there] != 105)
            DFS(there);
}

void MakeAnswer()
{
    Floyd();
    vector<int> answer;
    for (int iter = 1; iter <= N; ++iter)
    {
        if (!visit[iter])
        {
            // DFS 순회를 통해 같은 위원회의 인원들을 계산한다.
            cur.clear();
            DFS(iter);

            pair<int, int> max_num = make_pair(0, 100);
            // 각 정점에서 다른 정점까지의 최대값을 구하고
            // 모든 정점들의 최대값들중 최소값을 구하여 그 정점을
            // 최종답 answer에 넣는다.
            for (auto a : cur)
            {
                int now = -1;
                for (auto b : cur)
                    now = max(now, board[a][b]);
                if (now < max_num.second)
                    max_num = make_pair(a, now);
            }
            answer.push_back(max_num.first);
        }
    }
    // answer의 수를 출력하고 정렬하여 오름차순으로 출력한다.
    cout << answer.size() << '\n';
    sort(answer.begin(), answer.end());
    for (auto ans : answer)
        cout << ans << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    int from, to;
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to;
        board[from][to] = 1;
        board[to][from] = 1;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}