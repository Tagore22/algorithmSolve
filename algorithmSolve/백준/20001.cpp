#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    int p = 0;
    while (true)
    {
        getline(cin, str);
        if (str == "����")
            ++p;
        else if (str == "������")
            p = p == 0 ? 2 : p - 1;
        else if (str == "������ ����� ��")
            break;
    }
    cout << (p == 0 ? "�������� �����" : "����") << '\n';
    return 0;
}