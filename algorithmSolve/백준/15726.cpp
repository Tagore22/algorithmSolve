#include <iostream>

using namespace std;

// 풀이.
// 문제에서 소수점을 버리라길래 왜 실수로 계산해야하나 했는데 계산 도중에는 소수점을 그대로 살린 형태로
// 계산한 후에 마지막에 정수화시키는 것이었다. 또한, float는 자리수가 작아서 오차가 심하기 때문에
// 실수를 사용하는 문제에서는 float가 아니라 long double을 사용하자.

int main()
{
    long double a, b, c;
    cin >> a >> b >> c;
    int answer = max((a / b * c), (a * b / c));
    cout << answer << '\n';
}