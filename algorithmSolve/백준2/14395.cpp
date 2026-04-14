// 1. 답이 0인 경우를 먼저 가지치기한다. s == t라면 0이다.
// 2. 그 이외에는 무조건 답이 존재하는 경우이기에 3가지 연산을 모두 계산한다.
// 3. DP를 구성하기 애매하니 unordered_map을 써보자.
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

// 풀이.
// 처음에는 백트래킹 같은 것을 생각했다. 하지만 이건 제대로 문제 내용을
// 기억하지 못한것이다. 가장 최소한의 방식 + 사전순으로 가장 앞에 오는
// 문자열을 찾아야 하기 때문이다. 따라서 백트래킹이 아닌 BFS를 이용해야했다.
// 문제를 풀 당시에는 -1이 되는 조건들에 대해 굉장히 복잡하고 어렵게 접근했는데
// 잘 생각해보면 수가 증가하는 연산 2개, 0이 되는 연산 1개, 1이 되는 연산 1개로써
// 만약 현재 수가 t보다 커진다면 손을 쓸 수가 없다. 따라서 현재 수가 t보다 작다면
// 무시하는 조건을 건다면 수월하게 처리할 수 있다.

int s, t;
unordered_map<long long, int> dp;

void BFS()
{
    queue<pair<long long, string>> que;
    que.push({ s, "" });
    dp[s] = 1;

    while (!que.empty())
    {
        long long cur = que.front().first;
        string str = que.front().second;
        que.pop();

        if (cur == t)
        {
            cout << str << '\n';
            return;
        }
        if (!dp.count(cur * cur) && cur * cur <= t)
        {
            dp[cur * cur] = 1;
            que.push({ cur * cur, str + "*" });
        }
        if (!dp.count(cur + cur) && cur + cur <= t)
        {
            dp[cur + cur] = 1;
            que.push({ cur + cur, str + "+" });
        }
        if (!dp.count(1))
        {
            dp[1] = 1;
            que.push({ 1, str + "/" });
        }
    }
    cout << -1 << '\n';
}

int main()
{
    cin >> s >> t;

    if (s == t)
    {
        cout << 0 << '\n';
        return 0;
    }

    BFS();
    return 0;
}