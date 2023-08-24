#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 처음엔 정렬문제인줄 알았는데 N의 최대값이 15로 매우 작고, 단순히 시간 혹은 금액의 크기로 정렬해도 
// 풀기 애매했다. 그래서 dp를 통한 완전탐색을 생각했다. 큰 틀 자체는 다음과 같다.

// 1. 0 ~ N - 1까지 순회한다.
// 2. 현재 일수 idx로부터 다음 상담이 가능한 모든일자를 다시 전부 순회해본다.
// 3. 최대값 answer를 출력한다.

// 다만 한가지 주의할점이 있었는데 다음 일자로 넘어갈때 N과 같아도 된다는 점이다.
// 예를 들어 주어진 예시가 1, 1, 10일때 0일 하루를 써서 10원을 받고 1일에 퇴사해도 되기 때문이다.
// 이러한 이유로 BackTrack()의 for문에 i <= N이 되었고 시작점에 기저 조건을 따로 걸어야했다.

// 자세한 설명은 주석으로 남긴다.

pair<int, int> board[15];
int dp[15];
int N;

int BackTrack(int idx)
{
    // 위 상술한 조건때문에 생긴 기저 조건.
    // 현재 일자 idx가 N과 같거나 크다면 0을 반환한다.
    if (idx >= N)
        return 0;

    int& ans = dp[idx];
    if (ans != -1)
        return ans;

    ans = 0;
    int plus = board[idx].first;
    // 위 상술 2번대로 다음상담이 가능한 일자부터 모든 날짜를 순회한다.
    // 또한 상수한 주의할점 때문에 i <= N이 되었다.
    for (int i = idx + plus; i <= N; ++i)
        ans = max(ans, BackTrack(i) + board[idx].second);

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
        cin >> board[i].first >> board[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}