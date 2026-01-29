#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 막연하게 생각하다가 LIS가 떠올랐다. 직접 대입해보니 잘되었고
// 꽤 많이 해봤기에 어렵지 않게 구현하였다. 정말 최악의 경우에
// 모든 자리에서 이분 탐색을 해야하여 Nlogn을 해도 100(T의 최대값) *
// 10000(N의 최대값) * 14(100만의 로그값)을 하여 1400만밖에 나오지 않는다.

int T, N, K;
int board[10000];

bool MakeNum()
{
    vector<int> cur;
    for (int i = 0; i < N; ++i)
    {
        // 맨 뒷값보다 크다면 추가한다.
        if (cur.empty() || cur.back() < board[i])
        {
            cur.push_back(board[i]);
        }
        // 그렇지 않다면 이분 탐색을 이용해 맞는 자리를 찾아 덮어쓴다.
        else
        {
            int idx = lower_bound(cur.begin(), cur.end(), board[i]) - cur.begin();
            cur[idx] = board[i];
        }
    }
    return cur.size() >= K;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> N >> K;
        for (int i = 0; i < N; ++i)
            cin >> board[i];
        cout << "Case #" << iter + 1 << '\n';
        if (MakeNum())
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
    return 0;
}