#include <iostream>

using namespace std;

// �˰��� ����Ǯ�̸� ó�� �����Ҷ����� ���� Ʈ���� '�׳� ����Ʈ���� ���� �ǰ���' �ϰ�� ���ѽ� �ߴµ�
// �̹��� ���� ���ߴ�. ���� Ʈ���� �� �����ϰ� �� ������ �����̾���. �ٸ� ��Ʈ����ũ�� ����ؼ� 
// ����� ��������ߴ�. �����δ� ���� ����ؾ߰ڴ�.

// �ڼ��� ������ �ּ����� �����.

long long board[1000001];
int N, Q;

// to������ ��� �յ��� ����ϴ� �Լ�. �� ���Ұ����� 1 ~ N������ ���յ��̹Ƿ� �Ű������� from, to�� �÷���
// from ~ to������ ���� ����Ҽ� ����. �������� ���� �����غ��� �˼� �ִ�.
// 1, 2, 3, 4�� �����Ҷ� �� �������� 1, 3, 6, 10�̴�. ���� [3, 4]�� ���Ѵٰ� �Ҷ�
// ����ó�� 10 - 3�� 7�� ������, 10 + 6�� 16�� �Ǿ� ������ �ƴϱ� �����̴�.
long long Query(int to)
{
    long long ans = 0;
    while (to > 0)
    {
        ans += board[to];
        // �����ʺ��� ���� ������ 1�� �����ϸ� ���� �ε������� ���Ҽ� �ִ�.
        to &= (to - 1);
    }
    return ans;
}

// to���� ��� ������ ��ȭ��Ű�� �Լ�.
void Update(int idx, int value)
{
    while (idx <= N)
    {
        board[idx] += value;
        idx += (idx & -idx);
    }
}

void MakeAnswer()
{
    int a, b, c;
    for (int iter = 0; iter < Q; ++iter)
    {
        cin >> a >> b >> c;
        if (a == 1)
            Update(b, c);
        else
            cout << Query(c) - Query(b - 1) << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> Q;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}