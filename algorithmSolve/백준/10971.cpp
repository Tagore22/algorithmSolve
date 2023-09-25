#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 오랜만에 아주 오래전에 풀었던 외판원 순회 문제다.
// 문제 자체는 매우 간단한다. 갈수 있는 모든 경우를 계산해서 그중 최소값을 출력하면 된다.
// 다만 2가지 중요한 부분이 존재한다.

// 1. 경로의 시작점은 어디로 지정하든 그 값은 같다.(아무곳으로든 지정하면 된다)
// 2. 가지치기의 효율이 크다.

// 특히 2번은 속도가 124 -> 0으로 확 차이가 난다.
// 또한 1번은 코딩을 간단히 하는데 매우 중요하다.

// 자세하 설명은 주석으로 남긴다.

int board[10][10];
bool visit[10];
int N, answer = 978654321;

// 모든 경우를 계산해보는 함수.
void DFS(int cur, int num, int sum)
{
    // 위 상술한 2번의 가지치기. 이미 경로의 합이 기존의 최소값보다 크다면 무시한다.
    if (sum > answer)
        return;

    if (num == N)
    {
        // N개를 모두 구했을때 마지막 지점에서 시작 지점으로 되돌아갈수 있다면
        // answer를 갱신한다.
        int end = board[cur][0];
        if (end != 0)
            answer = min(answer, sum + end);
        return;
    }

    // 모든 도시들을 순회한다.
    for (int i = 0; i < N; ++i)
    {
        // 이미 방문한 지점이거나 도달할수 없는 지점이라면 무시한다.
        if (visit[i] || board[cur][i] == 0)
            continue;

        visit[i] = true;
        DFS(i, num + 1, sum + board[cur][i]);
        visit[i] = false;
    }
}

void MakeAnswer()
{
    memset(visit, false, sizeof(visit));

    visit[0] = true;
    DFS(0, 1, 0);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}