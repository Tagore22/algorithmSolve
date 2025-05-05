#include <iostream>

using namespace std;

// 풀이.
// 피보나치를 이용한 문제이다. 예시를 잘 살펴보면 알수 있듯이 N개의 타일로 이루어진 직사각형의 둘레는
// N번째 피보나치의 수 * 2 + N + 1번째 피보나치의 수와 동일하다. 다만, 문제에서 알려주듯 피보나치의 수
// 값이 int 범위를 벗어날 수도 있으므로 long long 타입의 변수를 사용해야 한다.

long long FiboDP[82];
int N;

int main()
{
    cin >> N;
    FiboDP[1] = 1;
    for (int i = 2; i <= N + 1; ++i)
        FiboDP[i] = FiboDP[i - 1] + FiboDP[i - 2];
    cout << FiboDP[N + 1] * 2 + FiboDP[N] * 2 << '\n';
    return 0;
}