#include <iostream>

using namespace std;

// Ǯ��.
// ó������ �ָԱ��������� String�� ��ȭ�ϴ� ������ �ߴµ� K�� 31�϶����� �����ŷȴ�.
// N�� ��ư�� ���������� ���� Ȯ���غ��� �Ǻ���ġ ������ ���� ��ȭ���� ã�� �� �־���.

int A[46], B[46];
int K;

int main()
{
    cin >> K;
    A[1] = 0;
    A[2] = 1;
    B[1] = 1;
    B[2] = 1;
    for (int i = 3; i <= K; ++i)
    {
        A[i] = A[i - 2] + A[i - 1];
        B[i] = B[i - 2] + B[i - 1];
    }
    cout << A[K] << ' ' << B[K] << '\n';
    return 0;
}