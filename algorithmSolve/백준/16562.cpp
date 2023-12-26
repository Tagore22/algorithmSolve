#include <iostream>
#include <vector>

using namespace std;

// Ǯ��.
// ��� ģ����� ģ���� �� ��� �䱸�Ǵ� �ּ����� ģ���� ����ϴ� ������.
// ģ���� ģ���� ��¥��� ���� ģ���� ������ ���� ��� �� �����߿��� ���� ���� ģ���� ã����
// �� ������ ��ο� ģ���� �ȴٴ� ���� ���Ѵ�. �� 1������ N������ ģ���� ��� ��ȸ�ϸ� �����Ҽ� �ִ�
// ģ������ ���� ���� ģ���� ���� ���س����� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int cost[10001];
vector<vector<bool>> board;
vector<bool> visit;
int N, M, K, point;

// �� ģ���� ģ������ ��ȸ�ϴ� �Լ�.
void DFS(int here)
{
    // ���� ģ���� �ٸ� ģ������ ��� ��ȸ�Ѵ�.
    for (int there = 1; there <= N; ++there)
    {
        // �̹� �湮�� ģ���ų� ģ�� ���̰� �ƴ϶�� �����Ѵ�.
        if (visit[there] || !board[here][there])
            continue;
        // ���� ������ ģ������� �ּҰ��� �����Ѵ�.
        point = min(point, cost[there]);
        visit[there] = true;
        DFS(there);
    }
}

void MakeAnswer()
{
    int answer = 0;
    // ��� ģ������ ��ȸ�Ѵ�.
    for (int iter = 1; iter <= N; ++iter)
    {
        // ���� ģ���� ���� �湮���� ���� ģ�����.
        if (!visit[iter])
        {
            // ģ������ �ּҰ��� ���� ģ���� ģ�������� �����Ѵ�.
            point = cost[iter];
            visit[iter] = true;
            DFS(iter);

            // ģ������ �ּҰ��� ���� ���� ������ ���ٸ� ��� ģ������ ��м� ����.
            if (point > K)
            {
                cout << "Oh no" << '\n';
                return;
            }
            // ģ������ �ּҰ��� ������ answer�� ���Ѵ�.
            answer += point;
            // ���� ���� ���� �����Ѵ�.
            K -= point;
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;
    board.resize(N + 1, vector<bool>(N + 1, false));
    visit.resize(N + 1, false);
    for (int i = 1; i <= N; ++i)
        cin >> cost[i];
    int from, to;
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to;
        board[from][to] = true;
        board[to][from] = true;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}