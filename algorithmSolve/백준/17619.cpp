#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// 30���ΰ� �ȵǴ� ��������� ����� ��������. �������� ���Ͽ� ���ε忴�µ� ��������
// �־����� �� ���� �Ӹ����� ���� ������ �ƴ��� Ȯ���ϴ°��� Ȯ�������� �� ������ ���ϴ�
// ����� �� �������� �ʾҴ�. ��������δ� ������ �������� �����Ͽ� �� ������ �����ϴ� ���̾���.

// �ڼ��� ������ �ּ����� �����.

struct pos
{
    int l;
    int r;
    int idx;
};

pos board[100001];
int p[100001];
int N, Q;

// ������ ������ �Ǵ� �Լ�. ������ġ�� �������� �����ϸ�
// ���� ��ġ�� ������ �����Ƿ� ���ۺκи� ���غ��� �ȴ�.
bool SortFunc(const pos& lhs, const pos& rhs)
{
    if (lhs.l != rhs.l)
        return lhs.l < rhs.l;
    return lhs.r < rhs.r;
}

// �� ������ �Ӹ���ġ�� ����ϴ� �Լ�.
int Find(int idx)
{
    if (p[idx] == idx)
        return idx;
    // �� �κ��� ����ȭ�� �ٽ��ε� �ѹ� ���� ���ŵɶ� ���ʴ�� �ö󰡸�
    // ��� ������ �Ǳ� �����̴�.
    return p[idx] = Find(p[idx]);
}

// �� ������ �����ϴ� �Լ�.
void Merge(int lhs, int rhs)
{
    lhs = Find(lhs), rhs = Find(rhs);

    if (lhs != rhs)
        p[rhs] = lhs;
}

void MakeAnswer()
{
    // ���ʺ��� ���������� �������� �س����� ��ȸ�ϱ� ������
    // ������ �ʼ����̴�.
    sort(board, board + N, SortFunc);
    // p�� �θ��� ���̸� �ִ� N���� �־�����.
    for (int i = 0; i <= N; ++i)
        p[i] = i;
    int from = board[0].l, to = board[0].r;
    for (int i = 1; i <= N; ++i)
    {
        // ���� ���ο� ������ ���� ������ ��ģ�ٸ�
        if (board[i].l <= to)
        {
            // ���ο� ������ ���� ������ ���յǰ� ���� ������ ����
            // �����Ѵ�.
            Merge(board[i - 1].idx, board[i].idx);
            to = max(to, board[i].r);
        }
        else
        {
            from = board[i].l;
            to = board[i].r;
        }
    }
    for (int i = 0; i < Q; ++i)
    {
        cin >> from >> to;
        // �� ������ ���� �����ִٸ� �̵��� �����ϴ�.
        cout << (Find(from) == Find(to) ? 1 : 0) << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> Q;
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i].l >> board[i].r >> board[i].idx;
        board[i].idx = i + 1;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}