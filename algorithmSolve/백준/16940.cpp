#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Ǯ��.
// ó���� ������ ������ ��û ���������µ� ���� Ǯ��� �߻��� ���ø��Ⱑ ����� ��������.
// ����, �������� 25�ۼ�Ʈ���� ���� �ʾҴ�. ������ �ǵ� ��ü�� ����Ͽ��� ������ ����.
// �־��� ������ ������ ���� BFS��ȸ ������ �ϳ������� �����ϴ� ���̴�.
// ó������ BFS�� ������ �̿��Ͽ� ���� �������� �̵������� ��� �������� ť�� ����ְ�
// �� ������� ť���� ���� ������ ���Ϸ��� �߾��µ� https://www.acmicpc.net/board/view/60231�� �ݷʸ� ����
// �˼� �ֵ��� �ֽô��� �Ұ����ϴ�. �ռ� ť�� �� ������ ���� �˼� ���� �����̴�.
// ����� �ƿ� �־��� ������� ��ȸ�� ���� ���̴�. �ֽô��� �־��� ������ ������ ��ȸ���
// ���� ��ȸ�� �ϸ鼭 ���� ���Ҷ� �ٸ����� ���� �����̴�. �ٸ� �־��� ������� �� �̵������� ��������
// ������ ���� �����ؾ� �ߴ�. ����� ���䰰���� �ǻ��� �־��� ������� �켱������ �ο��Ͽ� �� �̵������� ��������
// ��� �����ϱ⸸ �ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

vector<vector<int>> tree;
int board[100000], order[100001];
int N;

// �̵������� �������� ������ �ٽ� �����ϴ� �Լ�.
bool SortFunc(int lhs, int rhs)
{
    // �� �켱������ ���缭 �����Ѵ�.
    if (order[lhs] < order[rhs])
        return true;
    return false;
}

// BFS ��ȸ �Լ�.
void BFS()
{
    queue<int> que;
    que.push(0);
    vector<int> visit(N + 1, false);
    visit[0] = true;
    int idx = 0;

    // �� �Ѱ��� �κи��� �����ϰ�� �Ϲ����� BFS�� �ٸ����� ����.
    while (!que.empty())
    {
        int here = que.front();
        que.pop();

        for (auto there : tree[here])
        {
            if (!visit[there])
            {
                // ���� ���� �湮�ϴ� ������ �־��� ������ �ٸ��ٸ� 0�� ����Ѵ�.
                if (there != board[idx])
                {
                    cout << 0 << '\n';
                    return;
                }
                visit[there] = true;
                que.push(there);
                ++idx;
            }
        }
    }
    // �־��� ������� BFS ��ȸ�� ��ĥ�� �־��⿡ 1�� ����Ѵ�.
    cout << 1 << '\n';
}

void MakeAnswer()
{
    tree[0].push_back(1);
    // �� ��� �������� �̵������� �������� �켱������ ���� ���Ӱ� �����Ѵ�.
    for (int i = 0; i <= N; ++i)
        sort(tree[i].begin(), tree[i].end(), SortFunc);
    BFS();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    tree.resize(N + 1, vector<int>());
    int from, to;
    for (int i = 0; i < N - 1; ++i)
    {
        cin >> from >> to;
        tree[from].push_back(to);
        tree[to].push_back(from);
    }
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i];
        // �Էµ� ������� �켱������ �ο��Ѵ�.
        order[board[i]] = i;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}