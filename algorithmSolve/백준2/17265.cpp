#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// 보통의 그래프 탐색에는 중복처리가 반드시 있어야 하나, 이번 문제에는
// 2가지 이유로 인해 그러지 않았다.

// 1. 중복처리가 필요없을만큼 격자가 작다.
// 2. 중복처리를 하기가 힘들다. 좌표도 아니고 문자열도 아니다.

// 따라서 그냥 무식하게 BFS를 돌며 계산식을 구하고 N - 1, N - 1에 도달하였을 때,
// 계산식을 구하여 기존의 최대, 최소값과 비교하면 된다.
// 자세한 설명은 주석으로 남긴다.

struct pos
{
    int y;
    int x;
    string str;
};

int N;
char board[5][5];
int rot[2][2] = { {0, 1}, {1, 0} };
pair<int, int> answer = make_pair(-2100000000, 2100000000);

void CheckMaximum(string str)
{
    // 어떻게 하면 깔끔하게 계산식의 답을 계산할까 고민하다가 이러한 방식이 나왔다.
    // 연산자의 수만큼만 순회를 하면 된다.
    int ans = str[0] - '0';
    for (int i = 1; i < str.size(); i += 2)
    {
        if (str[i] == '+')
            ans += str[i + 1] - '0';
        else if (str[i] == '-')
            ans -= str[i + 1] - '0';
        else
            ans *= str[i + 1] - '0';
    }
    answer.first = max(answer.first, ans);
    answer.second = min(answer.second, ans);
}

void BFS()
{
    queue<pos> que;
    string cur(1, board[0][0]);
    que.push(pos{ 0, 0, cur });

    while (!que.empty())
    {
        int y = que.front().y;
        int x = que.front().x;
        string str = que.front().str;
        que.pop();

        if (y == N - 1 && x == N - 1)
        {
            CheckMaximum(str);
            continue;
        }

        for (int i = 0; i < 2; ++i)
        {
            int ny = y + rot[i][0];
            int nx = x + rot[i][1];

            if (ny >= N || nx >= N)
                continue;

            que.push(pos{ ny, nx, str + board[ny][nx] });
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];

    BFS();
    cout << answer.first << ' ' << answer.second << '\n';
    return 0;
}