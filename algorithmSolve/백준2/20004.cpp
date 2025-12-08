#include <iostream>
#include <cstring>

using namespace std;

int dp[32][32];
int A;

int DFS(int idx, int num)
{
    if (idx <= 0)
        return 1;

    int& ans = dp[idx][num];
    if (ans != -1)
        return ans;
    ans = 0;
    for (int i = 1; i <= num; ++i)
        ans |= (!DFS(idx - i, num));
    return ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> A;
    for (int i = 1; i <= A; ++i)
        if (!DFS(31, i))
            cout << i << '\n';
    return 0;
}