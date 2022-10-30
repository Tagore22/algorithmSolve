#include <iostream>
#include <string>

using namespace std;

//�յڿ� 0 ������ ����� �� �ߴµ� ��������� string������ �������� ���� ������ �ƴ� ���� int�� �ٲپ� ���� ������ ��Ű�� 0�� ����
//�������� ��� �������. �ִ밪�� 1000�̱⿡ �����÷ο���� ������ �ʿ䵵 ����.

string a, b;

int ReverseConvert(const string& str)
{
    int con = 0, iter = 1;
    for (int i = 0; i < str.size(); ++i)
    {
        con += (str[i] - '0') * iter;
        iter *= 10;
    }

    return con;
}

void MakeAnswer()
{
    int first = ReverseConvert(a);
    int second = ReverseConvert(b);

    cout << ReverseConvert(to_string(first + second)) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}