#include <iostream>
#include <string>

using namespace std;

// Ǯ��.
// ������ ���Ե� ���ڿ��� �Է¹��� �� ���� ���� �̸�Ƽ�ܰ� ��� �̸�Ƽ���� ������ �ľ�����
// ���Ͽ� �� ������� ����Ѵ�.

// �ڼ��� ������ �ּ����� �����.

string str;

void MakeAnswer()
{
    int h = 0, s = 0;
    // ��� ���ڵ��� ��ȸ�ϸ� �� �̸�Ƽ���� ������ �ľ��Ѵ�.
    for (int i = 0; i < str.size() - 2; ++i)
    {
        if (str[i] == ':' && str[i + 1] == '-')
        {
            if (str[i + 2] == ')')
                ++h;
            else if (str[i + 2] == '(')
                ++s;
        }
    }

    // �� �̸�Ƽ���� ������ ���Ͽ� ������� ����Ѵ�.
    if (h == 0 && s == 0)
        cout << "none" << '\n';
    else if (h == s)
        cout << "unsure" << '\n';
    else if (h > s)
        cout << "happy" << '\n';
    else
        cout << "sad" << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    getline(cin, str);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}