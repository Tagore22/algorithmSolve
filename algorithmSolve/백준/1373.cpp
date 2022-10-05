#include <iostream>
#include <cmath>

using namespace std;

//ó���� 2���� >> 10���� >> 8������ ���������� ������ ���� �ִ� 100���ڸ��淡 �ƴϱ��� �;���.
//2���� >> 8������ �ϸ� �Ǵµ� �� �ڸ��� 3������ ���ؼ� ���̱⸸ �ϸ� �ȴ�.
//���� ���� �Ǿ� ��, answer[0]�� 0�Ͻ� ���ֹ��Ⱦ��µ� �ٽ� �����غ��� 8���� ��ü�� ����ؾ�������
//�׷� �ʿ䰡 ������.

constexpr int DIVNUM = 3;
string str;

void MakeAnswer()
{
    string answer = "";
    int check = 0;
    int str_size = str.size();
    for (int i = 0; i < str_size; ++i)
    {
        int pow_num = (str_size - i - 1) % DIVNUM;

        if (str[i] == '1')
            check += pow(2, pow_num);

        if (pow_num == 0)
        {
            answer.push_back(check + '0');
            check = 0;
        }
    }

    //int idx = answer[0] == '0' ? 1 : 0; << �� ���� 0�̸� ��¿��� �����ϴ� �ڵ�. �׷��� 8���� ��ü�� ����ؾ������� �ʿ����.
    for (int i = 0; i < answer.size(); ++i)
        cout << answer[i];
    cout << '\n';
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