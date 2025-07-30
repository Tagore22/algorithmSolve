#include <iostream>
#include <queue>

using namespace std;

// Ǯ��.
// �� ¡�˴ٸ����� �̵��� ¡�˴ٸ��� �����ִ� ���� �����ŭ �̵��ϴ� ����
// �����ؾ� �ϴ� ������. ���� Ȥ�� ���������� �̵��ؾ��ϴµ� �󸶸�ŭ �̵�
// �� �� �ִ��� �� �� ���⿡ �κκ����� ������߸� �ߴ�.

// �ڼ��� ������ �ּ����� �����.

int N, a, b;
int board[10001], visit[10001];

void BFS()
{
    queue<int> que;
    que.push(a);
    // �� ¡�˴ٸ��� ������ �ּ� ������ �ʱ�ȭ.
    for (int i = 1; i <= N; ++i)
        visit[i] = 987654321;
    visit[a] = 0;
    int answer = 0;

    while (!que.empty())
    {
        ++answer;
        int qsize = que.size();
        for (int iter = 0; iter < qsize; ++iter)
        {
            int here = que.front();
            que.pop();

            // ���������� �̵��� ���.
            for (int i = 1; ; ++i)
            {
                int next = here + board[here] * i;
                // b�� �����Ͽ��ٸ� ���̻��� ������� �ּҰ� answer�� ����� Ż���Ѵ�.
                if (next == b)
                {
                    cout << answer << '\n';
                    return;
                }
                if (next > N)
                    break;
                if (visit[next] <= answer)
                    continue;
                que.push(next);
            }
            // �������� �̵��� ���.
            for (int i = 1; ; ++i)
            {
                int next = here - board[here] * i;
                if (next == b)
                {
                    cout << answer << '\n';
                    return;
                }
                if (next <= 0)
                    break;
                if (visit[next] <= answer)
                    continue;
                que.push(next);
            }
        }
    }
    // ������ b�� �������� ���� ��� -1�� ����Ѵ�.
    // �� �κ��� ���߷��� �ѹ� Ʋ�ȴ�.
    cout << -1 << '\n';
}

void Solve()
{
    if (a == b)
    {
        cout << 0 << '\n';
        return;
    }
    BFS();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> board[i];
    cin >> a >> b;
}

int main()
{
    Input();
    Solve();
    return 0;
}