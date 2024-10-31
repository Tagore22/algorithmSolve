#include <iostream>
#include <queue>

using namespace std;

// 풀이.
// 문제가 그지 같은 문제였다. 골2에 정답율이 25퍼인 어려운 문제였는데 이런 이유에는 내생각엔 2가지가 있다.
// 첫째는 후술할 생각해내기 까다로웠던 부분이 하나 존재한다. 둘째는 문제의 가독성이 그지같다. 예를 들어
// 어떤 칸으로 이동했는데 이 칸은 g이며, 주위에 쓰레기가 존재한다. 이런 상황에서 나는 두가지 상황에 모두
// 포함되기에 둘다 1씩 증가하는줄 알았는데 그게 아니라 쓰레기칸에 닿은 횟수만 1증가하는 것이었다.
// 그 설명이 없어서 꽤나 헤맸다. 그래도 결국엔 스스로 어렵지 않게 풀어냈다. 다행이다.
// 풀이를 요약하자면 BFS를 순회하는 것이다. 하지만 이동의 최소값을 구하는 기존의 BFS와는 다르게 쓰레기와 닿은
// 횟수를 최소값으로 구해야하기에 중복을 방지하는 것이 어려웠다. 왜냐하면 똑같은 칸에 중복방문해도 현재 pair값에
// 따라 실제로 중복이 아닐수도 있기 때문이었다. 원래 하던대로 bool 타입으로 하니 맞아 떨어지질 않았다.
// 재치있게 떠올린 방법은 pair 타입으로 중복방문을 막는것이었다. 각 칸에 pair값을 두고 그 값보다 크다면 무시하고
// 작다면 큐에 포함시키는 것이다. 이것이 상술한 어려운 이유 첫번째였다. 재치있는 발상이 필요로 했다. 

// 자세한 설명은 주석으로 남긴다.

// P.S 지금 분류를 보니 다익스트라가 끼어있다. 그런 방법도 있을수 있겠다. 애시당초 BFS와 다익스트라 모두
// 최소값을 구하기 위한 방법이니 어느정도는 비슷하기 때문이다.

// 큐에 넣기 위한 사용자 정의 타입.
// 각각 좌표와 pair값.
struct pos
{
    int y;
    int x;
    pair<int, int> cur;
};

char board[50][50];
int N, M;
pair<int, int> from, to;
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };

// 도달하려는 칸의 주위에 쓰레기가 존재하는지 확인하는 함수.
bool CheckSide(int y, int x)
{
    // 다시 주위 4칸을 순회한다.
    for (int i = 0; i < 4; ++i)
    {
        int ny = y + rot[i][0];
        int nx = x + rot[i][1];

        // 역시나 범위값을 벗어난다면 무시한다.
        if (ny < 0 || ny >= N || nx < 0 || nx >= M)
            continue;
        // 주위값이 쓰레기라면 바로 true를 반환하고 탈출한다.
        if (board[ny][nx] == 'g')
            return true;
    }
    // 탈출하지 못했다는 것은 쓰레기를 발견하지 못했다는 것이기에
    // false를 반환하고 탈출한다.
    return false;
}

// 모든 경우를 탐색하는 BFS 함수.
void BFS()
{
    queue<pos> que;
    que.push(pos{ from.first, from.second, make_pair(0, 0) });
    // 상술한 중복방문을 막는 pair 배열. 각칸의 pair값을 두어 그보다 크다면 무시한다.
    pair<int, int> visit[50][50];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            // 매우 큰값으로 초기화해둔다. 대략 2500정도만 넘어도 상관없을듯 싶지만 혹시 몰라 더 큰값으로 해둠.
            visit[i][j] = make_pair(50000, 50000);
    visit[from.first][from.second] = make_pair(0, 0);

    while (!que.empty())
    {
        int y = que.front().y;
        int x = que.front().x;
        pair<int, int> cur = que.front().cur;
        que.pop();

        // 목적지에 도달했다면 더이상 순회할 필요가 없으니 무시한다.
        if (y == to.first && x == to.second)
            continue;

        // 4방향을 모두 순회한다.
        for (int i = 0; i < 4; ++i)
        {
            int ny = y + rot[i][0];
            int nx = x + rot[i][1];

            // 범위값을 벗어났다면 무시한다.
            if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue;

            pair<int, int> next = cur;
            // 만약 도달하는 곳이 쓰레기라면 first값만 증가한다. 이것을 문제에서 제대로 설명해주지 않았다.
            if (board[ny][nx] == 'g')
                next.first = cur.first + 1;
            // 쓰레기가 아니라면 주위에 쓰레기가 있는지 확인한다.
            else
                next.second = board[ny][nx] != 'F' && CheckSide(ny, nx) ? cur.second + 1 : cur.second;

            // 새로 계산한 값 next가 기존값보다 크다면 무시한다.
            if (next >= visit[ny][nx])
                continue;

            // 그렇지 않다면 next를 큐에 넣고 visit값을 갱신한다.
            que.push(pos{ ny, nx, next });
            visit[ny][nx] = next;
        }
    }
    // 최종답 출력.
    cout << visit[to.first][to.second].first << ' ' << visit[to.first][to.second].second << '\n';
}

void MakeAnswer()
{
    BFS();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        for (int j = 0; j < M; ++j)
        {
            board[i][j] = str[j];
            if (board[i][j] == 'S')
                from = make_pair(i, j);
            else if (board[i][j] == 'F')
                to = make_pair(i, j);
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}