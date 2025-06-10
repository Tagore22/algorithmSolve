#include <iostream>

using namespace std;

// Ǯ��.
// ������ Ǫ�� ���� ��ü�� �� ���߾���. �ӷ��� �����ϴµ��� �ƹ��� ������ ������, �����ϴµ��� ���� �ӵ�����
// 1���ۿ� �������� ���ϱ� �����̴�. ���� �ڿ������� �ӷ��� �����س����� �ߴ�. �� �� ù��° �Ǽ��� �Ͽ��µ�
// ���� ������ ���� ������ ��꿡�� �ƿ� �����ȴ�. ���� ������ �ӷ��� 0�� ���·� �����ؾ��Ѵٴ� ���� ������
// �߰� �������� �ӷ��� 1�̿��� �Ѵٴ� ���̴�. �׷��Ƿ� �� �ڿ��� ��ȸ�� �����Ҷ� �ӷ��� 1�� �����ؾ� �Ѵ�.
// �� �� �ι�° �Ǽ��� �ߴµ� �� �ӷ��� �ִ�ġ�� 10���̱� ������ int ������ ��� �� �����Ƿ� �������� ���
// ���� answer�� long long Ÿ���̿��� �Ѵ�.

int N;
const int MAX = 500000;
int board[MAX];

void Solve()
{
    int cur = 1;
    long long answer = 0;
    for (int i = N - 1; i >= 0; --i)
    {
        cur = min(cur, board[i]);
        answer += cur;
        ++cur;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    Solve();
    return 0;
}