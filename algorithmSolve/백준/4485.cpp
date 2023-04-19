#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// 최단 거리길래 BFS인줄 알고 풀었다가 한참 해맸다.
// 최단 거리가 아니라 최소 가중치의 합을 구하여야 하기에 다익스트라로 풀어야했다.
// 원리만 알면 구현은 어렵지 않은데 로직은 다음과 같다.

// 1. 0, 0에서 시작하며 최초의 가중치값은 board[0][0]값이다.
// 2. 최초값을 우선순위 큐에 넣어 순회를 하며 좌 우 상 하 4방향으로 나아가며 가중치의 합들을 갱신한다.
// 3. answer[N - 1][N - 1]을 출력한다.

// 자세한 설명은 주석으로 첨부함.

// 각각 각 배열의 가중치값과 최소 가중치의 합에 대한 배열
int board[125][125], answer[125][125];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} }; // 좌 상 우 하.
int N;

// 0, 0 ~ N - 1, N - 1까지의 가중치 합의 최소값을 출력하는 함수.
int DK()
{
    // 모든 좌표까지의 가중치의 합은 987654321을 최초값으로 한다.
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            answer[i][j] = 987654321;

    answer[0][0] = board[0][0];
    priority_queue<pair<int, pair<int, int>>> que;
    que.push(make_pair(-board[0][0], make_pair(0, 0)));

    while (!que.empty())
    {
        int cost = -que.top().first;
        int y = que.top().second.first;
        int x = que.top().second.second;
        que.pop();

        if (answer[y][x] < cost)
            continue;

        // 4방향으로 나아가며 가중치의 합의 최소값을 갱신한다.
        for (int i = 0; i < 4; ++i)
        {
            int dy = y + rot[i][0];
            int dx = x + rot[i][1];

            if (dy < 0 || dy >= N || dx < 0 || dx >= N)
                continue;

            int new_cost = cost + board[dy][dx];

            if (new_cost < answer[dy][dx])
            {
                answer[dy][dx] = new_cost;
                que.push(make_pair(-new_cost, make_pair(dy, dx)));
            }
        }
    }

    return answer[N - 1][N - 1];
}

void MakeAnswer()
{
    int idx = 0;

    while (true)
    {
        cin >> N;

        if (N == 0)
            break;

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                cin >> board[i][j];

        ++idx;
        cout << "Problem " << idx << ": " << DK() << '\n';
    }
}

void Init()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Init();
    MakeAnswer();
    return 0;
}