#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// 풀이.
// 주어진 등수들을 기준으로 오름차순으로 정렬하여 실제 등수와 비교한다.
// 그 차이값들을 모두 더하여 출력하면 된다. 한가지 간과한 부분이 있는데
// 최대 등수는 50만으로 모든 인원들이 자신의 예상 점수를 50만으로 적어 낸다면
// 인원이 총 50만명일때 0 ~ 499999를 더해야해서 int값을 벗어난다.
// 따라서 최종값 answer의 타입은 long long 이여야 한다.

// 자세한 설명은 주석으로 남긴다.

int board[500001];
int N;

void MakeAnswer()
{
    // 차이값을 최소한으로 하기 위해 예상 점수를 기준으로 오름차순 정렬.
    sort(board, board + N);
    // 상술한대로 최종값 answer의 타입은 long long 이여야 한다.
    long long answer = 0;
    // 차이값을 모두 더해 출력한다.
    for (int i = 0; i < N; ++i)
        answer += abs(i - board[i] + 1);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}