#include <iostream>

using namespace std;

// 풀이
// 1로 주어진 수들의 최대공약수를 구하는 문제라지만 실상은 주어진 입력값들의 최대공약수를 구해 그만큼 1을 출력하면 되는 문제다.

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