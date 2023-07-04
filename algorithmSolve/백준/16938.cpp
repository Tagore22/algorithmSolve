#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 사소한곳을 체크하지 못해 한번에 푼 문제다.
// 문제를 읽어보면 백트래킹 문제임에 틀림없다. 다만 dp를 사용해야 하는가 하면 그건 또 아닌데
// 앞의 값에 따라 그 현재 값이 변하기 때문이다. 그렇기 때문에 모든 경우의 수를 백트래킹으로 구해서
// 조건에 해당하는 경우를 다시 추려내면 된다.

// 비트마스크로도 풀수는 있으나 이러한 방법으로도 풀수 있다.

// 자세한 설명은 주석으로 남긴다.

int board[15];
int N, L, R, X, answer;

// 모든 경우의 수를 순회하는 백트래킹 함수.
void BackTrack(int idx, int sum, int min_num, int max_num)
{
    // 현재 조건에 충족한다면 답을 1 증가시킨다.
    if (L <= sum && sum <= R && X <= max_num - min_num)
    {
        // 여기 주석친 부분이 잘못되었다. 현재 조건에 충족하여 답이 1 증가한후 다음번 원소를 고를수도 있기에
        // 그냥 탈출하면 안된다.
        ++answer;
        //return;
    }

    // 중복을 피하기 위해 현재 원소 이후부터 마지막까지 순회하며 조건에 충족하는(난이도의 총합이 R보다 작거나 같아야한다.)
    // 원소를 만날경우 재귀를 호출한다.
    for (int i = idx + 1; i < N; ++i)
    {
        if (sum + board[i] <= R)
        {
            int next_sum = sum + board[i];
            int next_min = min(min_num, board[i]);
            int next_max = max(max_num, board[i]);
            BackTrack(i, next_sum, next_min, next_max);
        }
    }
}

void MakeAnswer()
{
    answer = 0;
    BackTrack(-1, 0, 987654321, 0);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> L >> R >> X;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}