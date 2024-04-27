#include <iostream>

using namespace std;

// 풀이.
// 그냥 주먹구구식으로 풀면 C가 최대 10억이기 때문에 연산량이 많아 시간초과에 걸린다.
// 따라서 XOR의 성질을 이용하여야 하는데 잘 알듯이 두 비트가 다르면 1이 되는 성질이므로
// 같은 비트로 XOR 연산을 두번하면 다시 자기자신이 된다. 결과적으로 연산횟수를 뜻하는 C의 값이
// 홀수이면 A ^ B를, 짝수이면 원래대로 돌아온 A를 출력하면 된다.

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    if (C % 2 == 0)
        cout << A << '\n';
    else
        cout << (A ^ B) << '\n';
    return 0;
}