#include <iostream>

using namespace std;

// 풀이.
// 어제 도망쳐서 그런지 거듭제곱 문제가 계속 나온다. 알고리즘 문제 풀이하면서 2번 봤는데
// 그 2번이 어제 오늘이다. 흠... 한가지 분명하게 기억해야할 것은 조건이 충족할때
// N까지의 호출을 log로 줄일수 있다는 점이다. 시간날때 거듭제곱 한번 봐두어야겠다.

const int MOD = 1000000007;
long long X[2][2] = { 0, 1, 1, 1 };

void fibo(long long result[][2], long long f[][2]) {
    int temp[2][2] = { 0, };
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                temp[i][j] += (result[i][k] * f[k][j]) % MOD;

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            result[i][j] = temp[i][j] % MOD;
}
int main() {
    long long n, result[2][2] = { 1, 0, 0, 1 };
    cin >> n;
    n += (n % 2 ? 1 : 0);
    while (n) {
        if (n & 1) fibo(result, X);
        fibo(X, X);
        n >>= 1;
    }
    cout << result[1][0] << '\n';
    return 0;
}