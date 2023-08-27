#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 처음에는 스택을 이용한 그리디 알고리즘으로 풀수 있을줄 알았는데 전혀 아니었다.
// 예를 들어 5, 1, 8, 2, 3, 9라면 출력은 15지만 실제 답은 18이다.
// 진짜 풀이는 아래와 같이 완전탐색이었다. 
// 0 ~ N - 1까지 순회하며 현재 원소번호 idx 이후의 값이 board[idx]보다 크다면 다음으로 넘어가는
// 재귀 호출을 사용하면 된다.

// 자세한 설명은 주석으로 남긴다.

int board[1000], dp[1000];
int N;

int BackTrack(int idx)
{
    // 기저 조건. 맨 마지막 원소에 도달하였다면 더이상 나아갈수 없으니 원소값을 그대로 반환한다.
    if (idx == N - 1)
        return board[idx];

    int& ans = dp[idx];
    if (ans != -1)
        return ans;

    // 현재부터 만들수 있는 최소값은 적어도 현재값이다.
    ans = board[idx];
    // idx번째 이후 원소값들중 board[idx]보다 크다면 모두 시도해본다.
    for (int i = idx + 1; i < N; ++i)
        if (board[i] > board[idx])
            ans = max(ans, BackTrack(i) + board[idx]);

    return ans;
}

void MakeAnswer()
{
    memset(dp, -1, sizeof(dp));
    int answer = 0;
    for (int i = 0; i < N; ++i)
        answer = max(answer, BackTrack(i));

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}