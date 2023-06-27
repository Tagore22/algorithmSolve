#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

// 풀이.
// 처음 생각한 방법은 백트래킹이었다. 하지만 중복이 있었다. 예를 들어
// BBBBOOOOOO 일 경우, 첫번째 B에서 마지막 O로도 갈수 있고 두번째 B에서 마지막 O로도 갈수 있고
// 중복이 점점 쌓이게 되는 형식이었다. 그래서 DP를 써야했다.

// 처음에 풀때에는 BackTrack()에 sum이란 매개변수가 하나 더 있었다. 말그대로 현재까지 에너지의 총량을 
// 담아두는 변수였는데, 

// 1. 일단 첫째로 굳이 쓸필요가 없었다. 현재처럼 추가되는 부분을 + 로 묶어두고 나중에
// 끝에 도달했을때 0을 반환하면 매개변수 하나를 줄일수가 있기 때문이다.
// 2. 두번째로 답이 맞지 않았다. 마지막 예시에서 52가 아닌 68이 나왔다. 덧셈 부분에서 에러가 난건지
// 아니면 어딘가에서 한번 더 더해진건지를 잘 모르겠다.

// 어쨌든 이 방법은 종만북에서도 나왔었던만큼 중요한 부분이고 실제로 사용해봤을때에도 그러했다.
// 유의하도록 하자.

// 자세한 설명은 주석으로 남긴다.

char board[1000];
char block[3] = { 'B', 'O', 'J' };
int dp[1000];
int N;

// 모든 순회를 구현하는 함수. 상술하였듯 sum 매개변수도 있었으나 굳이 필요없어 삭제되었다.
int BackTrack(int idx, int cur_block)
{
    // 마지막에 도달했다면 더이상 움직일 필요가 없으니 0을 반환한다.
    if (idx == N - 1)
        return 0;

    int& ans = dp[idx];
    if (ans != -1)
        return ans;

    // N번째까지 도달자체가 불가능하다면 매우 큰 수를 반환하여 조건문에서 거를수 있다.
    ans = 987654321;

    int next = (cur_block + 1) % 3;
    char next_block = block[next];
    for (int i = idx + 1; i < N; ++i)
    {
        // 다음 번째 문자라면 도달할수 있다.
        if (board[i] == next_block)
        {
            int sum = pow(i - idx, 2);
            // 상술하였듯 총합을 매개변수로 두지 아니하고, 반환되는 값에 더해 구현할수 있다.
            ans = min(ans, BackTrack(i, next) + sum);
        }
    }

    return ans;
}

void MakeAnswer()
{
    memset(dp, -1, sizeof(dp));

    // 여기서 백트래킹 시작.
    int answer = BackTrack(0, 0);

    cout << (answer == 987654321 ? -1 : answer) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

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