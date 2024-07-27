#include <iostream>

using namespace std;

// 풀이.
// 예시의 함수가 1 ~ n까지의 for문이 2중으로 구현되어 있기에
// 무조건 N의 제곱만큼 수행된다. 하지만 N이 최대 50만이기 때문에
// int로 구현하면 오버플로우가 난다. 따라서 long long으로 구현해야한다.

int main()
{
    long long N;
    cin >> N;
    cout << N * N << '\n';
    cout << 2 << '\n';
    return 0;
}