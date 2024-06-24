#include <iostream>

using namespace std;

// 풀이.
// 정말 어렵게 푼 문제다. 거의 7시간 넘게 걸린거 같다. 하... T^T
// 뭐 여러가지 실수가 거의 난발을 한 정도였는데 하나하나 나열해보자면

// 1. 처음에는 DP가 잘못 순회되고 있는줄 알았다. 그런게 아니라 재귀 이후 값의 반환이 잘못되었었다.
// 이로 인해 아예 방향을 잘못잡았고 방향조차 잘못잡았으니 시간이 지나도 갈피를 못잡았다.
// 2. 각 기업에 투자한 값들을 찾아내지 못했다.

// 그래서 엄청 오래 걸렸다. 아니면 아침에 피곤한게 여기까지 스노우볼이 구른건지. 자나깨나 수면 관리하자.
// 너무 부정적으로 생각하지 말자. 정답율 40퍼센트도 안된다.

// 자세한 설명은 주석으로 남긴다.

int board[301][20] = { 0, }, dp[301][20], cost[301][20];
int N, M, answer = 0;

// 모든 경우를 따져보는 함수.
int BackTrack(int money, int idx)
{
    if (idx == M)
    {
        return 0;
    }

    int& ans = dp[money][idx];
    if (ans != -1)
        return ans;
    ans = 0;

    for (int i = 0; i <= money; ++i)
    {
        int cur = BackTrack(money - i, idx + 1) + board[i][idx];
        // 평소라면 그냥 max()로 최대값을 구하고 말테지만 여기서는 각 기업에 투자한 금액을 찾기위해
        // if문이 따로 필요했다.
        if (cur > ans)
        {
            ans = cur;
            // 이 부분이 나에게 있어 엄청 중요했다. 재귀 호출에 대한 스트레스로 인해 전혀 발상 자체를 못했다.
            // 설명하자면 dp와 비슷하게 idx번째 기업에 대해 투자할때 금액을 money만큼 가지고 있을때 투자한 금액이다.
            cost[money][idx] = i;
        }
    }
    return ans;
}

void MakeAnswer()
{
    for (int i = 0; i <= N; ++i)
        for (int j = 0; j < M; ++j)
            dp[i][j] = -1;
    // 여기서 최대값은 이미 구할수 있다.
    cout << BackTrack(N, 0) << '\n';
    for (int i = 0; i < M; ++i)
    {
        // 위 상술한 중요한 부분. cost[N][i]가 말 그대로 i번째 기업에 투자한 금액 그 자체이므로 이것을 출력하고
        // 최종 금액 N에서 이 부분을 제외하면 그다음 금액이 나온다. 이것을 다시 재사용한다.
        cout << cost[N][i] << ' ';
        N -= cost[N][i];
    }
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    int num;
    for (int i = 1; i <= N; ++i)
    {
        cin >> num;
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}