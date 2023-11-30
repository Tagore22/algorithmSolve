#include <iostream>
#include <cstring>

using namespace std;

// 18290번의 더 나은 풀이.
// 따로 벡터에 이전 값들을 저장하지 않고 백트래킹의 장점을 극대화 시켜서 푸는 풀이이다.
// 매번 순회는 하나의 독립적인 순회이므로 벡터가 아닌 bool 배열을 이용하여 이전에 방문했던 칸을 구현해도 된다.

// 자세한 설명은 주석으로 남긴다.

int board[10][10];
bool visit[10][10];
int N, M, K;

// 모든 순회를 구현하는 함수.
int DFS(int y, int x, int num)
{
    // 바로 이부분에서 한가지 실수를 했다. 이전 풀이에서는 num이 1일때 이전값 + 현재값을 바로 반환했는데
    // 이 풀이에서는 그러면 안된다. 왜냐하면 이전 풀이에서는 매 이동전에 인접한 칸인지 미리 확인하고 넘어갔는데
    // 이 풀이에서는 내 위치를 잡고 그 위치부터 다시 시작하기 때문에 기존처럼하면 똑같은 값이 중복된다.
    if (num == 0)
        return 0;

    int ans = -50000;
    int from = x + 1;
    for (int i = y; i < N; ++i)
    {
        for (int j = from; j < M; ++j)
        {
            // 현재 위치가 이미 방문하였거나, 이전의 인접한 칸들에 이미 방문하였다면 무시한다.
            if (!visit[i][j] && !visit[i - 1][j] && !visit[i][j - 1])
            {
                visit[i][j] = true;
                ans = max(ans, DFS(i, j, num - 1) + board[i][j]);
                visit[i][j] = false;
            }
        }
        from = 0;
    }
    return ans;
}

void MakeAnswer()
{
    memset(visit, false, sizeof(visit));
    int answer = DFS(0, -1, K);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}