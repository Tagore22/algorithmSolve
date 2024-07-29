#include <iostream>

using namespace std;

// 풀이.
// 어려운 문제는 아니었으나 크나큰 실수 하나 때문에 근 1시간정도 헤맨 문제다.
// 후... 그래도 정답율도 낮은데 잘 풀었으니 넘어가자.
// 언젠가 많이 풀어봤던 양식의 문제다. 설명하기가 까다로우니 주석으로 남긴다.

// 자세한 설명은 주석으로 남긴다.

// P.S 기존과는 달리 2중 for문에서 str[0]과 비교하여 가지치기를 하니 속도가 더 빨라졌다.

int N, M, K;
char board[105][105];
int dp[105][105][85];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
string str;
int answer = 0;

// 1. 모든 칸을 순회하며 시작 단어가 나타날시 DFS 시작.
// 2. 각 칸을 DFS 순회시작 할때 다음 단어가 나타날시 순회 시작.

// y, x에서 idx번째 문자를 찾는 순회 함수.
int DFS(int y, int x, int idx)
{
    // 만약 현재 위치와 idx번째가 이미 계산되어있다면 그 계산값을 반환하고 탈출한다.
    int& ans = dp[y][x][idx];
    if (ans != -1)
        return ans;

    // 마지막까지 도달하였다면 1가지 방법을 찾았음을 1을 반환하여 뜻한다.
    if (idx == str.size() - 1)
        return 1;

    ans = 0;

    // 여기서 많이 실수했다. 아니 못봤다고 해야하나. 이해를 잘못했다고 해야하나.
    // 한번에 무조건 K만큼 이동해야하는 것이 아닌 최대 1 ~ K만큼의 이동이 가능한 것이었다.
    for (int i = 0; i < 4; ++i)
        // 이동 범위를 1 ~ K로 늘린다.
        for (int j = 1; j <= K; ++j)
        {
            // 그리고 여기서 또 실수를 했다. 증가한 범위 j를 곱해야하지만 K를 곱했었다... ㅠㅠ
            int ny = y + rot[i][0] * j;
            int nx = x + rot[i][1] * j;

            // 배열값을 벗어나거나 도달한곳이 idx + 1번째 문자가 아니라면 무시한다.
            if (ny < 0 || ny >= N || nx < 0 || nx >= M || board[ny][nx] != str[idx + 1])
                continue;

            ans += DFS(ny, nx, idx + 1);
        }
    return ans;
}

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            for (int z = 0; z < str.size(); ++z)
                dp[i][j][z] = -1;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            // i, j번째 값이 str[0]과 같다면 DFS순회를 한다.
            if (board[i][j] == str[0])
                answer += DFS(i, j, 0);

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i)
    {
        string cur;
        cin >> cur;
        for (int j = 0; j < M; ++j)
            board[i][j] = cur[j];
    }
    cin >> str;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}