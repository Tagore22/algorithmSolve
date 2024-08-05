#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 처음에는 BFS로 풀려고 했던 문제이다. 그래프가 트리형식에 가까우니 가장 말단 노드부터 시작해서
// 하나씩 쭉쭉 올라가면서 계산하려고 했다. 그런데 뭐 때문인지 1퍼센트에서 올라가질 않았고
// DFS로 풀기로 했다. 우선 부모 자식관계를 구축하여 후에 순회를 위한 밑작업을 하였다.
// 그 이후 DFS로 1번 노드부터 내려가면서 계산해 준다. 무엇보다 헷갈린건 늑대가 잡아먹는 방식이었는데
// 매번 잡아먹는게 아니라 모든 순간을 통틀어 한마리의 늑대가 딱 한번만 잡아먹는다는 것이었다.
// 출제자 역시 모호하다며 인정한 부분이다. 그래서 그런지 정답율이 30퍼도 안된다.

// 자세한 설명은 주석으로 남긴다.

struct island
{
    char animal;
    int num;
    int path;
};

island board[123457];
vector<int> child[123457];
int N;

// idx번째 노드부터 마지막 노드까지 양의 수를 구하는 함수.
long long DFS(int idx)
{
    // 말단 노드에 도착하였다면 그곳이 늑대가 산다면 0을, 양이 산다면 양의 수를 반환한다.
    if (child[idx].size() == 0)
    {
        if (board[idx].animal == 'W')
            return 0;
        else
            return board[idx].num;
    }

    long long ans = 0;
    // 모든 양의 수를 구한다.
    for (auto& n : child[idx])
        ans += DFS(n);

    // 이 문제의 가장 큰 문제인데 늑대가 양을 딱 한마리만 잡아먹는다. 매번 한마리가 아니라
    // 모든 순간에 딱 한마리다. 따라서 모든 양의 수를 구한후 거기에서 딱 한번만 늑대의 수를 뺀다.
    if (board[idx].animal == 'W')
        ans -= board[idx].num;
    else
        ans += board[idx].num;

    // 만약 늑대가 더 많아서 음수의 값이 된다면 양은 없으므로 0을 반환한다.
    return ans >= 0 ? ans : 0;
}

void MakeAnswer()
{
    cout << DFS(1) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 2; i <= N; ++i)
    {
        cin >> board[i].animal >> board[i].num >> board[i].path;
        // 상술한 부모 자식관계 구축. 부모관계는 이미 주어지므로 구할 필요가 없다.
        child[board[i].path].push_back(i);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}