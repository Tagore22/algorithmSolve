#include <iostream>
#include <vector>

using namespace std;

// Ǯ��.
// ���� ���Ե� ���� Ǯ���� �ּ� ���д� Ʈ�� ������ �ǳ��Դ�.
// �⺻�����δ� ũ�� ���̰� ������ 2���� �������� �����ߴ�.

// 1. �� �ּ����� ����ġ�� �������� ���б� -> ���б� Ȥ�� ���б� -> ���б��� ������ �Ұ�����.
// 2. Ʈ���� �������� ���� ��츦 ���ؾ���.

// 1��°�� ũ�� ����� �ʾҴ�. �б�����ŭ �迭�� �ϳ� ���� ���б��� ���б��� ���̸� ����
// ���� ���� u���� ���ް����� v�� ��ȸ�Ҷ� ���б��� ������ �ٸ����� ���ϸ� �ƴ�.
// 2��°�� ���� �򰥷ȴµ� ��������δ� �� �б����� �ּ� ����ġ�� Ȯ���ϴ� ���̴�.
// ��â�⿡ 987654321���� ���� ū ���� �� �� ��� ��������ŭ�� ��ȸ�� ���� ����
// �ּ� ����ġ�� �״�� 987654321�̶�� ���޵� �̵��� �Ұ����� ���̹Ƿ� Ʈ���� �̷�� ����.

// �ڼ��� ������ �ּ����� �����.

vector<vector<pair<int, int>>> board;
bool isMan[1001];
int N, M;

void MakeAnswer()
{
    // ��� �ּ� ����ġ���� ����.
    int answer = 0;
    vector<int> min_dist(N + 1, 987654321);
    min_dist[1] = 0;
    vector<bool> visit(N + 1, false);

    // �Ź� �ϳ��� ������ Ʈ���� �߰��ϱ� ������ ��������� ������ ����ŭ ��ȸ�Ѵ�.
    for (int iter = 0; iter < N; ++iter)
    {
        int u = -1;
        // �ٸ� ��� �������� ��ȸ�ϸ� �̹��� �߰��� ������ ã�´�.
        for (int v = 1; v <= N; ++v)
            // ���� Ʈ���� �߰����� ���� ù��° �����̰ų�, ���� �������� �ּ� ����ġ�� ���ٸ�
            // ���� ������ ����ȴ�.
            if (!visit[v] && (u == -1 || min_dist[u] > min_dist[v]))
                u = v;

        // ���� ������ �ּ� ����ġ�� �߰��ϰ� Ʈ���� �߰��Ѵ�.
        answer += min_dist[u];
        visit[u] = true;

        // ���� ���� u���� ���ް����� ��� �������� ��ȸ�Ѵ�.
        for (int i = 0; i < board[u].size(); ++i)
        {
            int v = board[u][i].first;
            int cost = board[u][i].second;
            // ���� Ʈ���� �߰����� ���� �������� u���� �̵��� ����ġ�� ������ �ּ� ����ġ���� ������
            // �� -> �� Ȥ�� �� -> ���� �ƴҶ� �ּҰ���ġ�� ���� ����ġ�� �����Ѵ�.
            if (!visit[v] && min_dist[v] > cost && isMan[u] != isMan[v])
                min_dist[v] = cost;
        }
    }
    // ��� �������� ��ȸ�Ѵ�.
    for (int i = 1; i <= N; ++i)
    {
        // ���� ������ �ּ� ����ġ�� 987654321�̶�� ��,
        // ���� �������� �̵����� ���ϴ� ��� Ʈ���� ���������.
        if (min_dist[i] == 987654321)
        {
            cout << -1 << '\n';
            return;
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    char p;
    for (int i = 1; i <= N; ++i)
    {
        cin >> p;
        isMan[i] = p == 'M' ? true : false;
    }
    board.resize(N + 1, vector<pair<int, int>>());
    int from, to, dist;
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to >> dist;
        board[from].push_back(make_pair(to, dist));
        board[to].push_back(make_pair(from, dist));
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}