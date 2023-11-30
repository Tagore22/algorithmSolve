#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 정답율이 30퍼센트가 안되는만큼 쉽지 않은 문제였다.
// 문제 자체는 최대 100개의 칸중에서 인접하지 않는 최대 4개의 칸을 고를때 그 최대값을 출력하는 간단한 문제다.
// 이 풀이에서는 매번 이전 칸 이후로 순회하며 다음 칸이 여태까지 고른 칸들에 인접하지 않는다면 골라가면서
// K개를 골랐을때 그 최대값을 출력하였다. 하지만 다른 더 좋은 풀이가 존재했다. 너무 어려운 방식으로 접근한것 같다.

// 자세한 설명은 주석으로 남긴다.

vector<pair<int, int>> points;
int board[10][10];
int N, M, K;

// 다음칸 y, x가 여태까지 고른 칸들에 인접하는지 확인하는 함수.
bool CheckPoints(int y, int x)
{
    for (int i = 0; i < points.size(); ++i)
    {
        if ((points[i].first == y + 1 && points[i].second == x) || (points[i].first == y - 1 && points[i].second == x) ||
            (points[i].first == y && points[i].second == x + 1) || (points[i].first == y && points[i].second == x - 1))
            return false;
    }
    return true;
}

// 모든 순회를 구현하는 함수.
int DFS(int y, int x, int num)
{
    // 1개가 남았다면 여태까지 고른 칸들의 값들을 모두 더하고 현재 칸의 값을 추가로 더해 반환한다.
    if (num == 1)
    {
        int ans = 0;
        for (int i = 0; i < points.size(); ++i)
            ans += board[points[i].first][points[i].second];

        return ans + board[y][x];
    }

    // 현재 칸을 저장한다.
    points.push_back(make_pair(y, x));
    int ans = -49999;
    // 이전 칸은 이미 골랐으므로 또 고를 필요 없이 1칸 오른쪽에서 시작한다.
    int from = x + 1;
    for (int i = y; i < N; ++i)
    {
        for (int j = from; j < M; ++j)
        {
            // 다음 칸 i, j가 여태까지 고른 칸들과 인접하지 않는다면 선택한다.
            if (!CheckPoints(i, j))
                continue;

            ans = max(ans, DFS(i, j, num - 1));
        }
        // 이미 한줄을 순회했다면 처음부터 순회해야 하기에 from은 0이 된다.
        from = 0;
    }
    // 현재 저장한 칸 제거.
    points.pop_back();
    return ans;
}

void MakeAnswer()
{
    int answer = -50000;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            answer = max(answer, DFS(i, j, K));

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}