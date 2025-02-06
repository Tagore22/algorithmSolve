#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 정답율이 20퍼도 안나오는 문제였다. DP를 이용한 냅색 문제였는데 2가지 경우에서
// 더 높거나 낮은 경우를 사용하는 기존의 방식과는 달랐기에 발상까지 오래 걸렸다.
// 결과적으로 가능한 경우를 1로, 불가능한 경우를 0로 반환하여 둘중 더 큰값을 구하면 된다.

// 자세한 설명은 주석으로 남긴다.

pair<int, int> board[100];
int dp[50001][100];
int N, sum;

int Nap(int cost, int idx)
{
    // 답을 찾은 경우. 1을 반환.
    if (cost == sum)
        return 1;
    // 마지막까지 찾지 못한 경우. 0을 반환.
    if (idx == N)
        return 0;

    int& ans = dp[cost][idx];
    if (ans != -1)
        return ans;
    ans = 0;

    // 가지고 있는 동전의 개수만큼 순회한다.
    for (int i = 0; i <= board[idx].second; ++i)
    {
        // 절반값보다 총합이 커질 경우 무시한다.
        if (cost + board[idx].first * i > sum)
            continue;
        // 모든 경우중 가장 큰 값을 반환한다.
        // 실패는 0, 성공은 1이기 때문에 단 한번만 성공해도
        // 1이 반환된다.
        ans = max(ans, Nap(cost + board[idx].first * i, idx + 1));
    }
    return ans;
}

void MakeAnswer()
{
    for (int iter = 0; iter < 3; ++iter)
    {
        cin >> N;
        sum = 0;
        for (int i = 0; i < N; ++i)
        {
            cin >> board[i].first >> board[i].second;
            sum += board[i].first * board[i].second;
        }
        // 애시당초 총합이 홀수라면 0을 반환한다.
        if (sum % 2 != 0)
        {
            cout << 0 << '\n';
            continue;
        }
        sum /= 2;
        memset(dp, -1, sizeof(dp));
        cout << Nap(0, 0) << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}