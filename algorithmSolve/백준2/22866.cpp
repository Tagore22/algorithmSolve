#include <iostream>
#include <stack>

using namespace std;

// 풀이.
// 문제를 푸는 로직 자체는 금방 생각났는데 디테일이 좀 떨어져서 메모리 초과로 이어졌다.
// 처음에는 스택을 이용하여 왼쪽으로 한번 오른쪽으로 한번씩 순회하며 모든 건물들을 저장
// 하였는데 상술하였듯 메모리 초과로 이어졌다. 이번 로직은 조금 달라졌는데 똑같이 왼쪽,
// 오른쪽으로 순회를 하되, 보이는 건물들의 수를 더하고, 가장 가까운 즉, 큐의 가장 위에
// 있는 건물의 번호를 가지고 계산을 하였다. 다만 스택이 0일 때 등 주의해야 할 것들이
// 몇가지 존재하였다.

// 자세한 설명은 주석으로 남긴다.

int N;
int board[100001];
pair<int, int> answer[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> board[i];

    stack<pair<int, int>> sta;
    // 왼쪽부터 순회.
    for (int i = 1; i <= N; ++i)
    {
        // 현재 건물의 높이보다 작거나 같은 건물들은 모두 제외한다.
        while (!sta.empty() && sta.top().second <= board[i])
        {
            sta.pop();
        }
        // 만약 볼 수 있는 건물이 없을 경우는 무시한다. 지금은 최초의 순회이기 때문에
        // 모든 값들이 0으로 초기화된 상태이므로 가장 가까운 건물도 그냥 대입만 하면 된다.
        if (sta.size() != 0)
            answer[i] = make_pair(sta.size(), sta.top().first);
        sta.push(make_pair(i, board[i]));
    }
    while (!sta.empty())
    {
        sta.pop();
    }
    // 오른쪽부터 순회. 한군데를 제외하고는 왼쪽과 동일하다.
    for (int i = N; i > 0; --i)
    {
        while (!sta.empty() && sta.top().second <= board[i])
        {
            sta.pop();
        }
        answer[i].first += sta.size();
        // 더하기만 하면 되는 건물의 수들과는 달리 가장 가까운 건물은 이전 순회에서
        // 찾았을 수도 있기 때문에 이번에 찾을 가장 가까운 건물과 무엇이 더 가까운지
        // 계산해보아야 한다. 이번 풀이에서는 간단히 i와의 거리를 이용했다.
        if (sta.size() != 0)
        {
            if (answer[i].second == 0)
                answer[i].second = sta.top().first;
            else
                answer[i].second = i - answer[i].second > sta.top().first - i ? sta.top().first : answer[i].second;
        }
        sta.push(make_pair(i, board[i]));
    }
    for (int i = 1; i <= N; ++i)
    {
        if (answer[i].first == 0)
            cout << 0 << '\n';
        else
            cout << answer[i].first << ' ' << answer[i].second << '\n';
    }
    return 0;
}