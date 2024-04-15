#include <iostream>

using namespace std;

// 풀이.
// 1씩 증가하는 곱셈의 결과인 팩토리얼을 출력하는 문제이다.
// 다만 주어지는 N의 최대값이 20일 경우 답이 int값을 벗어나기 때문에 long long타입으로 구현해야한다.

int main()
{
    int N;
    cin >> N;
    long long answer = 1;
    for (int i = 1; i <= N; ++i)
        answer *= i;
    cout << answer << '\n';
    return 0;
}