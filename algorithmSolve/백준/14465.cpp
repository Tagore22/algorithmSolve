#include <iostream>

using namespace std;

// Ǯ��.
// �� ġ������ ������ �������� �巯���µ� �ʹ� ��ư� �����Ѵٴ� ���̴�. ó������
// �� �μ��� ī�޶��� ���ʰ� �����ʰ��� ����ؼ� �����ϴ� ����� ���÷ȴµ� ��ġ ��⸦ ���
// ���� �ڳ��� ��� ���⸦ ���� ������ �����. �� ������ ���� Ǯ�̴� �ſ� �����ϴ�. ���� �հ� 
// �����̵� �������� ������ �̿��Ͽ� �� ���ʺ��� K������ ��ĭ�� �Űܰ��� �����ϴ� �μ��� ī�޶��� �ּҰ��� ���ϸ�
// �ȴ�. ���� �� ħ���غ���.

int N, K, B;
int broken[100001];

void Solve()
{
    int minbroken = 0;
    for (int i = 1; i <= K; ++i)
        minbroken += broken[i];

    int curbroken = minbroken;
    for (int i = K + 1; i <= N; ++i)
    {
        curbroken += broken[i] - broken[i - K];
        minbroken = min(minbroken, curbroken);
    }
    cout << minbroken << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K >> B;
    for (int i = 0; i < B; ++i)
    {
        int num;
        cin >> num;
        broken[num] = 1;
    }
}

int main()
{
    Input();
    Solve();
    return 0;
}