#include <iostream>

using namespace std;

// Ǯ��.
// ��������� ���� ����� �׸����� 5�� �����ϰ� ����� �ٲ�� ������
// ���̰� �巯�������� 10�� �����Ѵ�.

int main()
{
    string str;
    cin >> str;
    int answer = 10;
    for (int i = 1; i < str.size(); ++i)
        answer = str[i] == str[i - 1] ? answer + 5 : answer + 10;
    cout << answer << '\n';
    return 0;
}