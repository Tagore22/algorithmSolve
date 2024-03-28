#include <iostream>

using namespace std;

// 풀이.
// 와! 새싹 문제! 결과값이 가장 커지는 경우는 100000, 1이 주어지는 경우인데 이때
// 결과값이 90억이 넘기 때문에 int로는 100점을 맞을수 없음에 주의할것.

int main()
{
    long long A, B;
    cin >> A >> B;
    cout << (A + B) * (A - B) << '\n';
    return 0;
}