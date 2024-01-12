#include <iostream>

using namespace std;

// Ǯ��.
// ���� �����ϴ� ���� ���� ������.
// �̹����� ���� Ư�������� �ּҰ��̳� �ִ밪�� �ƴ� ������� �������� 0������ ���� �˾ƾ��Ѵ�.
// �ٸ� ������ ���� ��尡 ���̻� �������� ���� ��尪�� �ٲ� ������ 1, ������� -1, 0�̶�� 0����
// ���� �ʱ�ȭ���ָ� �� ���� �ܼ� ���ϱ� �������� �� ������ �������� �˾Ƴ��� �ֱ� ������ ����� �ʴ�.

// �ڼ��� ������ �ּ����� �����.

int board[100001], arr[400004];
int N, K;

// �ʱ�ȭ �Լ�.
int Init(int left, int right, int node)
{
    // ����� �� �������� �ٴٶ����� ���� ���� ������� �������� 0������ ���� 
    // �ʱ�ȭ���� �ٲ��ش�.
    if (left == right)
    {
        if (board[left] > 0)
            return arr[node] = 1;
        else if (board[left] == 0)
            return arr[node] = 0;
        else
            return arr[node] = -1;
    }
    int mid = (left + right) / 2;
    return arr[node] = Init(left, mid, node * 2) * Init(mid + 1, right, node * 2 + 1);
}

// ���� �Լ�.
int Query(int left, int right, int node, int node_left, int node_right)
{
    if (left > node_right || node_left > right)
        return 1;
    if (left <= node_left && node_right <= right)
        return arr[node];
    int mid = (node_left + node_right) / 2;
    int lhs = Query(left, right, node * 2, node_left, mid);
    int rhs = Query(left, right, node * 2 + 1, mid + 1, node_right);
    return lhs * rhs;
}

// ���� �����ϴ� �Լ�.
int Update(int idx, int value, int node, int left, int right)
{
    if (idx < left || idx > right)
        return arr[node];
    if (left == right)
    {
        if (value > 0)
            return arr[node] = 1;
        else if (value == 0)
            return arr[node] = 0;
        else
            return arr[node] = -1;
    }
    int mid = (left + right) / 2;
    int lhs = Update(idx, value, node * 2, left, mid);
    int rhs = Update(idx, value, node * 2 + 1, mid + 1, right);
    return arr[node] = lhs * rhs;
}

void MakeAnswer()
{
    while (cin >> N >> K)
    {
        string answer = "";
        for (int i = 1; i <= N; ++i)
            cin >> board[i];
        Init(1, N, 1);
        char order;
        int i, j;
        for (int iter = 0; iter < K; ++iter)
        {
            cin >> order >> i >> j;
            if (order == 'C')
            {
                Update(i, j, 1, 1, N);
            }
            else
            {
                int num = Query(i, j, 1, 1, N);
                if (num > 0)
                    answer += "+";
                else if (num == 0)
                    answer += "0";
                else
                    answer += "-";
            }
        }
        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}