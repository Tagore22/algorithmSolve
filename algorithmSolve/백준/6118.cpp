#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Ǯ��.
// �׷��� Ž�� �����̴�. 1������ �����Ҷ� ���� �� ��ġ�� ���̿� ���� �� ��ġ���� ����, ���� �� ��ġ����
// ���� ���� ���� ��ȣ�� ����Ͽ��� �Ѵ�. ���ͽ�Ʈ�� �˰������� Ǯ�� ����� �ʴ�.
// ������ ū Ʋ�� ������ ����.

// 1. ���ͽ�Ʈ�� �˰������� �� ��ġ�� ���̸� �����س�����.
// 2. ��ȸ ���� ���� �� ��ġ�� max_num�� ������ ������.
// 3. ��ȸ�� ������ 1������ N������ �ٽ� ��ȸ�� �ϸ� ���� ù��°�� max_num�� ���ϴ� �� ans�� ã�´�.
// �� �� ��� N���� ��ȸ�ϸ� max_num�� ���� ���� ���ҵ��� �� num�� ã�´�.
// 4. ������� ans, max_num, num�� ����Ѵ�.

// �ڼ��� ������ �ּ����� �����.

vector<vector<int>> way;
int N, M;

// ���ͽ�Ʈ�� �˰����� ������ �Լ�.
void DK()
{
    priority_queue<pair<int, int>> que; // �Ÿ�, ��ġ.
    que.push(make_pair(0, 1));
    vector<int> dis(N + 1, 987654321);
    dis[1] = 0;
    int max_num = 0;

    while (!que.empty())
    {
        int cost = -que.top().first;
        int here = que.top().second;
        que.pop();

        // ���� ã�� ���̰� ������ ���̺��� ��ٸ� �����Ѵ�.
        if (cost > dis[here])
            continue;

        // ���� ��ġ���� ���� �ִ� ������ ������.
        for (int i = 0; i < way[here].size(); ++i)
        {
            int there = way[here][i];
            // ���� ���̰� ������ ���̺��� �����ٸ� �����Ѵ�.
            if (dis[there] > cost + 1)
            {
                dis[there] = cost + 1;
                // ����� 2��. �ִ���� max_num�� �����Ѵ�.
                max_num = max(max_num, dis[there]);
                que.push(make_pair(-dis[there], there));
            }
        }
    }

    bool isfind = false;
    int num = 0, ans;
    for (int i = 1; i <= N; ++i)
    {
        if (dis[i] == max_num)
        {
            // ����� 3���� max_num�� ���� ������ �� num�� ���� �����Ѵ�.
            ++num;
            if (!isfind)
            {
                // ����� 3���� ���� ù��°�� max_num�� ������ �� ans�� ã�´�.
                ans = i;
                isfind = true;
            }
        }
    }

    cout << ans << ' ' << max_num << ' ' << num << '\n';
}

void MakeAnswer()
{
    //���⼭ bfs ����.
    DK();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    way.resize(N + 1, vector<int>());
    int from, to;
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to;
        way[from].push_back(to);
        way[to].push_back(from);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}