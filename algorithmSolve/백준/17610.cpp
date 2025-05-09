#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 문제에서 최종적으로 원하는 것은 주어진 추 무게를 이용하여 만들 수 있는 모든 수의 개수를 알아야한다.
// 이 부분에서 좀 막혔다. 결과적으로는 아래 풀이처럼 DFS 혹은 백트래킹을 사용하여 더하거나, 빼거나,
// 사용하지 않고 넘어가거나 이 3가지를 모두 대입하여 푸는 방식이다. 3가지 경우가 최대 13번 주어지므로
// 연산량은 3의 13제곱으로 150만이 조금 넘게 된다.

vector<bool> choose(2600000);
int board[13];
int K, sum = 0, answer = 0;

void DFS(int idx, int w)
{
    if (idx == K)
    {
        if (w > 0)
            choose[w] = true;;
        return;
    }

    DFS(idx + 1, w + board[idx]);
    DFS(idx + 1, w - board[idx]);
    DFS(idx + 1, w);
}

void Solve()
{
    DFS(0, 0);

    for (int i = 1; i <= sum; ++i)
        if (!choose[i])
            ++answer;
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> K;
    for (int i = 0; i < K; ++i)
    {
        cin >> board[i];
        sum += board[i];
    }
}

int main()
{
    Input();
    Solve();
    return 0;
}