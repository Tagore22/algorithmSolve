#include <iostream>

using namespace std;

// 찾지 못했던 규칙을 이용한 풀이.

int main()
{
    int M, N;
    cin >> M >> N;
    cout << (M > N ? N * 2 - 1 : M * 2 - 2) << '\n';
    return 0;
}