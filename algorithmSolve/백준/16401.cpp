#include <iostream>

using namespace std;

// Ǯ��.
// ó������ �켱���� ť�� �̿��Ͽ� ���� �� ���븦 ���ݾ� ������� ���Ϸ��� �ߴµ�
// �����ϱ⸸ �ϰ� ��Ȯ���� ��������. �̺� Ž������ mid�� �ø��ų� �ٿ����� ���ϸ� �Ǿ���.
// �ٸ�, ���ڱ����� ������ M���� �۴ٸ� �ƿ� �������ټ��� ���� ������ 0�� ����Ͽ� ���ܸ�
// ó���ϴ°Ϳ� �����ؾ��Ѵ�.

int board[1000000];
int M, N;
long long sum = 0;

// ���� mid�� ������ ������ ���ϴ� �Լ�.
bool IsOverMid(int mid)
{
    int ans = 0;
    for (int i = 0; i < N; ++i)
        ans += board[i] / mid;
    return ans >= M;
}

void MakeAnswer()
{
    // �ƿ� ���ڸ� �������� �� ���ٸ� 0�� ����Ѵ�.
    if (sum < M)
    {
        cout << 0 << '\n';
        return;
    }
    // from�� 0���� �����߾��µ� �̷��� ���߿� 0�� ������ �Ǵ� ��찡 �����.
    // ���� 1���� �����ؾ��Կ� ��������.
    int from = 1, to = 1000000001;
    while (from <= to)
    {
        int mid = (from + to) / 2;
        if (IsOverMid(mid))
            from = mid + 1;
        else
            to = mid - 1;
    }
    cout << from - 1 << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> M >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i];
        sum += board[i];
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}