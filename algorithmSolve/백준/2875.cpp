#include <iostream>

using namespace std;

// Ǯ��. 
// �� �� �����߾����� K �κ��� ������ 2�� �����س��Ҿ���.
// ���л�, ���л����� �� K��ŭ�� ���� �����ϱ� ������
// 0 ~ K��ŭ ��ȸ�ϸ� ���� ������� ���� ���� ���л� / 2�� ���л��� ����
// �� ���� ���� ���� ����� �ִ� ���� ���̸�, �� ������ �ִ밪�� ����ϸ� �ȴ�.

int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    int answer = 0;
    for (int i = 0; i <= K; ++i)
    {
        int dn = N - i;
        int dm = M - K + i;
        answer = max(answer, min(dn / 2, dm));
    }
    cout << answer << '\n';
    return 0;
}