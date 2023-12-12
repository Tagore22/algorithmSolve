#include <iostream>
#include <vector>

using namespace std;

// Ǯ��.
// �ͼ�ġ ���� �ּ� ���д� Ʈ�� ��������. �� �״�� Ʈ���� �̷�� �ּ� ����ġ�� ���ϴ� �˰����̴�.
// ���� �˰����� �̿��Ͽ�����, �켱���� ť�� �̿������� �ʾұ⿡ �ð��� ���� �ɸ���.
// ũ�罺Į�̳� �켱���� ť�� �̿��Ͽ��߰ڴ�.

// �ڼ��� ������ �ּ����� �����.

vector<vector<pair<int, int>>> board;
int M, N, answer;

// �ּ� ���д� Ʈ���� ���ϴ� ���� �˰���.
void Prim()
{
    // ��� �ּ� ����ġ�� �ִ�� �ʱ�ȭ��Ų��.
    vector<int> dist(M, 987654321);
    // �������� ����ġ�� 0���� �����Ѵ�.(���Ƿ� ��Ʈ�� �����ص� �Ǹ� ���⼭ ����ġ�� �θ��������� ���� ����������
    // ����ġ�� ���ϱ⿡ ��Ʈ�� dist[0]�� 0�� �ȴ�.)
    dist[0] = 0;
    vector<bool> visit(M, false);

    // �Ź� �� ������ Ʈ���� �߰��ϱ� ������ ��������� ������ ����ŭ�� �ݺ��ϸ� �ȴ�.
    for (int iter = 0; iter < M; ++iter)
    {
        int u = -1;
        // ��� ������ ��ȸ�Ѵ�.
        for (int v = 0; v < M; ++v)
            // ���� ������ Ʈ���� ���� ������ ���� ù��° �����̰ų�, ������� �������� ����ġ����
            // ���۴ٸ� ���� ������ �����Ѵ�.
            if (!visit[v] && (u == -1 || dist[u] > dist[v]))
                u = v;

        // �� ������ ������ ��� ����ġ���� �ּ� ����ġ���� ���� �����Ͽ��� �ϱ⿡ -= ������ ����Ѵ�.
        answer -= dist[u];
        // ���� ����ġ�� ���� ���� ������ Ʈ���� ���Խ�Ų��.
        visit[u] = true;
        // ���� �������� �����Ҽ� �ִ� ��� ������ ��ȸ�Ѵ�.
        for (int i = 0; i < board[u].size(); ++i)
        {
            int v = board[u][i].first;
            int cost = board[u][i].second;
            // v�� ���� Ʈ���� �������� �ʾ����� v�� �ּ� ����ġ��
            // cost���� ũ�ٸ� dist[v]�� �����Ѵ�.
            if (!visit[v] && dist[v] > cost)
                dist[v] = cost;
        }
    }
    cout << answer << '\n';
}

void MakeAnswer()
{
    while (true)
    {
        cin >> M >> N;
        if (M == 0 && N == 0)
            return;

        answer = 0;
        board.clear();
        board.resize(M, vector<pair<int, int>>());
        int from, to, dist;
        for (int i = 0; i < N; ++i)
        {
            cin >> from >> to >> dist;
            board[from].push_back(make_pair(to, dist));
            board[to].push_back(make_pair(from, dist));
            answer += dist;
        }

        Prim();
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}