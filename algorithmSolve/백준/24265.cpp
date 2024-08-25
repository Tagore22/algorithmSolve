#include <iostream>

using namespace std;

// 풀이
// n의 값이 최대 50만이기 때문에 점화식에 의한 값이 int값을 벗어난다.
// n을 이용한 연산값이기 때문에 타입은 int로 되어 있어 오버플로우가 일어남으로
// n의 타입을 long long으로 해주어야 한다.

int main()
{
    long long n;
    cin >> n;
    cout << n * (n - 1) / 2 << '\n';
    cout << 2 << '\n';
    return 0;
}