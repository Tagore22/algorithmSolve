#include <iostream>

using namespace std;

//Ǯ��
//�� �м��� 4���� �Է¹޾� �и�鰣�� �ּҰ������ ���Ѵ�. �� ��, �� ���ڵ��� �и���� �ּҰ���� / �ڽ��� �и����� ��������
//�� ���ڰ��� ���ϸ� �� �м����� ���Ѱ��� �Ǵµ�, ���м��� ����϶�� �߱⿡ ���������� ���� �и�� ���ڰ��� �ִ������� ������
//�и�� ���ڰ��� ����ϸ� �ȴ�. ����, �ԷµǴ� ���� �ִ밪�� 3���̱⿡ �������� �ִ밪�� 9���̶� int�������ε� ����� ������ �����ϴ�.

pair<int, int> board[2];

int Gcd(int a, int b)
{
    if (b == 0)
        return a;
    return Gcd(b, a % b);
}

int Lcm(int a, int b)
{
    return a * b / Gcd(a, b);
}

void MakeAnswer()
{
    int lcm_num = Lcm(board[0].second, board[1].second);
    int first_mul = lcm_num / board[0].second;
    int second_mul = lcm_num / board[1].second;

    int up_num = board[0].first * first_mul + board[1].first * second_mul;
    int down_num = lcm_num;
    int gcd_num = Gcd(up_num, down_num);

    cout << up_num / gcd_num << ' ' << down_num / gcd_num << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 2; ++i)
        cin >> board[i].first >> board[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}