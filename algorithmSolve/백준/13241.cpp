#include <iostream>

using namespace std;

// 풀이.
// 최소공배수의 점화식은 두 수의 곱 / 최대공약수이다. 최대공약수는 이미 계산이 가능하므로
// 위 점화식값을 그대로 출력하면 된다.

long long a, b;

long long GDC(int a, int b)
{
    if (b == 0)
        return a;
    return GDC(b, a % b);
}

int main()
{
    cin >> a >> b;
    cout << a * b / GDC(a, b) << '\n';
    return 0;
}