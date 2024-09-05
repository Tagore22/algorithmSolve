#include <iostream>

using namespace std;

// 풀이.
// 그래프 문제인건 확실했다. 플로이드 워셜 아니면 DFS로 탐색하는 문제인데 둘다 애매했다.
// 결론적으로 전자였는데 매번 입력시 양방향인지 일반방향인지에 따라 초기화값을 바꾸면 되었다.
// 답을 알고 보면 매우 당연하며 쉬운 문제지만 생각해내기가 조금 걸렸다.

// 자세한 설명은 주석으로 남긴다.

int board[251][251];
int N, M, K, S, E;

// 모든 원소에서 다른 원소로 바꾸어야하는 양방향의 최소값을 미리 구하는 함수.
void Floyd()
{
    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                // i에서 j로의 최소값은 k를 경로하는 두 경로의 합과 기존값의 최소값이다.
                board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
}

void MakeAnswer()
{
    Floyd();
    for (int iter = 0; iter < K; ++iter)
    {
        cin >> S >> E;
        cout << board[S][E] << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    // 양방향으로 바꾸어야하는 최소값들의 초기화.
    // N개의 정점이 존재하니 최대값은 N - 1로도 충분하다.
    // 또한 자신에서 자신으로의 값은 무조건 0이다.
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
        {
            if (i == j)
                board[i][j] = 0;
            else
                board[i][j] = N - 1;
        }
    for (int i = 0; i < M; ++i)
    {
        int u, v, b;
        cin >> u >> v >> b;
        // u에서 v로의 최소값은 무조건 0이다. 이동이 가능함. 
        board[u][v] = 0;
        // 양방향이라면 둘다 서로 이동이 가능하니 0이고,
        // 그렇지 않다면 u에서 v로의 값이 일단 1이다.
        if (b == 0)
            board[v][u] = 1;
        else
            board[v][u] = 0;
    }
    cin >> K;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}