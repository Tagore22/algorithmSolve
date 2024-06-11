#include <iostream>

using namespace std;

// Ǯ��.
// 2018���� ���� Ǯ��.
// ���� �ָԱ����� Ǯ�̴�. ������ ��ġ�� ���� �����Ҽ� �����Ƿ� DP�� ���� �ʾҴ�.
// ������ ���۵Ǵ� ������ �ڱ� �ڽ��� ���ݺ��� ū ��Ȳ�� �����Ҽ� �����Ƿ� 1 ~ N / 2����
// �Լ��� ȣ���Ͽ� ���������� 1ū���� ��������. ���� ���� 0���� �۴ٸ� Ż���ϰ� 0�̶�� 1�� ��ȯ�Ͽ�
// ��������� ����� �ִ� ��� �������� ����Ѵ�.

int N;

int FindTree(int cur, int minus)
{
    if (cur == 0)
        return 1;
    else if (cur < 0)
        return 0;
    return FindTree(cur - minus, minus + 1);
}

int main()
{
    cin >> N;
    int answer = 1;
    for (int i = 1; i <= N / 2; ++i)
        answer += FindTree(N, i);
    cout << answer << '\n';
    return 0;
}