#include <iostream>
#include <string>

using namespace std;

// Ǯ��.
// ������ ���Ե� ���ڿ��� �Է¹޾ƾ� �ϱ� ������ getline()�� ����ؾ� �Ѵ�.
// �ִ� 100�ٵ��� �־����� ���ڿ��� ��� �Է¹޾� �״�� ����ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int main()
{
    string str;
    // �Է��� ��ӵǴ� ���� �״�� ����Ѵ�.
    while (getline(cin, str))
    {
        cout << str << '\n';
    }
    return 0;
}