#include <iostream>
#include <cmath>

//Ǯ��
//���ĺ��� ���ڰ� ������ �Է��� �ޱ⿡ string���� �Է��� �޾Ƽ� �� �ڸ����� 16�� �������� ��ȯ�� �� �ڸ����� ���Ѱ��� ���ذ���.

using namespace std;

string str;

void MakeAnswer()
{
    int answer = 0, check, idx = str.size() - 1;
    for (int i = 0; i < str.size(); ++i)
    {
        if ('0' <= str[i] && str[i] <= '9')
            check = str[i] - '0';
        else
            check = str[i] - 55;
        answer += check * pow(16, idx - i);
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