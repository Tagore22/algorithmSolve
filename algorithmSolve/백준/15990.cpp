#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 주어지는 수 N을 연속되지 않은 상태에서 1, 2, 3의 합으로 표현하는 경우의 수를 출력하면 된다.
// 완전탐색과 DP를 이용하여 구현하면 된다.

// 자세한 설명은 주석으로 남긴다.

const int DIV = 1000000009;
int board[100001][4];
int T;

// 모든 완전탐색을 구현하는 함수.
int DFS(int num, int prev)
{
    // 현재 수 num이 2보다 작을때 이전값과 현재값이 같다면 0을, 다르다면 1을 반환한다.
    if (num <= 2)
        return prev == num ? 0 : 1;

    int& ans = board[num][prev];
    if (ans != -1)
        return ans;
    ans = 0;

    // 1, 2, 3 모든 경우를 대입해본다.
    for (int i = 1; i <= 3; ++i)
    {
        // 이전값과 현재값이 같거나 num에서 현재값을 뺏을때 0보다 작다면 무시한다.
        if (i == prev || num - i < 0)
            continue;

        ans += DFS(num - i, i);
        ans %= DIV;
    }
    return ans;
}

void MakeAnswer()
{
    int num;
    memset(board, -1, sizeof(board));
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> num;

        int answer = DFS(num, 0);
        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}