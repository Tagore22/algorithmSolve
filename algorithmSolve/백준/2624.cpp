#include <iostream>

using namespace std;

// 풀이.
// DP를 사용하는 문제다. 각 동전을 0개부터 사용하여 순회하기 때문에 동전간의 순서상은 중복이 없으나,
// idx번째 동전을 사용할때 같은 금액이 될 경우가 존재한다. 예를 들어 1번째에서 10원짜리 하나를 사용했을 경우와
// 1번째를 건너뛰고 2번째에서 5원짜리 동전을 2개를 사용했을때 3번째에서는 똑같이 10원이 제외된 상태로 시작한다.
// 이 경우 중복은 불가피하다. 따라서 이 부분을 DP로 구현해주면 된다.

// 자세한 설명은 주석으로 남긴다.

pair<int, int> board[100];
int dp[100][10001];
int T, K;

// 모든 경우를 순회하는 함수. 상술한대로 DP로 중복을 막는다.
int CalAnswer(int idx, int sum)
{
    // 금액이 0원이라면 방법을 하나 찾았기 때문에 1을 출력한다.
    if (sum == 0)
        return 1;
    // 마지막까지 금액이 0원이 아니라면 결국 찾지 못한다. 그러므로 0을 반환한다.
    if (idx == K)
        return 0;

    // 상술한 DP의 구현.
    int& ans = dp[idx][sum];
    if (ans != -1)
        return ans;
    ans = 0;

    int cost = board[idx].first;
    int num = board[idx].second;
    for (int i = 0; i <= num; ++i)
    {
        // 만약 현재 고르는 금액이 기존의 값보다 크다면 고를수없다.
        // 이 이후의 금액은 현재보다 무조건 커지기 때문에 for문을 탈출한다.
        if (cost * i > sum)
            break;
        // 그렇지 않을 경우 현재 금액을 제외하여 재귀호출한다.
        else
            ans += CalAnswer(idx + 1, sum - cost * i);
    }
    return ans;
}

void MakeAnswer()
{
    for (int i = 0; i < K; ++i)
        for (int j = 0; j <= T; ++j)
            dp[i][j] = -1;
    cout << CalAnswer(0, T) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T >> K;
    for (int i = 0; i < K; ++i)
        cin >> board[i].first >> board[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}