#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Ǯ��.
// �������� ���� ���� ������. �׷��� ������ �߸� Ǯ����.
// ù��°���� ���Ʈ���� �񽺹Ǹ��ϰ� Ǯ� �ð��ʰ��� ������.
// Ʋ�� �ڵ���� ���� �˰�����, ���� ��ǰ�� ���� ���� ����� ��찡 ������ ���� ���
// ���ʿ��� ������ �ߺ��Ǳ� ������ dp�� ��� �ð��� �ٿ���� �ߴ�.

// �ι�°���� ���� ���ķ� Ǯ���µ� DFS������� Ǯ� ����� dp�� ��� ����������� ��������.
// �׷��� ���ſ� Ǭ �ٸ� ���� ���� �������� ���� ��... BFS����.
// �������� �̿��Ͽ� ���� �������� ���� �������� BFS���� ó�����ָ� �Ǿ���.

// �׸��� ���������� �� ó���� ��� ���־������ ���� ��������.
// ��������δ� [������][������]�� �̿��ؼ� �������� ���� ����� ���ؼ� ���ϸ� �Ǵ� ���̾���.
// �ָ��ϸ� ���ſ� Ǯ�������� ���°� �� ���ذ� ������. �ٸ� ����� Ǭ ��ĺ��ٴ� �� �����
// ���� ���⿡ �� ���ذ� ���� �����̴�.

// �ڼ��� ������ �ּ����� �����.

vector<vector<pair<int, int>>> board;
int answer[101][101], depend[101];
int N, M;

void BFS()
{
    queue<int> que;

    for (int i = 1; i <= N; ++i)
    {
        if (depend[i] == 0)
        {
            que.push(i);
        }
        // ������ �����Էθ� 1�� �ʱ�ȭ�ؾ� �ϼ��� �κп��� ������ ����� �ȴ�.
        answer[i][i] = 1;
    }

    while (!que.empty())
    {
        int here = que.front();
        que.pop();

        // �� ó�� ����� ������ ���� �ʾҴ�.
        // �������ڸ� ������ ����. � ���� i���� ������������ ������ �����Ѵٸ�
        // ���簪������ ������ ��� * �������� ���ϸ� �ȴ�.
        for (auto& temp : board[here])
        {
            int there = temp.first;
            int cost = temp.second;
            for (int i = 1; i <= N; ++i)
            {
                answer[i][there] += cost * answer[i][here];
            }
            // �������� 1 ���ҽ�Ű�� ���� �������� 0�̶�� ť�� �����Ѵ�.
            --depend[there];
            if (depend[there] == 0)
                que.push(there);
        }
    }
}

void MakeAnswer()
{
    BFS();

    for (int i = 1; i < N; ++i)
    {
        // �⺻ ��ǰ���� ����ؾ� �ϱ⿡ board[i]�� ������ Ȯ���Ѵ�.
        if (board[i].size() == 0)
        {
            cout << i << ' ' << answer[N][i] << '\n';
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    board.resize(N + 1, vector<pair<int, int>>());
    int parent, child, num;
    for (int i = 0; i < M; ++i)
    {
        cin >> parent >> child >> num;
        board[parent].push_back(make_pair(child, num));
        ++depend[child];
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}