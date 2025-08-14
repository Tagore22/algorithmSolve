#include <iostream>

using namespace std;

// Ǯ��.
// ������ ����� ���о ���� ��� ������. ���ݸ��� ũ��� 2�� �������̴�.
// ���� �뷫������ 100���� �Ѵ� 2�� ���������� �ʱ� ���ݸ��� ũ�⸦
// 2�� ������� ���� ũ���� ���ݸ��� K���� ���ݸ��� ���� �� �ִ��� Ȯ��
// �ϸ� �ȴ�.

int K;
pair<int, int> answer;

void DivineChoco(int mid)
{
    int sum = 0, idx = 0;
    // �̹� ���ݸ��� ũ�Ⱑ K��� ���� �ʿ䵵 ����.
    if (mid == K)
    {
        answer = make_pair(mid, idx);
        return;
    }
    int cur = mid;
    while (cur > 1)
    {
        cur /= 2;
        ++idx;
        // ���� ���� ���ݸ��� ũ�⸦ ������ �� K���� Ŀ���ٸ�
        // ������ �ʴ´�.
        sum = sum + cur > K ? sum : sum + cur;
        if (sum == K)
        {
            answer = make_pair(mid, idx);
            return;
        }
    }
}

int main()
{
    cin >> K;
    // 2�� 29�������� ���������� �����δ� 100������ ����� 20�������� �ص�
    // �������.
    int to = (1 << 30);
    // 2�� ������� K�� ���� �� �ִ��� Ȯ���Ѵ�.
    for (int i = 0; i < 30; ++i)
    {
        DivineChoco(to);
        to /= 2;
    }
    cout << answer.first << ' ' << answer.second << '\n';
    return 0;
}