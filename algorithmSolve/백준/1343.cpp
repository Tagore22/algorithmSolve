#include <iostream>

using namespace std;

// Ǯ��.
// X�� A Ȥ�� B�� ��ü�ϴ� �����̴�. ���������� �ռ��� ���� ����ؾ��ϱ� ������ A�� ���� �����غ��ƾ� �Ѵ�.
// �ٸ�, A�� 4���� B�� 2���̱� ������ �̺κ��� �����ؼ� �����ϸ� �ȴ�.

string str, answer = "";

void MakeAnswer()
{
    int num = 0;
    for (int iter = 0; iter < str.size(); ++iter)
    {
        if (str[iter] == 'X')
        {
            ++num;
        }
        else
        {
            if (num % 2 != 0)
            {
                cout << -1 << '\n';
                exit(0);
            }
            for (int i = 0; i < num / 4; ++i)
                answer += "AAAA";
            num %= 4;
            for (int i = 0; i < num / 2; ++i)
                answer += "BB";
            num %= 2;
            answer += ".";
        }
    }
    if (num % 2 != 0)
    {
        cout << -1 << '\n';
        exit(0);
    }
    for (int i = 0; i < num / 4; ++i)
        answer += "AAAA";
    num %= 4;
    for (int i = 0; i < num / 2; ++i)
        answer += "BB";
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}