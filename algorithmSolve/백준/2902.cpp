#include <iostream>

using namespace std;

// Ǯ��.
// �� ���� �빮�ڿ� �� ������ ���� �빮�ڸ� ����ϴ� ������.
// �� ���Ӹ��� ����ؾ� �ϴµ� �������� �� ���Ӹ��鸸 �빮�ڶ�� ���������Ƿ� �����ϰ�
// �־��� ���ڿ����� �빮�ڵ鸸 ����ϸ� �ȴ�.

int main()
{
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); ++i)
        if ('A' <= str[i] && str[i] <= 'Z')
            cout << str[i];
    cout << '\n';
    return 0;
}