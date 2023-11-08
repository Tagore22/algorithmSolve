#include <iostream>

using namespace std;

// 풀이.
// 주어지는 가격과 개수들의 총합이 X와 같은지 확인하는 문제.

// 자세한 설명은 주석으로 남긴다.

int X, N, a, b;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> X >> N;
    int answer = 0;
    // 모든 물건들의 가격과 개수를 입력받아 그 합이 X와 같은지 확인한다.
    for (int i = 0; i < N; ++i)
    {
        cin >> a >> b;
        answer += a * b;
    }

    // 같다면 Yes를, 다르다면 No 출력.
    cout << (answer == X ? "Yes" : "No") << '\n';
    return 0;
}