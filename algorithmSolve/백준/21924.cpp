#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Ǯ��.
// ������ ������ MST������� ���� �˾�ç�� �־���. �ٸ� �Ѱ��� ������ �־��µ� �����Ͽ� �����ִ�
// ���� Ǯ�̷δ� �ð��ʰ��� �ɸ��ٴ� ���̾���. ���� ���̰� ������. �׷��� �����ϰ� ���� ���� �ִ�
// �켱���� ť�� �̿��� ������ �̿��ؾ� �ߴ�. �������� ������ Ǯ���� ���� �־��� �״�� �����ߴ�.
// ������ ������ �� ����� ����ؾ߰ڴ�. ������ ���� �������� �� ª�� ������ ������ �ִ�.

// �ڼ��� ������ �ּ����� �����.

vector<pair<int, int>> board[100001];
int N, M;
long long answer = 0;

void Prim()
{
    // ���������� �������� �ʰ� ���������� �����Ҽ� �ִ� ��� �������� �����Ѵ�.
    priority_queue<pair<int, int>> que;
    for (auto& here : board[1])
    {
        int cur = here.first;
        int cost = here.second;
        que.push(make_pair(-cost, cur));
    }
    bool visit[100001] = { false, };
    visit[1] = true;
    long long ans = 0;

    while (!que.empty())
    {
        int cost = -que.top().first;
        int here = que.top().second;
        que.pop();

        if (visit[here])
            continue;

        // �̰��� �Ʒ� for������ if���� �ű�°� �� �������� ���� ������ ����������
        // �׷��� ����� �۵����� �ʴ´�. �켱���� ť�� �̿��ϱ� ������ �ϴ� ���ް�����
        // ��� �������� ť�� �ְ� ���� ���� ������ ���� �������� �湮���θ� �����ϱ� �����̴�.
        visit[here] = true;
        ans += cost;

        for (auto& next : board[here])
        {
            int there = next.first;
            int dist = next.second;
            if (!visit[there])
                que.push(make_pair(-dist, there));
        }
    }
    for (int i = 1; i <= N; ++i)
        if (!visit[i])
        {
            cout << -1 << '\n';
            return;
        }
    cout << answer - ans << '\n';
}

void MakeAnswer()
{
    Prim();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    int from, to, dist;
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to >> dist;
        board[from].push_back(make_pair(to, dist));
        board[to].push_back(make_pair(from, dist));
        answer += dist;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}