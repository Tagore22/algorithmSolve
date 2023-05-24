#include <iostream>
#include <vector>

using namespace std;

// Ǯ��.
// ����� ����Ʈ��(���׸�Ʈ Ʈ��)�����̴�.
// N�� ������ �ִ� 10���̰� ã�ƾ� �ϴ� ������ �� M�� �ִ� 10���̶�
// �Ϲ������� Ǯ�� 10�� * 10���� ���귮�� �����⿡ Ǯ������.
// ���� ã���� �ִ� ����Ʈ�� ������ ���� �ٸ��� �ʱ⿡ ������� �ſ� ����.
// �ٸ� �Ѱ��� ��ģ�κ��� �־��µ� ���� int �ִ밪�� ���� 987654321���� �ϴµ�
// �̹����� �׷��ߴ�. ������ �̹� ������ �ִ밪�� 10���̱⿡ 987654321�� �����
// ��û ū ���� ���� ������ ���ߴ�. ��������� �տ� 1�� ���ٿ� �ذ��Ͽ���.

// �ڼ��� ������ �ּ����� �����.

const int MAX_NUM = 100000;
int board[MAX_NUM];
pair<int, int> iter[MAX_NUM];
int N, M;

// Ʈ�� ����.
struct tree
{
    vector<int> tree_board;

    tree()
    {
        tree_board.resize(N * 4);
    }

    // Ʈ���� �ʱ�ȭ. �⺻������ ���� Ž��ó�� �ΰ����� ������
    // �α��� ���귮�� ���Ѵ�.
    int Init(int idx, int left, int right)
    {
        // ������ ������ left Ȥ�� right �ϳ��� ���Ҵٸ� �� ������ �ڽ��� �ڸ���.
        if (left == right)
            return tree_board[idx] = board[left];

        // �ΰ����� ������ ���� ������ �ּҰ��� ã�´�.
        int mid = (left + right) / 2;
        int first = Init(idx * 2, left, mid);
        int second = Init(idx * 2 + 1, mid + 1, right);
        // ���� �ΰ����� �ּҰ����� �� �ּҰ��� ������ ���� �ּҰ����� ����.
        return tree_board[idx] = min(first, second);
    }

    int Init()
    {
        return Init(1, 0, N - 1);
    }

    // ���� from ~ to�� �־������� �� ������ �ּҰ��� ã�� �Լ�.
    int Find(int idx, int left, int right, int from, int to)
    {
        // 1. ������ �ƿ� ��ġ�� �ʴ´ٸ� ���� ū ���� ��ȯ�Ͽ� ����.
        // 2. from ~ to�� left ~ right�� ������ ���ų� �� Ŀ���ٸ� ���縦 �״�� ��ȯ.
        // 3. �׷��� �ʴٸ� �ٽ� ������ ������ ���.
        if (right < from || to < left)
            // �ٷ� �̺κ��� ��ģ �κ��̾��µ� ����Ͽ��� �̹����� 98765431�� ��û ū �ִ밪��
            // ���� ������ ���Ѵ�.
            return 1987654321;
        if (from <= left && right <= to)
            return tree_board[idx];
        int mid = (left + right) / 2;
        int first = Find(idx * 2, left, mid, from, to);
        int second = Find(idx * 2 + 1, mid + 1, right, from, to);
        return min(first, second);
    }

    int Find(int from, int to)
    {
        return Find(1, 0, N - 1, from, to);
    }
};

void MakeAnswer()
{
    tree t;
    t.Init();

    int answer;
    for (int i = 0; i < M; ++i)
    {
        answer = t.Find(iter[i].first - 1, iter[i].second - 1);
        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
    for (int i = 0; i < M; ++i)
        cin >> iter[i].first >> iter[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}