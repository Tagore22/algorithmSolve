#include <iostream>
#include <string>

using namespace std;

// Ǯ��.
// 2���� ���� �Է¹޾� �� ������ �ִ밪�� �ּҰ��� ������
// 2���� �ּҰ��� 2���� �ִ밪�� ���� ���Ͽ� ����Ѵ�.

int main()
{
    string a, b;
    cin >> a >> b;
    string a_Min = "", a_Max = "";
    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] == '5' || a[i] == '6')
        {
            a_Min += "5";
            a_Max += "6";
        }
        else
        {
            a_Min += a[i];
            a_Max += a[i];
        }
    }
    string b_Min = "", b_Max = "";
    for (int i = 0; i < b.size(); ++i)
    {
        if (b[i] == '5' || b[i] == '6')
        {
            b_Min += "5";
            b_Max += "6";
        }
        else
        {
            b_Min += b[i];
            b_Max += b[i];
        }
    }
    cout << stoi(a_Min) + stoi(b_Min) << ' ' << stoi(a_Max) + stoi(b_Max) << '\n';
    return 0;
}