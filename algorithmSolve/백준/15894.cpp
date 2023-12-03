#include <iostream>

using namespace std;

// 풀이.
// 직접 대비해보면 알겠으나 결과적으로 점화식은 맨 아래 길이 N * 4가 나온다.
// 양 옆의 길이는 N이 되고, 맨 아래도 N이 되며 맨 위는 맨 위층이 1이고 그 아래
// 0.5씩 2개가 총 N - 1이 존재한다. 즉, 1 + 0.5 * 2 * N - 1이 되어 총 N이 된다.
// 따라서 상술한대로 점화식은 N * 4가 된다.

long long N;

int main()
{
    cin >> N;

    cout << N * 4 << '\n';
    return 0;
}