#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// 오랜만에 돌아온 BFS문제다. 최소값을 구해야하기 때문에 거의 무조건 BFS였다. 다만 여러가지 제약이 존재했다.

// 1. 벽이 존재하는 경우 K가 0이 아니면 벽을 뚫을수 있음.
// 2. 벽은 오직 낮에만 뚫을수 있음.

// 따라서 이 모든 제약을 통과하는 최소값을 구해야 한다. 꽤나 까다로운 문제였기에 정답율이 23프로밖에 안된다.
// 그래도 이겨냈기에 매우 뿌듯하다.

// 자세한 설명은 주석으로 남긴다.

struct point
{
    int y;
    int x;
    int k;
};

int N, M, K;
bool board[1001][1001];
int rot[4][2] = { {0, -1}, {-1, 0}, {1, 0}, {0, 1} };

// 모든 경우를 순회하는 함수.
void BFS()
{
    queue<point> que;
    que.push(point{ 1, 1, K });
    // 이 부분이 중요했다. 같은 위치에 도달해도 k값에 의해 경우가 나뉘었다. 처음에는 bool타입의 3차원 배열을 생각하였으나
    // 메모리를 너무 잡아먹었다. 따라서 조금 그리디한 접근으로 k값이 크다면 무조건 더 빠르게 목표에 도달할수 있기 때문에
    // char 배열로 각 위치의 최대값의 k값을 저장하는 식으로 구현하였다. int로 해도 상관은 없으나 k값이 최대 10밖에 안되기
    // 때문에 char로 하여도 충분하다. 또한 0으로 하면 후술하는 조건에 의해 답이 제대로 안나올 가능성도 존재했기에 -1로 
    // 초기화하였다.
    char check[1001][1001];
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            check[i][j] = -1;
    check[1][1] = K;
    int answer = 0;

    while (!que.empty())
    {
        // 이 부분도 오랜만에 구현하는 방식이었는데 현재 가지고 있는 위치에서 1씩 나아가야 했다.
        // 따라서 추가로 얻은 위치들은 무시하고 현재 순회전 가지고 있는 위치들에서만 나아가야 한다.
        ++answer;
        int qsize = que.size();
        for (int iter = 0; iter < qsize; ++iter)
        {
            int y = que.front().y;
            int x = que.front().x;
            int k = que.front().k;
            que.pop();

            if (y == N && x == M)
            {
                cout << answer << '\n';
                return;
            }
            // 밤이라서 벽을 뚫지 못해 기다릴때를 생각해볼것.
            // 앞이 벽일때
            // 1. k가 0이라면 아예 못감
            // 2. k가 0이 아닐때
            // 2-1. 밤이 아니라면 뚫고 감.
            // 2-2. 밤이라면 현재 위치를 다시 한번 que에 넣음.
            for (int i = 0; i < 4; ++i)
            {
                int ny = y + rot[i][0];
                int nx = x + rot[i][1];

                // 걸러내는 조건은 다음과 같다.

                // 1. 배열값을 벗어났음.
                // 2. 더 많은 k값을 가진채로 이전에 방문한적이 있음.
                // 3. 현재 k가 0인데 도달하고자 하는 곳이 벽임.

                if (ny <= 0 || ny > N || nx <= 0 || nx > M || check[ny][nx] >= k ||
                    (!board[ny][nx] && k <= 0))
                    continue;

                // 도달하고자 하는 곳이 벽일때
                if (!board[ny][nx])
                {
                    // 현재 낮이라면 뚫고 넘어간다.
                    if (answer % 2 != 0)
                    {
                        que.push(point{ ny, nx, k - 1 });
                        check[ny][nx] = k - 1;
                    }
                    // 밤이라면 한번 대기한다.
                    else
                    {
                        que.push(point{ y, x, k });
                    }
                }
                // 벽이 아니라면 그냥 나아간다.
                else
                {
                    que.push(point{ ny, nx, k });
                    check[ny][nx] = k;
                }
            }
        }
    }
    // 여기를 놓쳐서 몇번 틀렸는데 기존에는 answer의 초기값이 -1이었다.
    // 따라서 모든 que의 값들을 순회하고도 답을 찾지못하면 answer를 그대로 출력해도 상관없으나
    // 1, 1에서 시작할때 answer의 값이 1이여야 하기에 이제는 답을 찾지 못하면 answer가 아닌 -1을 그대로
    // 출력해야한다.
    cout << -1 << '\n';
}

void MakeAnswer()
{
    BFS();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;
    string str;
    for (int i = 1; i <= N; ++i)
    {
        cin >> str;
        for (int j = 1; j <= M; ++j)
        {
            if (str[j - 1] == '0')
                board[i][j] = true;
            else
                board[i][j] = false;
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}