#include <iostream>
#include <queue>

using namespace std;

// 16235번의 더 빠른 풀이.

// 다른 풀이를 보고 잠을 자는 내내 의아했던 것은 다음과 같았다.

// 1. for문 이전에 if문을 추가함으로써 더 빨라지는가?
// 2. 3차원 deque에 접근할때 참조자를 이용하여 마지막 1차원을 순회할시 1차원 deque에 참조하여 순회하면 더 빠른가?

// 각각 직접 겪어본 바로는

// 1. 그다지 차이가 없다. 애시당초에 for문에도 조건문이 포함되어있기에 더 빠를리가 없다고 생각했는데 역시나였다.
// 2. 훨씬더 빨랐다. 어차피 랜덤 액세스를 지원하기에 그다지 차이가 없을줄 알았으나 생각해보면 랜덤 액세스 자체가 
// 어느정도 성능을 잡아먹는데 3차원이기에 더욱더 잡아먹었던것 같다. 1차원 duque를 참조하여 사용하는 새로운 기술(?)을 터득하여
// 기분이 좋다.

// 그 외.
// 이 문제는 새로운 나무를 뒤에서 넣을수도, 앞으로 넣을수도 있는데 나는 뒤에서 넣어서 죽은 나무들을 없앨때 52줄에 나온것처럼
// deque.front를 사용했다. 그런데 앞으로 넣으면 삭제할 순서와 순회의 순서를 맞출수 있어서 back이 아닌 랜덤액세스를 사용한
// [idx]가 가능하다. 직접 구현해보았으나 차이가 없었다.

// 기존에 4계절을 나눈것과 이번처럼 합친것의 차이도 그다지 없었다. 애시당초 순회안의 순회처럼 곱하기가 아닌 순회와 순회 같은
// 덧셈으로 연산량이 늘어나기에 그런듯 싶다. 또한 기존에 참조자를 사용하지 않고 합쳤을때 시간초과가 났는데 아무래도 다음 예시와 같은것 같다.
// 봄 연산 400, 여름 연산 400 일 경우 합쳐서 하면 순간적으로 800번의 연산량이다. 이 순간적으로 늘어나는 연산량이 시간초과의 원인같다.

// 가장 중요한건 참조자를 이용한 다차원 배열의 접근 방식이 성능을 눈에 띄게 끌어올린다는 점이다. 잊지 말자.

int board[10][10], provide[10][10];
int rot[8][2] = { {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1} }; //좌부터 시계방향으로 8방향.
deque<deque<deque<int>>> trees; // 생존 여부, 나이.
int N, M, K; // 배열의 크기, 나무의 수, 몇년 후인지.

void Spring_Summer()
{
    int deadline;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            deadline = -1;
            deque<int>& cur = trees[i][j];
            for (int iter = cur.size() - 1; iter >= 0; --iter)
            {
                if (board[i][j] < cur[iter])
                {
                    deadline = iter;
                    break;
                }
                else
                {
                    board[i][j] -= cur[iter];
                    ++cur[iter];
                }
            }

            for (int iter = 0; iter <= deadline; ++iter)
            {
                board[i][j] += cur.front() / 2;
                cur.pop_front();
            }
        }
}

void Autumn_Winter()
{
    int dy, dx;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            deque<int>& cur = trees[i][j];
            for (int iter = 0; iter < cur.size(); ++iter)
                if (cur[iter] % 5 == 0)
                {
                    for (int r = 0; r < 8; ++r)
                    {
                        dy = i + rot[r][0];
                        dx = j + rot[r][1];

                        if (dy < 0 || dy >= N || dx < 0 || dx >= N)
                            continue;

                        trees[dy][dx].push_back(1);
                    }
                }

            board[i][j] += provide[i][j];
        }
}

void MakeAnswer()
{
    int answer = 0;
    for (int i = 0; i < K; ++i)
    {
        Spring_Summer();
        Autumn_Winter();
    }

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            answer += trees[i][j].size();

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    trees.resize(N, deque<deque<int>>(N, deque<int>()));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            cin >> provide[i][j];
            board[i][j] = 5;
        }

    int y, x, age;
    for (int i = 0; i < M; ++i)
    {
        cin >> y >> x >> age;
        trees[y - 1][x - 1].push_back(age);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}