#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Ǯ��.
// �������� 30���ΰ� �ȵǴ� ����� ��������. �̰Ϳ��� ������ ���� �Ƹ����ϰ� ���� ſ�� �ִµ�
// ��� �������� �ٸ� ��� ���������� �̵�Ƚ���� ���� ª�� ������ �ƴ�
// ���� �� ���������� �̵�Ƚ���� ���� ª�� ������ ��ǥ�� �Ǿ�� �ϱ� �����̴�.
// ���� �Խ����� ���� ��ó�� �� �κп��� ���̵� ������ ����.
// �� ���ķδ� ���� ����ȸ���� ��ǥ�� ������ ������������ �����Ͽ� ����ϸ� �ȴ�.
// ���� ����ȸ�� �ο��� DFS�� ã�Ҵ�. �ٸ� ����� �ְ����� �̰� ���� ���� �������� ������ ����̾���.
// �̷��� ���� ����ȸ�� �ο����� ã�Ƴ����� �� ������ �̸� �÷��̵� �ͼ� �˰������� ����س��Ҵ�
// �� ����������� �Ÿ����� �ִ����� ���ϰ� �� ����ȸ�� �ο����� �ִ밪�� �ּҰ��� ���� �ο��� ã�Ƽ�
// ������ answer�� ����ִ´�. ��� ��ȸ�� ������ answer�� �����Ͽ� ����ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int board[101][101] = { 0, };
vector<int> cur;
vector<bool> visit(101, false);
int N, M;

// �� �������� �ּ� �Ÿ��� ���ϴ� �Լ�.
void Floyd()
{
    // i���� i�� 0����, �������� ���ϴ� ���������� �Ÿ��� �ƿ� ū 105�� �ʱ�ȭ�Ѵ�.
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            if (i != j && board[i][j] == 0)
                board[i][j] = 105;
    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
            {
                // i���� k Ȥ�� k���� j�� ���޺Ұ����ϴٸ� �����Ѵ�.
                if (board[i][k] == 0 || board[k][j] == 0)
                    continue;
                // i���� j�� �����Ÿ��� k�� �����Ͽ� �����ϴ� �Ÿ����� �ּҰ����� �Ѵ�.
                board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
            }
}

// ���� ����ȸ�� �ο��� ã�� ���� DFS ��ȸ.
void DFS(int here)
{
    visit[here] = true;
    cur.push_back(here);

    for (int there = 1; there <= N; ++there)
        if (!visit[there] && board[here][there] != 105)
            DFS(there);
}

void MakeAnswer()
{
    Floyd();
    vector<int> answer;
    for (int iter = 1; iter <= N; ++iter)
    {
        if (!visit[iter])
        {
            // DFS ��ȸ�� ���� ���� ����ȸ�� �ο����� ����Ѵ�.
            cur.clear();
            DFS(iter);

            pair<int, int> max_num = make_pair(0, 100);
            // �� �������� �ٸ� ���������� �ִ밪�� ���ϰ�
            // ��� �������� �ִ밪���� �ּҰ��� ���Ͽ� �� ������
            // ������ answer�� �ִ´�.
            for (auto a : cur)
            {
                int now = -1;
                for (auto b : cur)
                    now = max(now, board[a][b]);
                if (now < max_num.second)
                    max_num = make_pair(a, now);
            }
            answer.push_back(max_num.first);
        }
    }
    // answer�� ���� ����ϰ� �����Ͽ� ������������ ����Ѵ�.
    cout << answer.size() << '\n';
    sort(answer.begin(), answer.end());
    for (auto ans : answer)
        cout << ans << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    int from, to;
    for (int i = 0; i < M; ++i)
    {
        cin >> from >> to;
        board[from][to] = 1;
        board[to][from] = 1;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}