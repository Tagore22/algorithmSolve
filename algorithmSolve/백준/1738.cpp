#include <iostream>
#include <vector>

using namespace std;

// Ǯ��.
// ��� �Ǽ��� �ؼ� Ǫ�µ� ���� �ɷȴ�. ���⸦ ����� ����.
// �Ʒ� Ǯ�̸� ������ڸ� ������ ����.

// 1. ����-���� �˰����� ����ؼ� 1�� �������� �� ���������� ����ġ�� N�� ��ȭ�س�����.
// 2. ����-���� �˰��� �ǰ��Ͽ� ������ N�������� ��ȭ�� �Ͼ�ٸ� ���� ����Ŭ�� �����ϴ� ���̰�
// �̶� N�� ���������� ��ȭ�� �Ͼ�ٸ� �������� ���� ����Ŭ�� �����ϱ⿡ ����� �� ���� ���Ҽ� ����
// -1�� ����ؾ��Ѵ�.
// 3. �Լ� ȣ�� ������ ���� ������ ����.
// 3-1. ���������� �����Ҽ��� ���� ���. -1�� ���.
// 3-2. ���������� ������ �����ϳ� ���� ����Ŭ�� �ִ� ���. -1�� ���
// 3-3. ���������� ������ �����ϸ鼭 ���� ����Ŭ�� ���� ���. 

// �� ��쿡 ���� ���� ����ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

vector<pair<int, int>> board[101];
int p[101], dist[101];
int N, M;
const int MAXNUM = 987654321;

// ����-���� �˰����� �����ϴ� �Լ�.
void BF()
{
    for (int i = 1; i <= N; ++i)
        dist[i] = MAXNUM;
    dist[1] = 0;

    // N���� ��ȭ������ ��ģ��. ���� ������ N��°���� ��ȭ�� �Ͼ�ٸ�
    // ���� ����Ŭ�� �������� �ǹ��Ѵ�.
    for (int iter = 0; iter < N; ++iter)
    {
        // 1������ N�� �������� ��� ��ȸ�Ѵ�.
        for (int here = 1; here <= N; ++here)
        {
            // �� �������� �����Ҽ� �ִ� ��� ������ ��ȸ�Ѵ�.
            for (int next = 0; next < board[here].size(); ++next)
            {
                int there = board[here][next].first;
                int cost = board[here][next].second;

                // ��ȭ�� �����ϴٸ� �Ÿ����� �����ϰ� �迭 p�� �θ��� �����Ѵ�.
                if (dist[there] > dist[here] + cost)
                {
                    dist[there] = dist[here] + cost;
                    p[there] = here;
                    // ������ N��°���� �������� ���� ����Ŭ�� �߰ߵǸ� üũ�س��´�.
                    if (iter == N - 1)
                        dist[there] = -MAXNUM;
                }
            }
        }
    }
}

void MakeAnswer()
{
    BF();

    // ���������� �����Ҽ� ���ų�, �������� ���� ����Ŭ�� �����Ѵٸ� -1�� ����Ѵ�.
    if (dist[N] == MAXNUM || dist[N] == -MAXNUM)
    {
        cout << -1 << '\n';
        return;
    }
    // �θ� p�� ����ȸ�ϸ� ��θ� ã�� ����Ѵ�.
    int cur = N;
    vector<int> answer;
    while (cur != 0)
    {
        answer.push_back(cur);
        cur = p[cur];
    }
    for (int i = answer.size() - 1; i >= 0; --i)
        cout << answer[i] << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        board[from].push_back(make_pair(to, -cost));
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}