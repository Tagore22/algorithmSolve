#include <iostream>
#include <string>

using namespace std;

// ������ ������ ���ڿ��� �Ź� �Է¹޾� �״�� ����ϸ� �ȴ�.

string str;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (getline(cin, str))
    {
        cout << str << '\n';
    }

    return 0;
}