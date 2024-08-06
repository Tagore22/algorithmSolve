#include <iostream>

using namespace std;

// Ǯ��.
// ���� �쿬���� MST ������ ���޾� ���ͼ� ��û ���� Ǯ����. ���� �����ؾ��� �͵� ����
// �׳� MST�� �ȴٸ� �״�� �����ϱ⸸ �ص� �� ��������. ���� ��� �������� �ڵ尡 ���Ҵ���
// �ڵ嵵 ���� �ſ� ������ ���ư��� ���� 7� ��ġ�ߴ�. 1368���� 1���� �����ѰͿ� ���̾�
// ����� ���Ҵ�.

// �ڼ��� ������ �ּ����� �����.

int board[1000][1000];
int N;

// MST�� ���ϴ� ���� �˰��� �Լ�. ���� �ٸ��� ����
// �⺻���� �������� �Ǿ��ִ�.
void Prim()
{
    int dist[1000];
    for (int i = 0; i < N; ++i)
        dist[i] = 987654321;
    dist[0] = 0;
    bool visit[1000] = { false, };
    long long answer = 0;

    for (int iter = 0; iter < N; ++iter)
    {
        int u = -1;
        for (int i = 0; i < N; ++i)
            if (!visit[i] && (u == -1 || dist[i] < dist[u]))
                u = i;

        visit[u] = true;
        answer += dist[u];

        for (int i = 0; i < N; ++i)
            if (!visit[i] && board[u][i] < dist[i])
                dist[i] = board[u][i];
    }
    cout << answer << '\n';
}

void MakeAnswer()
{
    Prim();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}