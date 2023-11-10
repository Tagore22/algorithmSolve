#include <iostream>

using namespace std;

// Ǯ��.
// ���� ���� ������. �ٸ� ���� ���� ���� �ε����� �˾ƾ� �߱⿡ �ܼ� int�� �迭�� �ƴ� pair<int, int>�� �迭�� ����ؾ��ߴ�.
// ����, �ε��� ��ȣ�� 0�� �ƴ� 1������ �����߱⿡ ���� ���� ���� 1������ �����ϰԲ� �����ؾ��ߴ�.
// �ٸ� �������� ������ ū �Ǽ��� �ظ̴µ� �����Լ����� ������ �ƿ� ��߳��� �ִ밪�� ��ȯ�ϴ� �κ��̴�. ��� ����ó�� 987654321��
// ��ȯ�ߴµ� �־����� ���� �ִ� 10���̴�. 987654321�� 10�ﺸ�� ���� 9���� ���̱⿡ �����ϱ� ���� �͹��� ���� ū ���� ���� ���ؼ�
// 96�ۼ�Ʈ���� ����� Ʋ�ȴ�. �׷��� ã�ƴټ� �����̳� �������� ���ݴ� �����ϰ� Ǯ��.

// �ڼ��� ������ �ּ����� �����.

int board[100001];
pair<int, int> q_array[400004];
int N, M;

// ���� ������ �ʱ�ȭ �Լ�.
pair<int, int> Init(int left, int right, int node)
{
    // �� ���������� �̸����ٸ� ���� �������ش�.
    if (left == right)
        return q_array[node] = make_pair(board[left], left);
    // �������� ������ ���ȣ���Ѵ�.
    int mid = (left + right) / 2;
    return q_array[node] = min(Init(left, mid, node * 2), Init(mid + 1, right, node * 2 + 1));
}

// ���� ������ ���� �Լ�.
pair<int, int> Query(int left, int right, int node_left, int node_right, int node)
{
    // ã������ ������ ���� ������ ������ �ƿ� ��߳��ٸ� �͹��� ���� ū ���� ��ȯ�Ͽ� �����Ѵ�.
    if (left > node_right || node_left > right)
        return make_pair(1987654321, 1987654321);
    // ���� ������ ã������ ������ ���Եȴٸ� ���� ���� ����Ѵ�.
    if (node_left >= left && right >= node_right)
        return q_array[node];
    // �������� ������ ���ȣ���Ѵ�.
    int mid = (node_left + node_right) / 2;
    return min(Query(left, right, node_left, mid, node * 2),
        Query(left, right, mid + 1, node_right, node * 2 + 1));
}

// ���� ������ ���� �Լ�.
pair<int, int> Update(int idx, int value, int left, int right, int node)
{
    // ������ ����ٸ� �����Ѵ�.
    if (idx < left || idx > right)
        return q_array[node];
    // �������� �̸����ٸ� ���� �����Ѵ�.
    if (left == right)
        return q_array[node] = make_pair(value, idx);
    // �������� ������ ���ȣ���Ѵ�.
    int mid = (left + right) / 2;
    return q_array[node] = min(Update(idx, value, left, mid, node * 2),
        Update(idx, value, mid + 1, right, node * 2 + 1));
}

void MakeAnswer()
{
    Init(0, N - 1, 1);
    int num, first, second;
    for (int i = 0; i < M; ++i)
    {
        cin >> num >> first >> second;
        if (num == 1)
            Update(first - 1, second, 0, N - 1, 1);
        else
            cout << Query(first - 1, second - 1, 0, N - 1, 1).second + 1 << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
    cin >> M;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}