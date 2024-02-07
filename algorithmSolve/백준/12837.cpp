#include <iostream>

using namespace std;

// Ǯ��.
// ������ ������ ���ϴ� �����̴�. �ٸ� �������� �ſ� ũ�� ������ ���� ������ ����ؾ��ߴ�.
// �Ѱ��� �Ǽ��� �ߴµ� N�� ���� �ϳ��� �����Ǵ��� �˾Ҵµ� 0���� �߰��� �Էµ� ���� �����ϴ� ���̾���.

// �ڼ��� ������ �ּ����� �����.

long long board[4000004];
int N, Q;

// left ~ right�� ������ ���ϴ� �Լ�.
long long Query(int left, int right, int node, int node_left, int node_right)
{
    if (node_right < left || right < node_left)
        return 0;
    if (left <= node_left && node_right <= right)
        return board[node];
    int mid = (node_left + node_right) / 2;
    long long lhs = Query(left, right, node * 2, node_left, mid);
    long long rhs = Query(left, right, node * 2 + 1, mid + 1, node_right);
    return lhs + rhs;
}

// idx�� ���� value�� ��ü�ϴ� �Լ�. ������ �� ���������� ��ü�� �ƴ϶� �����ϴ� �Լ���.
long long Update(int value, int idx, int node, int left, int right)
{
    if (idx < left || right < idx)
        return board[node];
    if (left == right)
        return board[node] += value;
    int mid = (left + right) / 2;
    long long lhs = Update(value, idx, node * 2, left, mid);
    long long rhs = Update(value, idx, node * 2 + 1, mid + 1, right);
    return board[node] = lhs + rhs;
}

void MakeAnswer()
{
    int a, b, c;
    for (int iter = 0; iter < Q; ++iter)
    {
        cin >> a >> b >> c;
        if (a == 1)
            Update(c, b, 1, 1, N);
        else
            cout << Query(b, c, 1, 1, N) << '\n';
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