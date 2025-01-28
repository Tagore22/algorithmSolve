#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

// Ǯ��.
// ���� ��ü�� ���̵��� ������ �𸣰����� �������� �׷��ϵ� ����� ��������. 
// �ѹ��� ��ȸ���� ppap�� �߰��ҽ� p�� ��ü�Ͽ� ������� ����ϴ°��� �и��ߴµ� �� ������
// ���ø��°��� ���� �ʾҴ�. ���ڿ��� ��ȸ�ϸ� �� P�� A�� ������ ������ ���� �ൿ�� �ϰ� �ȴ�.

// 1. P�� ��������. P�� ���ÿ� �߰����� P�� ���� p�� 1 �ø���.
// 2. A�� ��������. p�� 2�̻��� ���鼭 �ٷ� �� ���ڰ� p�� ��� ppap�� �ش��ϴ� ����̹Ƿ�
// ������ ���� 2���� �������� p�� �߰��ϸ鼭 �ε������� 1�� �÷� ��ĭ �ǳ� �ڴ�.
// �׷��� ���� ��� �׳� A�� ���ÿ� �ִ´�.
// A�� ù��° ��찡 ���� �򰥷ȴµ� ������ ����� �� PPAP�� �������������� ��ȸ ���� P �Ǵ�
// PPAP�� �����ϰ� �Ǳ� �����̴�. ���� ��� PAPAP���� ��� �ι�° A���� 2�� ù��° ���ǿ�
// ���� ���� 2���� ���Ұ� ���󰡰� P�� �߰������� ����ε� PPAP�� �ƴϱ⿡ ��������� PP�� ����
// NP�� ��µȴ�.

// �ڼ��� ������ �ּ����� �����.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;

    stack<char> sta;
    int p = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == 'P')
        {
            sta.push(str[i]);
            ++p;
        }
        else
        {
            if (p >= 2 && str[i + 1] == 'P')
            {
                // ����Ѵ�� ����ε� PPAP�� A�� �ƴ� ��� ���� ��Ʋ���� �Ǿ�
                // NP�� ����ϰ� �ȴ�.
                sta.pop();
                sta.pop();
                sta.push('P');
                --p;
                ++i;
            }
            else
            {
                sta.push(str[i]);
            }
        }
    }

    string answer = "";
    while (!sta.empty())
    {
        answer += sta.top();
        sta.pop();
    }

    reverse(answer.begin(), answer.end());
    if (answer == "PPAP" || answer == "P")
        cout << "PPAP" << '\n';
    else
        cout << "NP" << '\n';
    return 0;
}