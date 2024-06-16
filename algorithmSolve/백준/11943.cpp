#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 두 바구니에 한종류의 과일만 남는 경우는 다음과 같다.

// 1. A 바구니의 사과를 B로 옮기고 B 바구니의 오렌지를 A로 옮김.
// 2. A 바구니의 오렌지를 B로 옮기고 B 바구니의 사과를 A로 옮김.

// 결과적으로 주어지는 A, B, C, D에서 A와 D를 옮기거나, B와 C를 옮기는 것이다.
// 따라서 A + D와 B + C중 더 작은값을 출력하면 된다.

int main()
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    cout << min(A + D, B + C) << '\n';
    return 0;
}