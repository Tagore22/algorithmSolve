#include <iostream>

using namespace std;

// 풀이.
// 원의 둘레 = 2 * 파이 * 반지름.

int main()
{
    int d1, d2;
    cin >> d1 >> d2;
    cout.precision(6);
    cout << fixed;
    cout << d1 * 2 + d2 * 3.141592 * 2 << '\n';
    return 0;
}