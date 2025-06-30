#include <iostream>

using namespace std;

// 풀이.
// n의 최대값이 2의 63제곱 - 1이었기 때문에 1씩 늘려가며 구하기엔 그 제곱근조차
// 10억을 훌쩍 뛰어넘는 수이기에 불가능했다. 하지만 이분 탐색을 이용한다면
// 100번도 안되서 구할 수 있었다.

int main()
{
    unsigned long long n;
    cin >> n;
    if (n == 0)
    {
        cout << 0 << '\n';
        return 0;
    }
    unsigned long long from = 1, to = 3037000500, mid;
    while (from <= to)
    {
        mid = (from + to) / 2;
        if (mid * mid >= n)
            to = mid - 1;
        else
            from = mid + 1;
    }
    cout << to + 1 << '\n';
    return 0;
}