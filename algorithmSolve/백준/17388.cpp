#include <iostream>

using namespace std;

// Ǯ��.
// �����ġ��� �ϳ� ���ŷο� �����̴�. �ܼ� ������ ���� ���ϴ°� �� ���ҵ��� �����Ҷ� ���� ���� � ���Ұ�
// ��� �������� �˾ƾ��ϱ� �����̴�. ���� �׳� ������ ���� �ʰ� �� ���Ұ����� �Է¹����� idx�� �ε�������
// �����Ͽ���. �� ���� �ε������� ���� ��� �������� �����Ͽ� ���и��� ����Ѵ�.

int main()
{
    int sum = 0, idx = 0, num, cur = 987654321;
    for (int i = 0; i < 3; ++i)
    {
        cin >> num;
        if (cur > num)
        {
            idx = i;
            cur = num;
        }
        sum += num;
    }
    if (sum >= 100)
    {
        cout << "OK" << '\n';
    }
    else
    {
        if (idx == 0)
            cout << "Soongsil" << '\n';
        else if (idx == 1)
            cout << "Korea" << '\n';
        else
            cout << "Hanyang" << '\n';
    }
    return 0;
}