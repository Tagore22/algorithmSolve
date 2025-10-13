#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

// Ǯ��.
// ó������ ���Ʈ���� �� DP�� �����س������ �ϳ� �ɷȴ�. ����� ������ ������.
// �Ǹ��� �� Ǯ������ DP�� ����������� �����Ͽ��⿡ ����� ���ȴ�.
// up_down ������� �����ϸ� �ξ� �� ������.

int N;
int dp[300001];
vector<int> board;

int DPFunc(int num)
{
    if (num == 0)
        return 0;

    int& ans = dp[num];
    if (ans != -1)
        return ans;

    ans = 300001;
    for (int i = 0; i < board.size(); ++i)
    {
        if (board[i] > num)
            break;
        ans = min(ans, DPFunc(num - board[i]) + 1);
    }
    return ans;
}

int main()
{
    cin >> N;
    memset(dp, -1, sizeof(dp));
    int plus = 1, sum = 0, cur = 0;
    while (true)
    {
        cur += plus;
        sum += cur;
        if (sum > N)
            break;
        board.push_back(sum);
        ++plus;
    }
    cout << DPFunc(N) << '\n';
    return 0;
}