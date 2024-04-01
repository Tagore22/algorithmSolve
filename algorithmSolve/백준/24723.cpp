#include <iostream>
#include <cmath>

using namespace std;

// 현재 블록에서 좌우 둘중 하나로 이동하기 때문에 결과적으로 2의 N제곱이 된다.

int main()
{
    int N;
    cin >> N;
    cout << pow(2, N) << '\n';
    return 0;
}