#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// 우선순위 큐를 이용한 풀이. 정렬은 알아서 되기에 신경쓰지 않고
// 현재 가장 작은 수가 구하려는 범위밖인지만 확인해가며 가장 작은 수를 출력한다.
// push(), pop()의 시간복잡도가 로그이기 때문에 총 NlogN의 연산량을 필요로 하는데
// N의 최대값이 500만이기 때문에 1억을 살짝 넘어 시간이 아슬아슬하다.

int board[5000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, L;
    cin >> N >> L;
    for (int i = 0; i < N; ++i)
        cin >> board[i + 1];
    priority_queue<pair<int, int>> que;
    for (int i = 1; i <= N; ++i)
    {
        que.push(make_pair(-board[i], i));
        while (que.top().second < i - L + 1)
        {
            que.pop();
        }
        cout << -que.top().first << ' ';
    }
    return 0;
}