#include <iostream>
#include <queue>

struct state
{
    int y;
    int x;
    int mask;
};

using namespace std;

// 풀이.
// 그래프 탐색 문제에 이것저것 얽혀놓은 문제였다. 문제가 복잡하기에 예전에는 못풀었으나
// 그래도 오늘은 차분히 잘 풀어냈다. 풀이는 다음과 같다.

// 1. '0'에서 좌상우하로 이동한다. 이때 움직이려는 칸이 '#'이거나 열쇠가 없는 상태라면 이동불가다.
// 2. 열쇠의 유무에 의해 중복 방문이 나뉘게 된다. A ~ F까지 최대 6종류인데 이것을 나타내기 위해서 비트마스크를 써야한다.
// 3. 방문시 비트마스크를 이용하여 중복 방문을 비교하기 때문에 방문 이전에 열쇠를 얻게끔 구현해야 한다.

// BFS에 위 조건들을 구현하면 된다. 상술한대로 복잡해보이기 때문에 어려울 것이라는 선입견을 가지고 있었는데
// 집중해서 그런가 의외로 쉽게 풀렸다. 어떤 상황에도 쫄지 말자.

// 자세한 설명은 주석으로 남긴다.

char board[50][50];
int rot[4][2] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };
int N, M;
pair<int, int> from;

// 어떤 좌표 y, x를 방문할수 있는지 확인하는 함수.
bool CanGo(int y, int x, int mask)
{
    // 오직 A ~ F일때만 열쇠를 확인하고 그렇지 않다면 
    // 방문할수 있다. 실제로는 '#'같은 경우는 불가능하지만
    // 함수 호출 이전 if문에서 모두 거르기 때문에 신경쓰지 않는다.
    if ('A' <= board[y][x] && board[y][x] <= 'F')
    {
        int idx = board[y][x] - 'A';
        // 이 부분에서 살짝 실수가 있었다. mask와 (1 << idx)를 비교할때
        // 비교하는 부분이 둘다 1이라면 그 결과값은 1이 아닌 어떠한 정수다.
        // 그런데 비교값이 1인지 확인하고 있었다. 주의하자.
        // 이미 열쇠를 가지고 있다면 방문이 가능하다.
        if (mask & (1 << idx))
            return true;
        else
            return false;
    }
    return true;
}

void BFS()
{
    queue<state> que;
    que.push(state{ from.first, from.second, 0 });
    // 언젠가 다른이의 풀이를 보고 배웠던 비트마스크를 이용한 배열의 구현. 실제로 써보니 굉장히 유용했다.
    bool visit[50][50][1 << 6] = { false, };
    visit[from.first][from.second][0] = true;
    int answer = -1;

    while (!que.empty())
    {
        // 어느순간 큐의 크기를 사용하는 아래 방식이 굳어졌는데 왜이렇게 했는지 생각해보니
        // 이렇게 하지 않으면 이동한 수를 따로 큐안에 저장해두어야 했다. 그러면 큐의 크기도 커지고
        // 넣고 빼는데 복잡해지니 이렇게 굳어졌었다.
        int qsize = que.size();
        ++answer;
        for (int iter = 0; iter < qsize; ++iter)
        {
            int y = que.front().y;
            int x = que.front().x;
            int mask = que.front().mask;
            que.pop();

            // 이 부분에도 살짝 실수가 있었는데 처음에는 입력받을때 '0'인 구역을 from으로 저장한듯
            // '1'인 구역을 to로 저장했었다. 하지만 '1'인 구역이 여러개 존재할수도 있었기에 
            // 이렇게 바꾸어야했다.
            if (board[y][x] == '1')
            {
                cout << answer << '\n';
                return;
            }

            for (int i = 0; i < 4; ++i)
            {
                int ny = y + rot[i][0];
                int nx = x + rot[i][1];

                // 상술한대로 방문시 비트마스크를 비교하는데 새로 이동한 좌표가
                // 열쇠라면 미리 열쇠를 얻은것으로 구현해야한다.
                int nmask = mask;
                if ('a' <= board[ny][nx] && board[ny][nx] <= 'f')
                {
                    int idx = board[ny][nx] - 'a';
                    nmask |= (1 << idx);
                }
                // 좌표값을 벗어났거나, 중복 방문이거나, 벽이거나, 열쇠가 존재하지 않으면
                // 방문할수 없다.
                if (ny < 0 || ny >= N || nx < 0 || nx >= M || visit[ny][nx][nmask] ||
                    board[ny][nx] == '#' || !CanGo(ny, nx, nmask))
                    continue;
                que.push(state{ ny, nx, nmask });
                visit[ny][nx][nmask] = true;
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

    cin >> N >> M;
    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        for (int j = 0; j < M; ++j)
        {
            board[i][j] = str[j];
            if (board[i][j] == '0')
                from = make_pair(i, j);
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}