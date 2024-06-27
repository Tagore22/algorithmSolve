#include <iostream>

using namespace std;

// 풀이.
// 정말 어려웠다. 젠장. 정답율이 30퍼센트도 안되는 문제이니 당연한건가.
// 냅색과 DP를 이용한 풀이이다. 현재 idx번째 원소에 도달하였을때 가능한 행동은 2가지가 존재한다.

// 1. 현재 원소를 새로운 구간으로 만든다.
// 2. 현재 원소를 건너뛴다.

// 이 2가지를 구현하면 된다. 생각보다 어렵지 않았는데 아.. 뭔가 너무 어렵게 생각한것 같기도 하고 아니면
// 지금은 답을 알아서 어렵지 않게 생각하는것 같기도 하고. 어쨌든 내일도 힘내보자.

// 자세한 설명은 주석으로 남긴다.

int N, M;
int board[100];
int dp[100][51];

// 모든 경우의 수를 순회하는 함수.
int BackTrack(int idx, int num)
{
    // M개를 모두 골랐다면 0을 반환하여 순회를 멈춘다.
    if (num == M)
        return 0;
    // 건너 뛴 결과가 배열을 벗어났다면 매우 큰 수를 반환하여 무시한다.
    if (idx >= N)
        return -987654321;

    int& ans = dp[idx][num];
    if (ans != -1)
        return ans;

    // 1. idx번째 원소를 건너 뛴 경우.
    ans = BackTrack(idx + 1, num);
    int sum = 0;
    // 2. idx번째 원소부터 i개의 원소를 구간으로 만드는 경우.
    // 이때 최대 N개까지 하여 범위값을 넘어가도 위에 기저사례에서 걸러내기 때문에
    // 모든 경우를 다 해본다.
    for (int i = idx; i < N; ++i)
    {
        sum += board[i];
        // 구간이 인접하면 안되기에 이번 구간 + 2번째 원소로 이동한다.
        ans = max(ans, BackTrack(i + 2, num + 1) + sum);
    }
    return ans;
}

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j <= M; ++j)
            dp[i][j] = -1;
    cout << BackTrack(0, 0) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}