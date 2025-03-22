#include <iostream>

using namespace std;

// 풀이.
// 처음에는 주먹구구식으로 String을 변화하는 구현을 했는데 K가 31일때에도 버벅거렸다.
// N번 버튼을 눌렀을때의 수를 확인해보니 피보나치 수열과 같은 점화식을 찾을 수 있었다.

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