#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 주어진 색깔이 3개이기에 idx번째 층에서 고를수 있는 경우는 다음과 같다.
// 1. 하나의 색으로 모두 칠할때
// 2. 2개의 색으로 칠할때. idx개에서 idx / 2개를 고른 조합의 경우를 곱해준다.
// 3. 3개의 색으로 칠할때. idx개에서 idx / 3개를 고른 조합의 경우
// idx - (idx / 3)개에서 3개를 고른 조합의 경우를 곱해준다.

// 파스칼의 삼각형을 사용하여 미리 경우의 수를 구해 가독성을 끌어올렸다.

// 자세한 설명은 주석으로 남긴다.

long long dp[11][101][101][101];
long long com[11][11];
int N, R, G, B;

// 파스칼의 삼각형을 이용해 모든 경우의 수를 미리 구하는 함수
void Pascal()
{
    for (int i = 1; i <= N; ++i)
    {
        // 양 끝은 1로 초기화
        com[i][0] = com[i][i] = 1;
        // 파스칼 항등식 
        for (int j = 1; j < i; ++j)
            com[i][j] = com[i - 1][j - 1] + com[i - 1][j];
    }
}

long long FindDP(int idx, int R, int G, int B)
{
    // 어떠한 색깔이 음수라면 더이상 구할수 없으므로 0을 반환한다.
    if (R < 0 || G < 0 || B < 0)
        return 0;
    // 0까지 도달하였다면 성공하였으므로 1을 반환한다.
    if (idx == 0)
        return 1;

    long long& ans = dp[idx][R][G][B];
    if (ans != -1)
        return ans;
    ans = 0;

    // 1가지 색으로 모두 칠할때.
    ans += FindDP(idx - 1, R - idx, G, B);
    ans += FindDP(idx - 1, R, G - idx, B);
    ans += FindDP(idx - 1, R, G, B - idx);

    // 2가지 색으로 칠할때.
    if (idx % 2 == 0)
    {
        int half = idx / 2;
        // idx개중 절반을 고른후 나머지를 고르는 경우는 1이므로 신경쓰지 않는다.
        ans += com[idx][half] * FindDP(idx - 1, R - half, G - half, B);
        ans += com[idx][half] * FindDP(idx - 1, R - half, G, B - half);
        ans += com[idx][half] * FindDP(idx - 1, R, G - half, B - half);
    }

    // 3가지 색으로 칠할때.
    if (idx % 3 == 0)
    {
        int third = idx / 3;
        // idx개중 3분의 1개를 고른후 다시 나머지중 3분의 1개를 고르며 나머지를 고르는 경우는 1이므로 신경쓰지 않는다.
        ans += com[idx][third] * com[idx - third][third] * FindDP(idx - 1, R - third, G - third, B - third);
    }
    return ans;
}

void MakeAnswer()
{
    // memset으로 0이외의 값을 초기화하기에는 불안정하기에 fill()을 이용해 초기화한다.
    fill(&dp[0][0][0][0], &dp[10][100][100][101], -1);
    Pascal();
    cout << FindDP(N, R, G, B) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> R >> G >> B;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}