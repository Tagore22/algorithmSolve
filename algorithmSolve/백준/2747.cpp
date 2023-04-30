#include <iostream>
#include <cstring>

// 풀이.
// 흔한 피보나치 수열 구현 문제.

using namespace std;

int fibo[46];
int N;

int FindFibo(int idx)
{
    if (idx == 0 || idx == 1)
        return idx;

    int& ans = fibo[idx];
    if (ans != -1)
        return ans;

    return ans = FindFibo(idx - 1) + FindFibo(idx - 2);
}

int main()
{
    cin >> N;
    memset(fibo, -1, sizeof(fibo));
    cout << FindFibo(N) << '\n';
    return 0;
}