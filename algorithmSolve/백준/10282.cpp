#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Ǯ��.
// �־����� ���������� ���� ������ �������� �ִ� �Ÿ��� ���� ū���� ���ϴ� ������.
// ���ͽ�Ʈ�� �̿��ϸ� �Ǵµ� �ļ��� �Ѱ��� �Ǽ� ������ ���� ��̴�.
// ���� ��ü�� ����� �ʱ⿡ �����ɰ��� ���� ����.

// �ڼ��� ������ �ּ����� �����.

vector<vector<pair<int, int>>> board;
int T, N, D, C;

// ���ͽ�Ʈ�� �˰��� ���� �Լ�.
void DK()
{
    // �Ÿ��� ª�� �͵��� ���� Ž���ϱ� ���� �켱���� ť.
    priority_queue<pair<int, int>> que;
    que.push(make_pair(0, C));
    vector<int> dis(N + 1, 987654321);
    dis[C] = 0;

    while (!que.empty())
    {
        int cost = -que.top().first;
        int here = que.top().second;
        que.pop();

        // ���� here������ �Ÿ� cost�� ���� �ִܰŸ����� ��ٸ� �����Ѵ�.
        if (cost > dis[here])
            continue;

        // here���� �����Ҽ� �ִ� ��� ������ ��ȸ�Ѵ�.
        for (int i = 0; i < board[here].size(); ++i)
        {
            int there = board[here][i].first;
            int len = board[here][i].second;

            // ���Ⱑ �ٷ� �� �Ǽ��� �κ��̴�. 
            // ���� ���Ѱ��� ���������� ���ų� ª�ٸ� �����ϴ� �� �˾Ҵµ� ª�ƾ����� �����ϴ� ���̾���.
            // ���� ���������� ũ�ų� ���ٸ� �����ؾ��Ѵ�.
            if (cost + len >= dis[there])
                continue;

            // �������� ���簪���� �����ϰ� �Ÿ��� ������ ť�� �ִ´�.
            dis[there] = cost + len;
            que.push(make_pair(-dis[there], there));
        }
    }

    // ��� ������ ��ȸ�ϸ� �Ÿ��� 987654321�̶�� �����ϰ�
    // �׷��� �ʴٸ� ������ ���� 1 ������Ű�� �� �Ÿ������� ���Ѵ�.
    // ���⼭ 987654321�� �ص� �Ǵ� ������ �ִ� ��ǻ���� ������ 10000�̰� �ִ� �Ÿ���
    // 1000 �̱⿡ ��� ������ ���� �� ������ ������ �����ص� �� �Ÿ��� 1000���̱� �����̴�.
    // ���� 1000���� �Ѵ� ���� üũ�Ѵٸ� ���� ����.(Ȯ���غ�)
    pair<int, int> answer = make_pair(0, 0);
    for (int i = 1; i <= N; ++i)
    {
        // �������� ���Ѵٸ� �����Ѵ�.
        if (dis[i] == 987654321)
            continue;

        // �׷��� �ʴٸ� ������ ��ǻ���� ������ 1 ������Ű��
        // ���� ū �ð��� ���Ѵ�.(��� �����Ǿ� �ϹǷ� �׵��� ���� �����ɸ��� �ð��� �˾ƾ��Ѵ�).
        ++answer.first;
        answer.second = max(answer.second, dis[i]);
    }

    cout << answer.first << ' ' << answer.second << '\n';
}

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> N >> D >> C;
        board.resize(N + 1, vector<pair<int, int>>());
        int a, b, s;
        for (int i = 0; i < D; ++i)
        {
            cin >> a >> b >> s;
            board[b].push_back(make_pair(a, s));
        }
        DK();

        for (int i = 0; i <= N; ++i)
            board[i].clear();
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}