#include <iostream>

using namespace std;

//�ܼ��� �ƽ�Ű�ڵ� + ���������ε� ó���� mul�� ���Ҷ� pow�Լ��� �����. ������ pow�Լ��� ����� ���� �ʹ�Ŀ���� 
//�����÷ο찡 �߻��ϱ� ���� ��� �Ұ����Ͽ� ���� Ǯ�� ����, ���� ���� 31�� ���ذ��� DIVNUM�� �Ѱ�����
//���� �ٿ����� ������� ����ϸ� �ȴ�.

string str;
int L;
constexpr int ASC = 96;
constexpr int MULNUM = 31;
constexpr int DIVNUM = 1234567891;

//mul�� int�� �߸� �����߾���. ���� mul�� int��� for�� ����°�ٿ��� int ���� 2���� �������� 
//int�� �ִ밪�� �Ѱ� �����÷ο찡 �ǰ�, ���� ���Ҽ��� ����.

void MakeAnswer()
{
    long long answer = 0;
    long long mul = 1;
    for (int i = 0; i < L; ++i)
    {
        answer += (str[i] - ASC) * mul;
        answer %= DIVNUM;
        mul = mul * MULNUM % DIVNUM;
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> L >> str;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}