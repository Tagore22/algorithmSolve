#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 수학적 접근을 필요로 하는 그리디 문제이다.
// 도저히 생각이 안나서 풀이를 본 문제다.
// 여러가지 해설이 있었는데 그중 가장 와닿은 해설은 다음과 같다.

// 1. 오름차순으로 정렬된 원생들의 키 board[]가 있다.
// 2. 각 board[i] - board[i - 1]인 dif[]가 있다.
// 3. K개의 조로 나눈다는 것은 결과적으로 K - 1개의 경계를 만드는 것과 같은데 이 경계값은 티셔츠를 만드는 비용에 들어가지 않는다.
// 4. 그러므로 dif중 최대값을 경계값으로 사용하여야 티셔츠를 만드는 최소 비용을 구할수 있다.
// 5. 그 이후 답을 구하는 것은 대충 2가지 방법이 있는데 dif[]를 모두 더해서 가장 큰 dif[]값 K - 1개를 빼는 것이 있고,
// dif[]중 K - 1개를 제외한 나머지를 더하는 방법이 있으나, 후자가 더 처리해야할 연산이 적으므로 후자를 구현한다.

// 수학적 접근은 어려운 것도 아니고 아예 떠오르질 않아서 문제다. 늘 더 넓은 시야를 가지도록 노력하자.

// 자세한 설명은 주석으로 남긴다.

int board[300000], dif[300000];
int N, K;

void MakeAnswer()
{
    // 상술한 차이값 dif[]를 구한다.
    for (int i = 1; i < N; ++i)
        dif[i] = board[i] - board[i - 1];

    // 상술한 5번처럼 dif를 오름차순으로 정렬하여 가장 큰 K - 1개를 제외한 나머지를 더하여 출력한다.
    // 각 원생의 키가 최대 10억까지 도달하기에 int로는 그 합을 모두 더하기 어렵고 long long타입의 변수를
    // 사용하여야 한다.
    sort(dif, dif + N);
    long long answer = 0;
    for (int i = 0; i < N - K + 1; ++i)
        answer += dif[i];

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}