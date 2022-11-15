#include <iostream>

using namespace std;

//1057���� ��ü������ ���� ��������, �ణ �ٸ� Ǯ��. �������� 1������� �����ϱ⿡ a,b �� ������ ���ۺ��� ���� ����������,
//0������� �����ϸ� while���� �ѹ� �� �����ϳ�, �ڵ尡 ���� �� ��������� ���̵� �̾��ϰԳ��� �پ���.

int N, a, b;

void MakeAnswer()
{
    int answer = 0;

    while (a != b)
    {
        a = a % 2 == 0 ? a / 2 : a / 2 + 1;
        b = b % 2 == 0 ? b / 2 : b / 2 + 1;
        ++answer;
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> a >> b;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}