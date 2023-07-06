#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// dp문제인데 잠을 잘 못자서 그런지 BFS로 풀고 있었다.
// 풀이 자체는 전혀 어렵지 않다. 현재 2개의 위치 first와 second에서 각각 이동해야할 위치로 이동후 매번 이동수를 더해
// 최소값을 구해주면 된다. 다만 BFS로 풀었을때 틀린 점은 first는 무조건 second보다 왼쪽 영역, second는 무조건 first보다 오른쪽
// 영역에서만 움직이는데 이점이 틀린거 같다.

// 자세한 설명은 주석으로 남긴다.

int N, T, first, second;
int board[20];
int dp[21][21][20];

// 각 idx번째 위치로 first와 second를 모두 이동시켜보고 더 짧은쪽을 선택하는 함수.
int FindAnswer(int first, int second, int idx)
{
    if (idx == T)
        return 0;

    int& ans = dp[first][second][idx];
    if (ans != -1)
        return ans;

    // idx번째 위치로 first와 second를 모두 이동시켜보고 더 짧은쪽을 반환한다.
    ans = min(abs(board[idx] - first) + FindAnswer(board[idx], second, idx + 1),
        abs(board[idx] - second) + FindAnswer(first, board[idx], idx + 1));

    return ans;
}

void MakeAnswer()
{
    memset(dp, -1, sizeof(dp));
    int answer = FindAnswer(first, second, 0);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> first >> second >> T;
    for (int i = 0; i < T; ++i)
        cin >> board[i];

    if (first > second)
        swap(first, second);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}