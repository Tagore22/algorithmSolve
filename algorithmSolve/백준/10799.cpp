#include <iostream>

using namespace std;

// Ǯ��.
// ���� ������� �� cur�� ���� ����Ⱚ answer�� ������, �� �������� ������ ���� ������ �ִ�.

// 1. ���� ���Ұ��� '('�϶� cur�� answer�� 1�� ������Ų��. 
// 2. ���� ���Ұ��� ')'�϶�
// 2-1. �� �� ���Ұ��� '('�̶�� ���� �������̹Ƿ� ������ �������״� cur�� answer�� �ٽ� 1�� ���ҽ�Ű��
// answer�� cur��ŭ ������Ų��.(�������� ��������.)
// 2-2. �� �� ���Ұ��� ')'�̶�� �������� �ƴ� ���� ª�� �踷����� ���̱⿡ cur�� 1 ���ҽ�Ų��.

// �� ������ �����س��� �ȴ�.

string str;

void MakeAnswer()
{
    int cur = 1, answer = 1;
    for (int i = 1; i < str.size(); ++i)
    {
        if (str[i] == '(')
        {
            ++cur;
            ++answer;
        }
        else
        {
            if (str[i - 1] == '(')
            {
                --cur;
                --answer;
                answer += cur;
            }
            else
            {
                --cur;
            }
        }
    }
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