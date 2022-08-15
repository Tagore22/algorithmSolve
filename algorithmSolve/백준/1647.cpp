#include <iostream>
#include <vector>
#include <queue>

using namespace std; //����� �׷���, ������ 1������ N������.

vector<vector<pair<int, int>>> board;
int N, M;

//������ �ð����⵵���� V������ + E�δ� ������ �ذ����� ���Ͽ� �켱���� ť�� �̿��ϴ� ���ͽ�Ʈ�� ������ ������ ����
//�Ͽ���. ó�� �غ��°ǵ� ������ �Ÿ��� �� ��� �� ���� ������ ���� �ſ� ����������.

void Prim()
{
    priority_queue<pair<int, int>> que;
    for (int i = 0; i < board[1].size(); ++i)
    {
        int there = board[1][i].first;
        int cost = board[1][i].second;
        que.push(make_pair(-cost, there));
    }
    vector<bool> check(N + 1, false);
    check[1] = true;
    int answer = 0;
    int max_cost = 0;
    while (!que.empty())
    {
        int cost = -que.top().first;
        int here = que.top().second;
        que.pop();

        if (check[here])
            continue;

        check[here] = true;
        answer += cost;
        max_cost = max(max_cost, cost);//������ ���ϴµ����� ���� �ʿ� ������, ������ ���� ������ ã�� ���� �߰���.
        for (int i = 0; i < board[here].size(); ++i)
        {
            int there = board[here][i].first;
            int len = board[here][i].second;

            if (!check[there])
                que.push(make_pair(-len, there));
        }
    }
    cout << answer - max_cost << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    board.resize(N + 1, vector<pair<int, int>>());
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        board[a].push_back(make_pair(b, c));
        board[b].push_back(make_pair(a, c));
    }
}

int main()
{
    Input();
    Prim();
    return 0;
}