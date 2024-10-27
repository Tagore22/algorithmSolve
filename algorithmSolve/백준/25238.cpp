#include <iostream>

using namespace std;

// 풀이.
// 언젠가 지나가듯 봤던 '실수 연산에서는 float보다는 long double을 써라'라는 글이 기억났던 문제이다.
// 다만 이 문제는 오차에 대해 신경쓸 필요가 없으니 float를 써도 상관이 없다.

int main()
{
    float a, b;
    cin >> a >> b;
    cout << (a - (a * b / 100) < 100) ? 1 : 0 << '\n';
    return 0;
}