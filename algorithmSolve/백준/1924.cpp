#include <iostream>

using namespace std;

//Ǯ��
//1�� 1�Ϸκ��� �����̳� ���������� ��� ������ 7�Ϸ� ������ �����Ϻ��� ���� �ϼ���ŭ �ѱ�� �ȴ�.

int month[12] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 };
string days[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
int x, y;

void MakeAnswer()
{
    int check = 0;
    for (int i = 1; i < x; ++i)
        check += month[i];
    check += y - 1;
    check %= 7;
    cout << days[check] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> x >> y;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}