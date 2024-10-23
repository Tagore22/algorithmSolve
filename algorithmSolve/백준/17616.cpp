#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Ǯ��.
// ó���� ��� Ǫ���� ���� ���� �������� �ᱹ ��Ʈ�� �ôµ� X���� �� �Ǵ� �ڿ� �ִ� ����� ���� ã��
// �׷��� Ž�� ��������. �� ���ķδ� �����ߴµ� �־��� A, B�� 2���� ���͸� �̿��ؼ� �ڽź��� ������, ��������
// ���� �Է¹޾� �ι��� BFS��ȸ�� �ϸ� �ȴ�. �� �������� ġ������ �Ǽ��� �ϳ� �ߴµ� ����.... �ļ��Ѵ�.

// �ڼ��� ������ �ּ����� �����.

// ���� �ڽź��� ������, ������.
vector<int> upper[100001], lower[100001];
queue<int> que;
bool visit[100001] = { false, };
int N, M, X;

// �ִ� ����� ���ϴ� �Լ�. �ڽ��� �ڿ� �ִ� ������� ���� ���Ѵ�.
void BFSUpper()
{
    que.push(X);
    for (int i = 1; i <= N; ++i)
        visit[i] = false;
    visit[X] = true;
    // ����� ġ������ �Ǽ��� �̺κ��̴�. ��û ���̾����µ� ���� answer�� �ʱⰪ�� 5����...
    // ���ÿ��� N�� 5���µ� �׷��� ������ �׳� �������� 5�� �ξ���. ����;; �ǰ��Ѱ���
    // �ƴϸ� �׷��Ե� �˰����� Ǯ�� ��������.. ��·�� ���� ������ ������� �ϳ��ϳ� ġ�� �ö󰣴�.
    int answer = N;

    while (!que.empty())
    {
        int here = que.front();
        que.pop();

        for (auto& next : upper[here])
        {
            if (visit[next])
                continue;
            que.push(next);
            // ���ο� ����� ã�������� ���� ���θ� �����ϰ� �ڽ��� ����� �ø���.
            visit[next] = true;
            --answer;
        }
    }
    cout << answer << '\n';
}

// �ּ� ����� ���ϴ� �Լ�. �ڽ��� �տ� �ִ� ������� ���� ���Ѵ�.
void BFSLower()
{
    que.push(X);
    visit[X] = true;
    // 1����� �ϳ��� ��������.
    int answer = 1;

    while (!que.empty())
    {
        int here = que.front();
        que.pop();

        for (auto& next : lower[here])
        {
            if (visit[next])
                continue;
            que.push(next);
            // ���ο� ����� ã�������� ���� ���θ� �����ϰ� �ڽ��� ����� ������.
            visit[next] = true;
            ++answer;
        }
    }
    cout << answer << ' ';
}

void MakeAnswer()
{
    BFSLower();
    BFSUpper();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> X;
    int from, to;
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to;
        upper[from].push_back(to);
        lower[to].push_back(from);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}