#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이.
// 언젠간 풀었던 BFS 스폐셜 저지의 DFS 버전이다.
// 큰 개념은 동일하다. 주어진 순서대로 각 정점의 순서들을 정렬한후 실제로 DFS순회를 하며
// 순서를 비교해본다.

// 자세한 설명은 주석으로 남긴다.

vector<vector<int>> board;
vector<bool> visit;
int compare[100001];
int N, idx = 1;
bool isEnd = false;

// 두 정점의 우선순위를 비교하는 함수.
bool CompareFunc(int lhs, int rhs)
{
    return compare[lhs] < compare[rhs];
}

// DFS 순회 함수.
void DFS(int here)
{
    if (isEnd)
        return;
    if (visit[here])
        return;
    visit[here] = true;

    for (auto there : board[here])
    {
        if (!visit[there])
        {
            // 현재 방문하려는 정점과 실제 주어진 정점을 비교해본다.
            // 만약 다르다면 isEnd가 true가 되어 모든 DFS를 탈출한다. 
            if (compare[there] != idx)
            {
                isEnd = true;
                return;
            }
            ++idx;
            DFS(there);
        }
    }
}

void MakeAnswer()
{
    if (compare[1] != 0)
    {
        cout << 0 << '\n';
        return;
    }
    // 모든 정점들을 주어진 순서에 의해 정렬한다.
    for (int i = 1; i <= N; ++i)
        sort(board[i].begin(), board[i].end(), CompareFunc);
    DFS(1);
    // isEnd에 의해 성공과 실패가 나뉜다.
    cout << (!isEnd ? 1 : 0) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    board.resize(N + 1, vector<int>());
    visit.resize(N + 1, false);
    int from, to;
    for (int i = 0; i < N - 1; ++i)
    {
        cin >> from >> to;
        board[from].push_back(to);
        board[to].push_back(from);
    }
    int num;
    for (int i = 0; i < N; ++i)
    {
        cin >> num;
        compare[num] = i;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}