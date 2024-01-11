#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

// 풀이.
// 문제 자체는 어려운 문제가 아니다. 5개의 판을 랜덤하게 쌓고 각 판을 시계방향으로 회전이 가능할때
// {0, 0, 0}에서 {4, 4, 4}로 도달가능한 최소한의 이동횟수를 출력하면 된다.
// 다만 구현하는 것은 굉장히 복잡하다. 5개의 판을 랜덤하게 쌓기, 각 판을 회전하는 경우, 그 경우에 BFS 순회를 하는 경우를
// 모두 구현해야한다. 여기까진 그래도 했으나 속도가 너무 느려서 찾아보니 3가지가 문제였다.

// 1. 가지치기
// 2. 당연하지만 벡터보다 일반 배열이 더 빠름. 다만 크게 차이는 나지 않지만 이번의 경우 벡터나 배열을 매우 빈번하게 사용하므로 그 차이가
// 벌어진듯 하다.
// 3. 큐의 무분별한 재생성. 재생성보다 clear()로 비우는게 더 빠르다.

// 문제 자체도 모호한 문제였다. 참가자가 임의로 선택한 꼭지점이 시작점이랬는데 그럼 내가 랜덤하게 고르는게 아닌가?
// 하지만 실제로는 0, 0, 0과 4, 4, 4로 시작점과 끝점이 정해져있었다. 또한 인접한 곳으로 이동이 가능하다고 해서
// 나는 대각선까지 생각했는데 막상보니 대각선은 제외였다. 이게 왜 55퍼센트짜리 문제인가?

// 자세한 설명은 주석으로 남긴다.

int board[5][5][5], cube[5][5][5];
vector<int> seq;
// 본디 BFS 순회시 덱이 아닌 큐를 쓰지만 큐의 무분별한 재생성을 막기위해 덱을 사용.
// 큐는 clear()가 없기 때문이다.
deque<pair<int, pair<int, int>>> que;
// 알고보니 대각선은 예외였다.
int rot[6][3] = { {0, 0, -1}, {0, -1, 0}, {0, 0, 1}, {0, 1, 0}, {1, 0, 0}, {-1, 0, 0} };
bool visit[5][5][5];
int answer = 987654321;

// BFS 순회 함수.
void BFS()
{
    // 기존의 덱을 비운다.
    que.clear();
    que.push_back(make_pair(0, make_pair(0, 0)));
    // 방문 여부의 갱신.
    memset(visit, false, sizeof(visit));
    visit[0][0][0] = true;
    int cost = -1;

    while (!que.empty())
    {
        int qsize = que.size();
        ++cost;
        for (int iter = 0; iter < qsize; ++iter)
        {
            int z = que.front().first;
            int y = que.front().second.first;
            int x = que.front().second.second;
            que.pop_front();

            // 끝점에 도달했을시 이동횟수를 갱신해본다.
            if (z == 4 && y == 4 && x == 4)
            {
                answer = min(answer, cost);
                return;
            }

            for (int i = 0; i < 6; ++i)
            {
                int dz = z + rot[i][0];
                int dy = y + rot[i][1];
                int dx = x + rot[i][2];

                if (dz < 0 || dz >= 5 || dy < 0 || dy >= 5 || dx < 0 || dx >= 5 ||
                    visit[dz][dy][dx] || cube[dz][dy][dx] == 0)
                    continue;

                visit[dz][dy][dx] = true;
                que.push_back(make_pair(dz, make_pair(dy, dx)));
            }
        }
    }
}

// idx번째 판을 시계방향으로 회전하는 함수.
void RotationCube(int idx)
{
    int plus = 4;
    // 벡터보다 배열이 빠르다.
    int temp[5][5];
    for (int j = 0; j < 5; ++j)
    {
        for (int i = 0; i < 5; ++i)
            temp[i][j] = cube[idx][j + plus][i];
        plus -= 2;
    }
    // 회전시킨 대체 판을 실제 판으로 변경.
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            cube[idx][i][j] = temp[i][j];
}

// 모든 판의 회전을 구현하는 함수.
void RotationCubeAll()
{
    for (int a = 0; a < 4; ++a)
    {
        RotationCube(0);
        // 회전시켰을시 입구가 막혔다면 무시한다.
        if (cube[0][0][0] == 0)
            continue;
        for (int b = 0; b < 4; ++b)
        {
            RotationCube(1);
            for (int c = 0; c < 4; ++c)
            {
                RotationCube(2);
                for (int d = 0; d < 4; ++d)
                {
                    RotationCube(3);
                    for (int e = 0; e < 4; ++e)
                    {
                        RotationCube(4);
                        // 끝점이 막혀있지 않다면 BFS 순회를 해본다.
                        if (cube[4][4][4] == 1)
                            BFS();
                        // 5x5x5의 최소값은 12이다. 그렇기에 현재값이 12가 되었다면
                        // 출력하고 탈출한다. 상술한 3가지 문제중 1번.
                        if (answer == 12)
                        {
                            cout << answer << '\n';
                            exit(0);
                        }
                    }
                }
            }
        }
    }
}

void MakeAnswer()
{
    for (int i = 0; i < 5; ++i)
        seq.push_back(i);
    while (true)
    {
        // 모든 판을 순서대로 쌓는다.
        for (int i = 0; i < 5; ++i)
            for (int j = 0; j < 5; ++j)
                for (int k = 0; k < 5; ++k)
                    cube[i][j][k] = board[seq[i]][j][k];
        // 모든 판을 회전시켜본다.
        RotationCubeAll();
        // 더이상 순서대로 쌓을수 없다면 탈출한다.
        if (!next_permutation(seq.begin(), seq.end()))
            break;
    }
    cout << (answer != 987654321 ? answer : -1) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            for (int k = 0; k < 5; ++k)
                cin >> board[i][j][k];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}