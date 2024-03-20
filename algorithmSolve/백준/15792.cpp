#include <iostream>

using namespace std;

// 풀이.
// double로도 1000자리의 오차까지는 판명할수 없으므로 직접 계산해야한다.
// 따라서 1 / 3을 1000자리까지 소수부와 정수부로 나누어 직접 계산하면 된다.

int main()
{
    int a, b;
    cin >> a >> b;
    cout << a / b << '.';

    for (int i = 0; i < 1000; ++i)
    {
        a %= b;
        a *= 10;
        cout << a / b;
    }
    return 0;
}