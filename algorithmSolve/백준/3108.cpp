#include <iostream>
#include <vector>

using namespace std;

// 풀이. 
// 떠올린 아이디어는 좋았다. 순서대로 서술하자면

// 1. 0, 0을 0번째 직사각형으로 두어 for문을 사용해 최대 N번 순회하며 각 직사각형과의
// 연결 여부를 계산하여 벡터에 넣는다. 
// 2. 2중 for문을 통해서 최대 50만번의 순회끝에 각 직사각형의 연결 여부를 벡터에 넣는다.
// 3. for문을 이용한 N번의 순회를 통해 아직 방문하지 않은 직사각형에만 DFS를 호출한다.
// 이 때, DFS가 호출된 횟수가 바로 정답이 된다.

// 다만, 각 직사각형의 겹침 여부를 구상하는게 너무 힘들었다. 실제로는 엄청 간단했는데
// 그것은 이곳에 설명하기 복잡하니 후술하겠다.

// 자세한 설명은 주석으로 남긴다.

struct quad
{
    int x1;
    int y1;
    int x2;
    int y2;
};

int N;
quad board[1001];
vector<int> mov[1001];
bool visit[1001] = { false, };

bool CanMove(const quad& a, const quad& b)
{
    // 먼저 전혀 안 겹치는 경우.
    if (a.x2 < b.x1 || b.x2 < a.x1 || a.y2 < b.y1 || b.y2 < a.y1)
        return false;

    // 내부에서만 겹치는 경우 배제 (경계 안 닿는 경우)
    if (a.x1 < b.x1 && b.x2 < a.x2 && a.y1 < b.y1 && b.y2 < a.y2)
        return false;
    if (b.x1 < a.x1 && a.x2 < b.x2 && b.y1 < a.y1 && a.y2 < b.y2)
        return false;

    return true;
}

void DFS(int idx)
{
    visit[idx] = true;
    for (auto next : mov[idx])
    {
        if (!visit[next])
            DFS(next);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> board[i].x1 >> board[i].y1 >> board[i].x2 >> board[i].y2;

    for (int i = 1; i <= N; ++i)
    {
        if (((board[i].y1 == 0 || board[i].y2 == 0) && (board[i].x1 <= 0 && 0 <= board[i].x2)) ||
            ((board[i].x1 == 0 || board[i].x2 == 0) && (board[i].y1 <= 0 && 0 <= board[i].y2)))
            mov[0].push_back(i);
    }

    for (int i = 1; i < N; ++i)
    {
        for (int j = i + 1; j <= N; ++j)
        {
            if (CanMove(board[i], board[j]))
            {
                mov[i].push_back(j);
                mov[j].push_back(i);
            }
        }
    }

    int answer = -1;
    for (int i = 0; i <= N; ++i)
    {
        if (!visit[i])
        {
            ++answer;
            DFS(i);
        }
    }
    cout << answer << '\n';
    return 0;
}