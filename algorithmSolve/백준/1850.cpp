#include <iostream>

using namespace std;

// Ǯ��
// 1�� �־��� ������ �ִ������� ���ϴ� ���������� �ǻ��� �־��� �Է°����� �ִ������� ���� �׸�ŭ 1�� ����ϸ� �Ǵ� ������.

long long A, B;

long long gcd(long long lhs, long long rhs)
{
    if (rhs == 0)
        return lhs;
    return gcd(rhs, lhs % rhs);
}

void MakeAnswer()
{
    int answer = gcd(A, B);
    for (int i = 0; i < answer; ++i)
        cout << 1;
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> A >> B;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}