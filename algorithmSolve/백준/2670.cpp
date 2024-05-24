#include <iostream>

using namespace std;

// Ǯ��.
// ó������ �ָԱ��������� Ǯ����. �ִ� 10000���� �Ҽ��� �ԷµǸ� ��� ��츦 ���ص� 10000 * 10000���� ���� 1��ۿ� ����
// �ʱ� �����̴�. �Ʒ��� ���� ����� Ǯ�̸� ���� ���Ѱ� �ƴ����� �������� �ణ �����ߴ�. ��������� ���簪�� ���ο�� ���ؼ�
// 1�� �Ѵ´ٸ� ���� ���� Ŀ���⿡ ���� ���ϰ�, �׷��� �ʴٸ� �۾����� ������ ���簪�� ��ü�ϰ� �Ѿ��. ����, �Ҽ� n°�ڸ�������
// ����ϴ� ���ο� ����� �����ߴµ� precision()�� �ƴ� printf()�� ����� ���̴�. �������� �� �����ϱ��ϴ�. �� �˾ƵѰ�.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    double cur, next, answer = 0;
    int N;
    cin >> N >> cur;
    for (int i = 1; i < N; ++i)
    {
        cin >> next;
        if (cur > 1)
            cur *= next;
        else
            cur = next;
        answer = max(answer, cur);
    }
    printf("%.3lf", answer);
    return 0;
}