#include <iostream>

using namespace std;

// 풀이.
// 주어지는 값 N이 4증가할때마다 long을 하나씩 덧붙여주면 된다.

int main()
{
    int N;
    cin >> N;
    for (int i = 1; i <= N / 4; ++i)
        cout << "long ";
    cout << "int" << '\n';
    return 0;
}