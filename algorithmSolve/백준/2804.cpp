#include <iostream>

using namespace std;

// Ǯ��.
// ������.. �������� ����� ���� ����� Ư���� �⺻���� ��¿� ���� �߽��� ������.
// ���ڿ� A�� B�� �־����� A���� ���� �տ������� ���� B�� ���� �տ������� �� ���ڿ��� ��ġ�� ���ڸ�
// ã�� ũ�ν��� ����ϴ� ������.

// �ڼ��� ������ �ּ����� �����.

string str1, str2;
int a, b;

// ���� for������ ���� �պκп������� ��ġ�� ������ ��ġ�� ã�� �Լ�.
void FindPivot()
{
    for (int i = 0; i < str1.size(); ++i)
    {
        for (int j = 0; j < str2.size(); ++j)
        {
            if (str1[i] == str2[j])
            {
                a = i, b = j;
                return;
            }
        }
    }
}

void MakeAnswer()
{
    cin >> str1 >> str2;
    FindPivot();
    // ��ºκ��� ���� ��ٷο���. 
    for (int i = 0; i < b; ++i)
    {
        for (int j = 0; j < a; ++j)
            cout << '.';
        cout << str2[i];
        for (int j = a + 1; j < str1.size(); ++j)
            cout << '.';
        cout << '\n';
    }
    cout << str1 << '\n';
    for (int i = b + 1; i < str2.size(); ++i)
    {
        for (int j = 0; j < a; ++j)
            cout << '.';
        cout << str2[i];
        for (int j = a + 1; j < str1.size(); ++j)
            cout << '.';
        cout << '\n';
    }
}

int main()
{
    MakeAnswer();
    return 0;
}