#include <iostream>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

// 풀이.
// BFS 혹은 DFS를 최대 100만번 실행해야하는 어려운 문제였다.
// 상술한대로 구현하면 무조건 시간초과가 나기에 다른 방법을 찾아야 한다.
// 기존에 생각했던 것은 미리 해당 좌표의 움직일수 있는 칸의 수를 저장해 놓고
// 주어진 배열을 순회하며 1인 칸에 도달하였을때 4방향의 칸의 수를 모두 더하는 것이었다.
// 하지만 이렇게 하니 예를 들어 왼쪽과 위쪽이 연결되어 있을때 더해지는 값이 중복되어
// 답이 맞지 않았었다. 이 부분에서 막혀 한참 해맸다.

// 답은 해당 칸의 움직일수 있는 칸을 넣지 않고 몇번째 0인지를 저장하는 것이었다.
// 예를 들어 주어진 문제의 2번 예시를 보면 처음 움직일수 있는 공간이 0, 2와 0, 3이다.
// 이 2칸에 모두 0을 저장하고 몇번째 공간이 몇칸 움직일수 있는지 저장하는 벡터를 하나 생성하여
// 그 벡터에 몇번째에 해당하는 원소에 몇칸을 움직일수 있는지를 저장하는 것이다.

// 다시 2번 예제를 예로 들면 0번째 움직일수 있는 공간인 0, 2와 0, 3은 2칸 움직일수 있다.
// 그렇기에 벡터[0] = 2이다. 그 다음 1번째 움직일수 있는 공간은 1, 0과 1, 1, 2, 0이다.
// 3칸 움직일수 있기에 벡터[1] = 3이다. 이렇게 저장하여 놓으면 된다.

// 그 후 최종답을 구할때에는 주어진 배열을 모두 순회하며 1인 좌표값을 찾아
// 그 좌표값의 4방향을 비교하는데 각 방향이 0일 경우 몇번째 공간인지를 찾아 보고
// 그 몇번째 공간이 이미 포함되어 있는지 set으로 검사한다.
// 만약 포함되어 있지 않다면 몇번째 공간의 칸수를 더하고 set에 몇번째의 n을 추가한다.

// 만약 포함되어 있다면 무시한다.

// 자세한 설명은 주석으로 남긴다.
// P.S 이 풀이는 DFS 풀이인데 역시나 DFS의 재귀횟수가 많기에 콜스택에 중첩된 메모리양이 점점 늘어서
// BFS의 용량을 훨씬 뛰어넘는 것을 알수 있었다. 다만 속도는 조금 더 빠른데 크게 차이가 없는지라
// 재귀횟수가 많다면 BFS로 풀것을 잊지말자.

int N, M, path;
int dp[1000][1000];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // 좌 상 우 하.
bool board[1000][1000], visit[1000][1000];
vector<int> dps;

// 몇번째 공간이 몇칸 움직일수 있는지 확인하는 DFS함수.
void DFS(int y, int x)
{
    visit[y][x] = true;
    // 몇칸 움직일수 있는지 계속 확인한다.
    ++path;
    // dp에는 몇번째 공간인지를 저장한다.
    dp[y][x] = dps.size();

    for (int i = 0; i < 4; ++i)
    {
        int dy = y + rot[i][0];
        int dx = x + rot[i][1];

        if (dy < 0 || dy >= N || dx < 0 || dx >= M || visit[dy][dx] || board[dy][dx])
            continue;

        DFS(dy, dx);
    }
}

void CalDPAll()
{
    memset(visit, false, sizeof(visit));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (!board[i][j] && !visit[i][j])
            {
                path = 0;
                DFS(i, j);
                // 몇번째 공간이 몇칸 움직일수 있는지 저장한다.
                dps.push_back(path);
            }
}

void MakeAnswer()
{
    CalDPAll();

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (board[i][j])
            {
                int answer = 1;
                set<int> check;
                for (int idx = 0; idx < 4; ++idx)
                {
                    int dy = i + rot[idx][0];
                    int dx = j + rot[idx][1];

                    if (dy < 0 || dy >= N || dx < 0 || dx >= M || board[dy][dx])
                        continue;

                    // 상술하였듯 몇번째 공간이 이미 포함되어 있는지 확인한다.
                    // 포함되어 있지 않다면 새로 포함시키고 답을 더하며
                    // 포함되어 있다면 무시한다.
                    int cur = dp[dy][dx];
                    if (check.find(cur) == check.end())
                    {
                        answer += dps[cur];
                        check.insert(cur);
                    }
                }
                cout << answer % 10;
            }
            else
            {
                cout << 0;
            }
        }
        cout << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        for (int j = 0; j < M; ++j)
            board[i][j] = str[j] - '0';
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}