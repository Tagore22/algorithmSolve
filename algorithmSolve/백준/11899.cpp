#include <iostream>

using namespace std;

//Ǯ��
//'('�� ')'�� ������ �����Ѵ�. '('�� ������ ���� plus�� 1 �����ϰ� ')'�� ������ plus�� 1 �̻��� ��� �����Ѵ�.
//�ٸ� plus�� 0�̶�� �� '('���� ')'�� �ִٴ� ���̱⿡ �߰��ؾ��ϴ� ��ȣ�� answer�� 1 �����Ѵ�.
//string�� ��� ��ȸ�� ���� plus�� 1�̻��̶�°� '('�� ')'�� ������ ����ä ���� �ִٴ� ���̱⿡ answer�� ���� plus���� ���ؼ�
//���� ������ ����Ѵ�.

string str;

void MakeAnswer()
{
    int answer = 0;
    int plus = 0;
    for (auto& c : str)
    {
        if (c == '(')
        {
            ++plus;
        }
        else
        {
            if (plus != 0)
                --plus;
            else
                ++answer;
        }
    }
    cout << answer + plus << '\n';
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