#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// 한가지 실수로 시간을 꽤나 잡아먹은 문제다. 주어진 배열의 크기가 최대 1000 x 1000이기 때문에 그에 해당하는
// bool 타입 배열로 중복방문을 막아야하는데 지역 배열로는 불가능하다. 이것은 메모리 영역과 연관이 있는데
// 지역 변수는 stack에서, 전역 변수는 data에서 관리한다. 운영체제에 따라서 stack에 메모리 제한이 걸려 있기
// 때문에 최대 100만에 해당하는 배열을 생성할수 없기 때문에 vs에서 제대로 된 값을 출력하지 못했다.
// 따라서 전역 배열로 구현해야 제대로 된 출력을 얻을수 있었다. 하지만 BOJ에는 따로 메모리 제한이 존재하지
// 않기 때문에 그냥 지역 배열로 구현해도 정답을 맞출수 있었다. 참고로 지역 배열은 대략 최대 25만정도를 구현할수
// 있다.

// 자세한 설명은 주석으로 남긴다.

// 좌표와 마법봉의 사용 유무.
struct pos
{
    int y;
    int x;
    bool canuse;
};

int board[1001][1001], rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
int N, M;
pair<int, int> from, to;
bool visit[1001][1001][2] = { false, }; // 상술한대로 vs에서는 전역배열로 해야하지만 BOJ에서는 상관이 없다.

void BFS()
{
    queue<pos> que;
    que.push(pos{ from.first, from.second, true });
    visit[from.first][from.second][1] = true;
    int answer = -1;

    while (!que.empty())
    {
        // 현재 큐에 들어가있는 원소의 수들만 미리 구하여 순회를 함으로써
        // 큐에 이동횟수를 따로 넣지 않아도 된다.
        ++answer;
        int qsize = que.size();
        for (int iter = 0; iter < qsize; ++iter)
        {
            int y = que.front().y;
            int x = que.front().x;
            bool canuse = que.front().canuse;
            que.pop();

            // 목적지에 도달하였는가.
            if (y == to.first && x == to.second)
            {
                cout << answer << '\n';
                return;
            }

            for (int i = 0; i < 4; ++i)
            {
                int ny = y + rot[i][0];
                int nx = x + rot[i][1];

                // 좌표값을 벗어났거나 마법봉을 사용하지 못하는 상태에서 벽을 만난다면 무시한다.
                if (ny <= 0 || ny > N || nx <= 0 || nx > M ||
                    (!canuse && board[ny][nx] == 1))
                    continue;

                // 마법봉의 사용유무가 현재 상황에 영향을 끼치므로 미리 갱신해야한다.
                bool ncanuse = (board[ny][nx] == 1 || !canuse) ? false : true;
                if (visit[ny][nx][ncanuse])
                    continue;
                que.push(pos{ ny, nx, ncanuse });
                visit[ny][nx][ncanuse] = true;
            }
        }
    }
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

    cin >> N >> M >> from.first >> from.second >> to.first >> to.second;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}