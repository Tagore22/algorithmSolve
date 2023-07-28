#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Ǯ��.
// ���ͽ�Ʈ�� �̿��� ���⹮���� �����Ͽ��� Ǯ��� ������ �ڼ����� ����� ���� �ʾҴ�.
// ���ͽ�Ʈ�� ��ü�� ��Ȯ������ ����ؾ��� ������� ��� �����ؾ����� �ָ��ߴ�.
// ������ �����ѵ� �� � �����̵� ���۰� ���� �ִٴ� ���̴�.
// ������ ūƲ�� ������ ����.

// 1. ���ο� ������� �����ؾ��ϴµ� ������ǻ��(1�� ��ǻ��)�� ��� ��ǻ�ʹ� ��, ���������� ����Ǿ� �־�� �Ѵ�.
// 2. �ٸ� ���ο� ������� ������ ����ӵ����� ������ �ȵǹǷ� �ּ� ����ġ�� �����Ͽ� ���� ������ ����Ǿ��־���Ѵ�.
// 3. ��� ��ǻ�͵��� ���� ����Ǿ� �־�� �ϴµ� 1������ ������ǻ�Ͱ� ��� ��ǻ�͵�� ����Ǿ� �����Ƿ�
// �̹� ��� ��ǻ�͵��� ����Ǿ� �ִ�.
// 4. �̷��� ���¸� �����ϰ� �ϴ� �ּ����� ������� ����ؾ� �Ѵ�.

// ���� ��ǻ�Ͱ� �ٸ� ��� ��ǻ�͵�� ����Ǵ� �ּ� ���� ������ �翬�� N - 1�̴�.
// ���� �ϳ��� ���᾿���� ����Ǿ� ������ �Ǳ� �����̴�.
// ���� �� ����ߴ� ������� ���۰� ���� ������ ���Ҵٰ� �ѹ��� ��� ������� ������ָ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

vector<pair<int, int>> board[1001];
int ans[1001];
int N, M;

// ���ͽ�Ʈ�� �˰��� ���� �Լ�.
void DK()
{
    vector<int> dist(N + 1, 987654321);
    dist[1] = 0;
    priority_queue<pair<int, int>> que;
    que.push(make_pair(0, 1));

    while (!que.empty())
    {
        int cost = -que.top().first;
        int here = que.top().second;
        que.pop();

        // cost�� ���� here������ �ּұ��̺��� ��ٸ� �����Ѵ�.
        if (dist[here] < cost)
            continue;

        // here���� ���� �ִ� ��� ���� ������.
        for (auto& next : board[here])
        {
            int there = next.first;
            int len = next.second;

            // cost + len�� ������ there������ �ּұ��̺��� ª�ٸ� �����Ѵ�.
            if (cost + len < dist[there])
            {
                dist[there] = cost + len;
                que.push(make_pair(-dist[there], there));
                // ������ǻ�Ϳ��� there������ ������ here�� ���ļ� ����ȴ�.
                ans[there] = here;
            }
        }
    }
}

void MakeAnswer()
{
    DK();
    // �� ����Ͽ��� ��� �ּ� ������ N - 1�̴�.
    cout << N - 1 << '\n';
    // ��� ������� ��ȸ�ϸ� ���۰� ���� ����Ѵ�.
    for (int i = 2; i <= N; ++i)
        cout << i << ' ' << ans[i] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    int a, b, c;
    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b >> c;
        board[a].push_back(make_pair(b, c));
        board[b].push_back(make_pair(a, c));
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}