#include <iostream>

using namespace std;

// Ǯ��.
// �Ǻ���ġ�� �̿��� �����̴�. ���ø� �� ���캸�� �˼� �ֵ��� N���� Ÿ�Ϸ� �̷���� ���簢���� �ѷ���
// N��° �Ǻ���ġ�� �� * 2 + N + 1��° �Ǻ���ġ�� ���� �����ϴ�. �ٸ�, �������� �˷��ֵ� �Ǻ���ġ�� ��
// ���� int ������ ��� ���� �����Ƿ� long long Ÿ���� ������ ����ؾ� �Ѵ�.

long long FiboDP[82];
int N;

int main()
{
    cin >> N;
    FiboDP[1] = 1;
    for (int i = 2; i <= N + 1; ++i)
        FiboDP[i] = FiboDP[i - 1] + FiboDP[i - 2];
    cout << FiboDP[N + 1] * 2 + FiboDP[N] * 2 << '\n';
    return 0;
}