#include <iostream>

using namespace std;

// 풀이.
// 17266번의 더 간단한 풀이. 너무 복잡하게 생각했는데 정리하자면 다음과 같다.

// 1. 0에서 첫번째 가로등까지와 맨 마지막 가로등에서 N까지의 거리는 하나의 가로등이 비추어야한다
// 2. 각 가로등 사이의 거리는 2개의 가로등이 나누어서 비출 수 있다.

// 위 조건에 입각하여 각 거리들의 최대값을 비교하면 되는데 2번은 나누어서 비출 수 있는것을
// 너무 어렵게 생각했다. 그냥 1번값들을 2배로 곱하고 2번값들과 비교하면 된다.
// 다만, 최대값이 홀수일때가 있다. 최대값이 2번값들중 하나인 홀수값일때가 그러한데
// 이때 단순히 이 값을 다시 2로 나누게 되면 실제 비추는 값과 1의 차이가 존재하게 되므로
// 최대값을 1 증가시켜 2로 나누어야 한다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    int gap, prev, cur;
    cin >> prev;
    gap = prev * 2;
    for (int i = 1; i < M; ++i)
    {
        cin >> cur;
        gap = max(gap, cur - prev);
        prev = cur;
    }
    gap = max(gap, (N - prev) * 2);
    gap = gap % 2 != 0 ? gap + 1 : gap;
    cout << gap / 2 << '\n';
    return 0;
}