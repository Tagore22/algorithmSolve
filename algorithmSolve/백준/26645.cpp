#include <iostream>

using namespace std;

// 풀이.
// 처음에는 단순히 예시에 있는 범위를 사용하면 되지 않을까 했지만 그렇지 않았다.
// 예를 들어 레벨이 206일 경우 1번 비약을 쓰든 2번 비약을 쓰든 똑같이 210까지 
// 올릴 수 있으나 동일한 레벨일 경우 숫자가 큰 비약을 써야하므로 2번 비약을 쓰게 된다.
// 따라서 범위는 N번 비약에서 올릴 수 있는 최대 레벨 - N + 1번 비약의 수 이전까지이다.

int main()
{
    int N;
    cin >> N;

    if (N < 206)
        cout << 1 << '\n';
    else if (N < 218)
        cout << 2 << '\n';
    else if (N < 229)
        cout << 3 << '\n';
    else
        cout << 4 << '\n';
    return 0;
}