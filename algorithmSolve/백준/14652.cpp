#include <iostream>

using namespace std;

// 풀이.
// 0, 0에서 오른쪽으로 번호가 증가하므로 M을 이용하여 계산할수 있다.

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    cout << K / M << ' ' << K % M << '\n';
    return 0;
}