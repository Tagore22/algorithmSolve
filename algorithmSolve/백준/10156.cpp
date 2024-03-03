#include <iostream>

using namespace std;

// 풀이.
// 현재 소지값이 사고자 하는 값보다 적다면 그 값을, 같거나 크다면 0을 출력하면 된다.

int main()
{
    int K, N, M;
    cin >> K >> N >> M;
    int answer = K * N - M;
    cout << (answer > 0 ? answer : 0) << '\n';
    return 0;
}