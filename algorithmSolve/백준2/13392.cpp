#include <iostream>
#include <cstring>

using namespace std;

// 풀이
// 구상을 떠올리는건 크게 어렵지 않았다. 윗단계의 나사가 왼쪽으로 회전하여
// 현재 단계의 나사도 돌아갈 수 있으므로 dp는 [현재 단계][돌아간 수]로 해야했다.
// 또한 최대 9번 돌아갈 수 있으므로 거의 모든 이동에 10으로 나누는 연산을 해야했다.
// 다만 왼쪽과 오른쪽 회전을 거꾸로 해서 꽤나 헤맸다;

// 자세한 설명은 주석으로 남긴다.

int N, dp[10000][10];
string from, to;

int DPFunc(int idx, int rolnum)
{
    // 기저 사례.
    if (idx >= N)
        return 0;

    int& ans = dp[idx][rolnum];
    if (ans != -1)
        return ans;
    ans = 987654321;

    // 현재 위치. 윗단계의 나사들이 왼쪽으로 이동했던 것을 반영함.
    int cur = ((from[idx] - '0') + rolnum) % 10;
    int left = ((to[idx] - '0') + 10 - cur) % 10;
    ans = min(ans, DPFunc(idx + 1, (rolnum + left) % 10) + left);
    int right = (cur + 10 - (to[idx] - '0')) % 10;
    ans = min(ans, DPFunc(idx + 1, rolnum) + right);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));

    cin >> N >> from >> to;
    cout << DPFunc(0, 0) << '\n';
    return 0;
}