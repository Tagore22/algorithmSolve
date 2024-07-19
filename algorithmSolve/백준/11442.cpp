#include <iostream>

using namespace std;

// Ǯ��.
// ���� �����ļ� �׷��� �ŵ����� ������ ��� ���´�. �˰��� ���� Ǯ���ϸ鼭 2�� �ôµ�
// �� 2���� ���� �����̴�. ��... �Ѱ��� �и��ϰ� ����ؾ��� ���� ������ �����Ҷ�
// N������ ȣ���� log�� ���ϼ� �ִٴ� ���̴�. �ð����� �ŵ����� �ѹ� ���ξ�߰ڴ�.

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