#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> cashe;
int N, K;
const int DIVNUM = 1000000003;

int DP(int idx, int num)
{
    if (idx <= 0 || idx < num * 2)
        return 0;
    if (num == 1)
        return idx;
    int& ans = cashe[idx][num];
    if (ans != -1)
        return ans;
    return ans = (DP(idx - 2, num - 1) + DP(idx - 1, num)) % DIVNUM;
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    cashe.assign(N + 1, vector<int>(K + 1, -1));
}

int main()
{
    Input();
    cout << DP(N, K) << '\n';
    return 0;
}