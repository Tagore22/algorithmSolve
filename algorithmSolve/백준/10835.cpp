#include <iostream>

using namespace std;

// 풀이.
// 각 방법은 3가지이다. 

// 1. 그냥 왼쪽을 버림.
// 2. 그냥 양쪽을 버림.
// 3. 왼쪽이 오른쪽보다 클때 오른쪽만을 버리며 그 점수를 획득함.

// 그냥 생각해보면 길이가 최대 2000이면서 1번 2번은 무조건 가능함으로 연산이 너무 커지지만
// DP를 이용하면 최대 400만으로 연산량을 줄일수 있다.

// 자세한 설명은 주석으로 남긴다.

int boardL[2000], boardR[2000], dp[2000][2000];
int N;

// 모든 경우를 확인해보는 함수.
int CalAns(int l, int r)
{
    // 양쪽중 아무곳이나 모든 카드를 다쓴다면 0을 반환하며 탈출한다.
    if (l == N || r == N)
        return 0;

    int& ans = dp[l][r];
    if (ans != -1)
        return ans;
    ans = 0;

    // 그냥 왼쪽을 버릴 경우.
    ans = max(ans, CalAns(l + 1, r));
    // 그냥 양쪽을 버릴 경우.
    ans = max(ans, CalAns(l + 1, r + 1));
    // 만약 오른쪽이 더 작다면 오른쪽만을 버리며 그 점수를 획득함.
    if (boardL[l] > boardR[r])
        ans = max(ans, CalAns(l, r + 1) + boardR[r]);
    return ans;
}

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            dp[i][j] = -1;
    cout << CalAns(0, 0) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> boardL[i];
    for (int i = 0; i < N; ++i)
        cin >> boardR[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}