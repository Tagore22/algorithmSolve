#include <iostream>

using namespace std;

long long board[4000004];
int N, M;

// Ǯ��.
// �������� ���׸�Ʈ Ʈ��(���� Ʈ��)������. �������� '�� ������ ���� Ʈ���� Ǫ�� ���̶��'��� ���� �ϰ� �־
// Ǯ�� ������. �ٸ� ���� Ʈ���� ������Ʈ�Կ� �־� �Ѱ��� �Ǽ��� �Ͽ��µ� ������Ʈ �� ���� �ݿ��� �����ְ� �־���.
// �������� ����� �ʾҴ�. �ٸ� �ٸ� Ǯ�̵��� ���� �ӵ��� ���� ���ݿ� ����� Ǯ�̵��� �־��µ� ���� ���� ��������.
// �ٸ� ���� �����Ͽ� ���� Ǯ�̷� Ǯ���� ������ ���� Ǯ�̴� �ƴҰ��̴�.

// �ڼ��� ������ �ּ����� �����.

// left ~ right������ ������ ��ȸ�ϸ� ��� ���� ��ȯ�ϴ� �Լ�.
long long Query(int node_left, int node_right, int left, int right, int node)
{
    // ���ϰ��� �ϴ� ������ ���� ������ �ƿ� ��ġ�� �ʴ´ٸ� �����Ѵ�.
    if (node_left > right || left > node_right)
        return 0;
    // ���� ������ ���ϰ��� �ϴ� �����ȿ� ���Ѵٸ� ���� ���� ��ȯ�Ѵ�.
    if (left <= node_left && node_right <= right)
        return board[node];

    // �������� ������ �����Ѵ�.
    int mid = (node_left + node_right) / 2;
    return Query(node_left, mid, left, right, node * 2) +
        Query(mid + 1, node_right, left, right, node * 2 + 1);
}

// �������� �����Ͽ� ���� Ʈ���� �ݿ��ϴ� �Լ�.
long long Update(int idx, int num, int left, int right, int node)
{
    // �����ϰ��� �ϴ� ��ġ�� ���� �������� �������� �ʴ´ٸ� �����Ѵ�.
    if (left > idx || idx > right)
        return board[node];
    // �ᱹ ���۰� ���� ���������� �����Դٸ� �װ��� ����� ��ġ�⿡ ���� �������ش�.
    if (left == right)
        return board[node] = num;

    // �������� ������ �����ϰ� ���� ���� �������ش�.
    // �̺κп��� �������ִ°� �ؾ������ ���� ��̴�.
    int mid = (left + right) / 2;
    return board[node] = Update(idx, num, left, mid, node * 2) +
        Update(idx, num, mid + 1, right, node * 2 + 1);
}

void MakeAnswer()
{
    int func, from, to;
    for (int i = 0; i < M; ++i)
    {
        cin >> func >> from >> to;

        if (func == 0)
        {
            if (from > to)
                swap(from, to);
            cout << Query(1, N, from, to, 1) << '\n';
        }
        else
        {
            Update(from, to, 1, N, 1);
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}