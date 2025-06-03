#include <iostream>
#include <cmath>

using namespace std;

// 풀이.
// 처음 문제를 읽으면서 생각할 때에는 백트래킹 같은 전부 대입해보는 로직을 생각했으나
// 문자열의 길이가 최대 10만이라는 걸 보고 포기했다. 결과적으로 점화식을 하나 생각해냈는데
// 다음과 같다.

// (각 문자열의 차이수(X라고 칭함) - B 혹은 W의 문자의 차이수(Y라고 칭함)) / 2 + B 혹은 W의 문자의 차이수

// 두 문자열을 한번에 순회하며 X와 각 문자열의 B의 개수를 구한 후 abs()를 통해 B의 차이수인 Y를
// 구할 수 있다. 그 이후 위의 점화식을 이용하면 O(N)만에 답을 구할 수 있다.

// 자세한 설명은 주석으로 남긴다.

int T;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    for (int iter = 0; iter < T; ++iter)
    {
        int ssize;
        string from, to;
        cin >> ssize >> from >> to;

        // 각각 두 문자열의 차이수, 초기 문자열의 B의 개수, 목표 문자열의 B의 개수
        int dif = 0, fromB = 0, toB = 0;
        for (int i = 0; i < ssize; ++i)
        {
            dif = from[i] != to[i] ? dif + 1 : dif;
            fromB = from[i] == 'B' ? fromB + 1 : fromB;
            toB = to[i] == 'B' ? toB + 1 : toB;
        }
        // abs()를 통해 두 문자열의 B의 차이수를 구한다.
        // 두 문자열중 어느 문자열에서 B가 더 많은지 알 수 없기에 abs()를 써야했다.
        int difB = abs(fromB - toB);
        // 상술한 점화식을 이용하여 답을 구해낸다.
        cout << (dif - difB) / 2 + difB << '\n';
    }
    return 0;
}