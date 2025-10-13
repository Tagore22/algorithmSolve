#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

// 풀이.
// 처음에는 브루트포스 등 DP를 생각해내기까지 꽤나 걸렸다. 컨디션 조절을 잘하자.
// 훌륭히 잘 풀었으나 DP를 재귀형식으로 구현하였기에 상당히 느렸다.
// up_down 방식으로 구현하면 훨씬 더 빠르다.

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