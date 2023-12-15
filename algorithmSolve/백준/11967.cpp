#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

// 풀이.
// 정답율이 증명하듯 어려운 문제였다. 상하좌우에 불이 켜진 방으로만 이동이 가능하며
// 각 방에는 다른 방의 불을 킬수 있는 스위치가 존재할수도 있다. 이때 불을 킬수 있는 최대 개수를 출력해야한다.
// 결과적으로는 불이 켜진 방들의 목록을 deque를 이용하여 저장하고 있으면서 새로이 불이 켜진 방을 추가하고
// deque을 순회하며 불은 켜졌으나 아직 방문하지 못한 방들중 새롭게 방문이 가능해진 방을 제거해나가며
// BFS를 순회했다. 하지만 이것보다 더 빠른 방법이 있었다.

// 자세한 설명은 주석으로 남긴다.

vector<pair<int, int>> board[101][101];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // 왼쪽, 위쪽, 오른쪽, 아래쪽.
int N, M;

int BFS()
{
    queue<pair<int, int>> que;
    que.push(make_pair(1, 1));
    // 각 방들이 방문했는지에 대한 배열.
    vector<vector<bool>> visit(N + 1, vector<bool>(N + 1, false));
    // 각 방들이 불이 켜졌는지에 대한 배열.
    vector<vector<bool>> isLight(N + 1, vector<bool>(N + 1, false));
    visit[1][1] = true;
    isLight[1][1] = true;
    int ans = 1;
    deque<pair<int, int>> deq;

    while (!que.empty())
    {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();

        // 현재 방에서 불을 킬수 있는 모든 방들을 순회한다.
        for (auto next : board[y][x])
        {
            // 현재 불이 켜지지 않은 방이라면
            if (!isLight[next.first][next.second])
            {
                // 불을 키고 최종답 ans를 증가시킨다.
                isLight[next.first][next.second] = true;
                ++ans;
                // 또한 불은 켜졌으나 아직 방문하지 않은 방들에 목록에 추가한다.
                deq.push_back(next);
            }
        }

        // deque은 원소가 추가되거나 삭제될시 기존의 반복자들이 모두 무효화되기 때문에
        // 반복자를 이용하지 않고 횟수를 이용하여야 했다.
        int idx = deq.size();
        // 현재 모든 원소들을 순회한다.
        for (int iter = 0; iter < idx; ++iter)
        {
            int i = deq.front().first;
            int j = deq.front().second;
            deq.pop_front();

            bool isFind = false;
            // 현재 위치에서 4방향을 순회한다.
            for (int k = 0; k < 4; ++k)
            {
                int di = i + rot[k][0];
                int dj = j + rot[k][1];

                // 배열값을 벗어났거나 방문하지 못한 곳이라면 무시한다.
                if (di <= 0 || di > N || dj <= 0 || dj > N || !visit[di][dj])
                    continue;

                // 방문한 곳이 한곳이라도 있다면 바로 옆칸인 현재 위치도 이동이 가능해진다.
                // 방문함을 갱신하고 queue에 추가해준다.
                visit[i][j] = true;
                que.push(make_pair(i, j));
                isFind = true;
                break;
            }

            // 방문하지 못한다면 다시 deque에 추가한다.
            if (!isFind)
                deq.push_back(make_pair(i, j));
        }
    }
    return ans;
}

void MakeAnswer()
{
    int answer = BFS();
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    pair<int, int> from, to;
    for (int i = 0; i < M; ++i)
    {
        cin >> from.first >> from.second >> to.first >> to.second;
        board[from.first][from.second].push_back(to);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}