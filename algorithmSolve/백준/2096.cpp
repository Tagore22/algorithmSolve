#include <iostream>

using namespace std;

// 풀이.
// DP의 변화된 슬라이딩 윈도우 문제인데 직접 푸는건 거의 처음인것 같다.
// 전개방식이 기존 DP와는 조금 달라서 색달랐던것 같다.

// 근데 지금 생각해보면 굳이 이렇게 번거롭게 풀지 않아도 어차피 아래, 오른쪽 아래, 왼쪽 아래
// 이렇게 세군데밖에 내려가지 못하기 때문에 그냥 for문으로 진행할수 있는 곳의 최대 최소를 골라서 출력해도 될듯하다.

// P.S 용량에 대해서 생각해보았는데 기존에 메모리 초과 풀이 방식에도 대략 90만개의 int 변수가 있었는데
// 이것은 대략 3.6메가바이트에 달한다. 그러면 단순 변수 이외의 기본적인 메모리가 있다는 것인데
// 확인결과 이 기본적인 메모리는 2메가 정도이다. 현재 이 풀이에도 대략 30만개의 int 변수가 존재하는데
// 이것은 120만 바이트 즉, 1.2메가 정도이고 최종 메모리가 3.2메가 정도였으니 얼추 맞는다.

// 정리하자면 기본적으로 2메가는 잡고 시작한다. 잊지말자.

int board[100000][3];
pair<int, int> dp[2][3]; // 최대, 최소.
int N;

pair<int, int> DP(int y, int x)
{
    // 기존처럼 -1이 아니면 출력하지 않고 매번 초기화해주어야 한다.
    pair<int, int>& ans = dp[y % 2][x];
    ans = make_pair(-1, 987654321);

    pair<int, int> next = dp[(y + 1) % 2][x];
    ans = make_pair(max(ans.first, board[y][x] + next.first), min(ans.second, board[y][x] + next.second));

    if (x - 1 >= 0)
    {
        next = dp[(y + 1) % 2][x - 1];
        ans = make_pair(max(ans.first, board[y][x] + next.first), min(ans.second, board[y][x] + next.second));
    }

    if (x + 1 < 3)
    {
        next = dp[(y + 1) % 2][x + 1];
        ans = make_pair(max(ans.first, board[y][x] + next.first), min(ans.second, board[y][x] + next.second));
    }

    return ans;
}

void MakeAnswer()
{
    for (int i = 0; i < 3; ++i)
        dp[(N - 1) % 2][i] = make_pair(board[N - 1][i], board[N - 1][i]);

    // 기존처럼 알아서 내려가지 않고 매 행, 매 열마다 호출해주어야 한다.
    for (int i = N - 2; i >= 0; --i)
        for (int j = 0; j < 3; ++j)
            DP(i, j);

    pair<int, int> answer = make_pair(-1, 987654321);
    for (int i = 0; i < 3; ++i)
        answer = make_pair(max(answer.first, dp[0][i].first), min(answer.second, dp[0][i].second));

    cout << answer.first << ' ' << answer.second << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}