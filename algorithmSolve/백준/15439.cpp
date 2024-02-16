#include <iostream>

using namespace std;

// 풀이.
// 상의 i번째와 하의 i번째는 모두 색이 같으며 1 ~ N까지 모든 색이 다르니
// 각 상의별로 같은 i번째 하의를 제외하고 나머지를 모두 고를수 있다.
// 따라서 점화식은 N * (N - 1)이 된다.

int main()
{
    int N;
    cin >> N;
    cout << N * (N - 1) << '\n';
    return 0;
}