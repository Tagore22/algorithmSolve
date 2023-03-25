#include <iostream>
#include <stack>

using namespace std;

// Ǯ��.
// ������ Ǯ��� ���쳪 ���� ������ �ľ��ϱⰡ ��ô �������.
// ��������� �����ϴ� ��ȣ�϶��� ���簪�� �����ְ� 
// ������ ��ȣ�� ù��° ������ ��ȣ�϶� ���簪�� �������� �����ش�.
// ���� ������ ������ �������ش�.

// �������� ������ ������� �ʴٸ� 0�� ����ϸ� �ȴ�.

string str;

void MakeAnswer() // Ȧ���϶��� ������ ���� �ȵȴ�.
{
    if (str.size() % 2 == 1 || str[0] == ')' || str[0] == ']')
    {
        cout << 0 << '\n';
        return;
    }

    stack<char> cha;

    int cur = 1, answer = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == '(')
        {
            cur *= 2;
            cha.push(str[i]);
        }
        else if (str[i] == '[')
        {
            cur *= 3;
            cha.push(str[i]);
        }
        else if (str[i] == ')')
        {
            if (cha.empty() || cha.top() != '(')
            {
                cout << 0 << '\n';
                return;
            }

            if (str[i - 1] == '(')
                answer += cur;

            cur /= 2;
            cha.pop();
        }
        else
        {
            if (cha.empty() || cha.top() != '[')
            {
                cout << 0 << '\n';
                return;
            }

            if (str[i - 1] == '[')
                answer += cur;

            cur /= 3;
            cha.pop();
        }
    }
    cout << (cha.empty() ? answer : 0) << '\n';
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