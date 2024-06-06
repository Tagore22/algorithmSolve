#include <iostream>

using namespace std;

// 풀이.
// 주어지는 두 수 N과 M이 동일하다면 1을, 그렇지 않다면 0을 출력하는 문제.
// 다만, N과 M의 최대값이 10자리 정수인데 이는 int의 최대값인 24억가량을 손쉽게 넘어서므로
// int가 아닌 long long 타입의 변수로 구현해야한다.

int main()
{
    long long N, M;
    cin >> N >> M;
    cout << (N == M ? 1 : 0) << '\n';
    return 0;
}