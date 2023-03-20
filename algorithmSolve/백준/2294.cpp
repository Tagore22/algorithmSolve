#include <iostream>

using namespace std;

// 풀이.
// 평범한 DP문제다. 동전의 금액과 총 금액이 주어질때 해당 금액을 만들수 있는 동전수의 최소값을 구하면 된다.
// 각 동전의 금액은 무조건 1개가 최소값이므로 1로 초기화를 하고 나머지는 MAX_NUM으로 초기화를 한다.
// 그후 1부터 K까지 증가하며 현재 금액에서 사용할수 있는 동전들을 비교하여 동전수의 최소값을 갱신한다.

int coin[100], answer[10001];
int N, K;
const int MAX_NUM = 987654321;

void MakeAnswer()
{
    // 모든 금액의 초기값은 최대값.
    for (int i = 0; i <= K; ++i)
        answer[i] = MAX_NUM;

    // 각 동전의 금액은 말 그대로 하나의 동전으로 구할수 있기에 1로 초기화한다.
    for (int i = 0; i < N; ++i)
        if (coin[i] <= K)
            answer[coin[i]] = 1;

    // 1부터 K까지 순회하며 동전수를 비교한다. 0보다 커야하는 이유는 차이가 0일때에는 굳이 갱신할 필요가 없기에
    // 성능만 잡아먹는다.
    for (int i = 1; i <= K; ++i)
        for (int j = 0; j < N; ++j)
            if (i - coin[j] > 0)
                answer[i] = min(answer[i - coin[j]] + 1, answer[i]);

    cout << (answer[K] != MAX_NUM ? answer[K] : -1) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
        cin >> coin[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}