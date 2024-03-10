#include <iostream>

using namespace std;

// 풀이.
// 무슨 시그마의 공식이라는데 옘병 다 배낀 풀이들 뿐이다.

long long N;

int main()
{
    cin >> N;
    cout << (N - 2) * (N - 1) * N / 6 << '\n';
    cout << 3 << '\n';
    return 0;
}