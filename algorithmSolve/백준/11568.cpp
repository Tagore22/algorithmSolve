#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이.
// 오랜만에 LIS였는데 잘 기억이 나지 않아 조금 헤맸다. 요약하자면, 배열을 순회하되
// 벡터가 비었거나 현재 값이 벡터의 가장 큰값보다 크다면 벡터의 마지막에 집어넣고
// 그렇지 않다면 맞는 정렬된 위치값을 찾아 덮어쓰는 것이다. 덮어쓴다는 부분이 잘 기억이
// 나질 않았다.

int N;
const int MAX = 1000;
int board[MAX];
vector<int> ans;

void Solve()
{
    for (int i = 0; i < N; ++i)
    {
        if (ans.empty() || ans.back() < board[i])
        {
            ans.push_back(board[i]);
        }
        else
        {
            int idx = lower_bound(ans.begin(), ans.end(), board[i]) - ans.begin();
            ans[idx] = board[i];
        }
    }
    cout << ans.size() << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    Solve();
    return 0;
}