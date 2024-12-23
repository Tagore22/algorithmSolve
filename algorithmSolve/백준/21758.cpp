#include <iostream>

using namespace std;

// 풀이.
// 척 보기에도 복잡해보여서 예전엔 지나갔던 문제다. 이번엔 조금더 신중하게 풀어보았다. 처음에는
// 모든 경우를 따져봐야하나 생각했다. 하지만 10만개중 3개를 고르는 경우는 10C3으로 너무 많았다.
// 최대값을 구하기 위해서는 다음과 같은 3가지 경우가 존재한다.

// 1. 벌집이 맨 왼쪽, 중앙 어딘가에 있으며 꿀통이 맨 오른쪽에 존재함.
// 2. 벌집이 맨 오른쪽, 중앙 어딘가에 있으며 꿀통이 맨 왼쪽에 존재함.
// 3. 벌집이 맨 오른쪽과 맨 왼쪽에 있으며 꿀통이 중앙 어딘가에 존재함.

// 왜냐하면 모든 수가 양수이며 최대값을 구해야 하기 때문에 가장 끝자락부터 그 합이 구해져야하기 때문이다.
// 따라서 위 3가지 경우를 구현하면 된다.

// 자세한 설명은 주석으로 남긴다.

int board[100000], sum_arr[100000];
int N, sum = 0;

void MakeAnswer()
{
    int answer = 0;
    // 벌집이 왼쪽, 중앙이고 벌통이 오른쪽
    int left = sum - board[0];
    for (int i = 1; i < N - 1; ++i)
    {
        int ans = left - board[i];
        ans += sum - sum_arr[i];
        answer = max(answer, ans);
    }
    // 벌집이 오른쪽, 중앙이고 벌통이 왼쪽
    int right = sum - board[N - 1];
    for (int i = N - 2; i >= 1; --i)
    {
        int ans = right - board[i];
        ans += sum_arr[i - 1];
        answer = max(answer, ans);
    }
    // 벌집이 양쪽, 벌통이 중앙
    for (int i = 1; i < N - 1; ++i)
    {
        int ans = sum - board[0] - board[N - 1] + board[i];
        answer = max(answer, ans);
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i];
        sum += board[i];
        sum_arr[i] = sum;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}