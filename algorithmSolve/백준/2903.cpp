#include <iostream>

using namespace std;

// 풀이.
// 각 꼭지점의 수는 2의 배수만큼 늘어난다. 최종 꼭지점의 수는 그 제곱이다.

int N;

int main()
{
    cin >> N;
    int idx = 1, num = 3;
    for (int i = 1; i < N; ++i)
    {
        idx *= 2;
        num += idx;
    }
    cout << num * num << '\n';
    return 0;
}